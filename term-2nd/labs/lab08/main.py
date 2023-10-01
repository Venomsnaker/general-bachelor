import pandas as pd

def readFile(filePath: str):
    # The Dataset contains 6 sheets
    s = []
    for idx in range(1, 7):
        s.append(pd.read_excel(
            filePath, sheet_name="Sheet{sheet_code}".format(sheet_code=idx)))

    # Divide the DataFrame to each categories
    for df in s:
        if 'DANH SÁCH THÔNG TIN CHI TIẾT TRƯỜNG' in df:
            infos = df
        elif 'Danh sách quận huyện' in df:
            districts = df
        elif 'Tình Trạng Học Sinh' in df:
            conditions = df
        elif 'DANH SÁCH HỌC SINH TRƯỜNG' in df:
            students = df
        elif 'DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG' in df:
            schools = df
        else:
            conditions_code = df
    return {'schools': schools, "districts": districts, "infos": infos,
            "conditions_code": conditions_code, "conditions": conditions, "students": students}


def getDistrictsMap(df: pd.DataFrame):
    # Consider using iterrows because of bad original formatting
    # This solution also takes in the annotate line, very trashy but still not a bug
    districts = df["Unnamed: 1"]
    res = dict()

    for d in districts:
        # nan values are in float for ? reasons
        if type(d) != str:
            continue

        d_list = d.split(" ")
        # Remove prefix
        d_list = [d for d in d_list if d not in ["Quận", "Huyện", "Thị", "xã"]]
        d_name = " ".join(d_list)
        res[d_name] = d
    return res


def addDistrictColumnToInfos(df: pd.DataFrame, districts_map: dict):
    # Set up the new column and some annotations (decorate)
    # The format is seriously dog-shit
    df["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"] = None
    df["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][0] = "NĂM HỌC: 2019-2020"
    df["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][1] = ""
    df["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][2] = "Quận/ Huyện/ Thị xã"

    # Iterrows works nicely here:
    for idx, row in df.iterrows():
        # Ignore all the annotations
        if idx <= 2:
            continue

        # Mapping
        school_name = row[0]
        location = row[1]

        # Handle nan values
        if type(school_name) != str:
            school_name = ""
        if type(location) != str:
            location = ""

        # Check for district names in school_name and location
        res = ""
        for d in districts_map.keys():
            if (d in school_name) or (d in location):
                res = d
                break
        df["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][idx] = districts_map[res] if res != "" else ""
    return


def addDistrictColumnToSchools(schools: pd.DataFrame, infos: pd.DataFrame):
    # Set up the new column and some annotations (decorate)
    schools["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"] = None
    schools["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][0] = "NĂM HỌC: 2019-2020"
    schools["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][1] = ""
    schools["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][2] = "Quận/ Huyện/ Thị xã"

    # schools and infos have the same number of row, indexs are also similar
    df_idx_range = len(schools.index)

    for idx in range(df_idx_range):
        # Ignore all the annotations
        if idx <= 2:
            continue
        schools["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][idx] = infos["DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2"][idx]
    return


def outputInfos(filePath: str, df_dict: dict, sheets_map: dict):
    # For operation 2
    with pd.ExcelWriter(filePath) as writer:
        df_dict["infos"].to_excel(writer, sheet_name="Thông tin trường")

        for df_key in df_dict:
            df = df_dict[df_key]

            if df_key == "infos":
                continue
            else:
                df.to_excel(writer, sheet_name=sheets_map[df_key])
    return


def outputSchools(filePath: str, df: pd.DataFrame):
    df.to_excel(filePath, sheet_name="Sheet1")

def handleOnClassTest():
    # This is just formatting hell
    df_schools = pd.read_excel("Dataset.xlsx", sheet_name="Thông tin trường")
    df_schools_code = pd.read_excel("Dataset.xlsx", sheet_name="DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG")
    df_schools_code = df_schools_code.rename(columns={'DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG': "Code"})
    df_schools = df_schools.join(df_schools_code["Code"])
    df_schools = df_schools.drop(df_schools.columns[0], axis = 1)
    df_schools = df_schools.drop("DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG", axis = 1)
    df_schools =  df_schools.rename(columns={'DANH SÁCH THÔNG TIN CHI TIẾT TRƯỜNG': "Tên Trường", "DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.1": "Category", "DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG.2": "QHTX"})
    df_schools.drop([0,1,2], inplace=True)
    df_schools = df_schools.reset_index()

    df_students = pd.read_excel("Dataset.xlsx", sheet_name="Tình Trạng Học Sinh")
    df_students = df_students.drop(df_students.columns[0], axis = 1)
    df_students = df_students.rename(columns={'Tình Trạng Học Sinh': 'MaHS', 'Unnamed: 1': 'Condition'})
    df_students = df_students.drop([0,1,2])
    df_students = df_students.drop(df_students.columns[0], axis = 1)
    df_students = df_students.reset_index()

    df_students_code = pd.read_excel("Dataset.xlsx", sheet_name="DANH SÁCH HỌC SINH TRƯỜNG")
    df_students_code = df_students_code.drop(df_students_code.columns[0], axis = 1)
    df_students_code = df_students_code.drop([0,1])
    df_students_code = df_students_code.rename(columns={'DANH SÁCH HỌC SINH TRƯỜNG': 'MaHS', 'Unnamed: 1': 'Code'})
    df_students_code = df_students_code.reset_index()

    df_students_code = df_students_code.join(df_students["Condition"])
    df_students_code = df_students_code.drop(df_students_code.columns[0], axis = 1)

    print(df_students_code.head(5))
    print(df_schools.head(5))

    df_schools_bd = df_schools[df_schools["QHTX"] == "Quận Ba Đình"]
    school_code = df_schools_bd["Code"]

    def map_school(code):
        return df_schools.loc[df_schools['Code'] == code, "Tên Trường"].values[0]

    def map_cate(code):
        return df_schools.loc[df_schools['Code'] == code, "Category"].values[0]

    students_selected = df_students_code[df_students_code['Code'].isin(school_code)]
    students_selected =  students_selected[students_selected["Condition"] == "L002"]
    students_selected = students_selected.drop("Condition", axis = 1)
    students_selected["School Name"] = students_selected['Code'].apply(map_school)
    students_selected["Category"] = students_selected['Code'].apply(map_cate)
    students_selected = students_selected.sort_values(by="Category")
    print(students_selected)

# Map of df: schools, districts, infos, conditions_code, conditions, students
sheets_map = {"schools": "DANH SÁCH THÔNG TIN HỒ SƠ TRƯỜNG", "conditions": "Tình Trạng Học Sinh", "conditions_code": "Tình trạng",
              "infos": "DANH SÁCH THÔNG TIN CHI TIẾT TRƯỜNG", "districts": 'Danh sách quận huyện', "students": 'DANH SÁCH HỌC SINH TRƯỜNG'}
df_dict = readFile(filePath="Dataset2.xlsx")
districts_map = getDistrictsMap(df=df_dict["districts"])
addDistrictColumnToInfos(df=df_dict["infos"], districts_map=districts_map)
outputInfos("Dataset.xlsx", df_dict = df_dict, sheets_map=sheets_map)
addDistrictColumnToSchools(schools=df_dict['schools'], infos=df_dict["infos"])
outputSchools("Output.xlsx", df_dict["schools"])
