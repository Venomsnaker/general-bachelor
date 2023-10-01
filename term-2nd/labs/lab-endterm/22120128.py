import pandas as pd

def read_file(filePath):
    df_schools_code = pd.read_excel(filePath, sheet_name="Tên trường", skiprows=2)
    df_schools = pd.read_excel(filePath, sheet_name="Trường", skiprows= 2)
    df_birth_day = pd.read_excel(filePath, sheet_name="Ngày sinh")
    df_address = pd.read_excel(filePath, sheet_name="Địa chỉ")
    return df_schools_code, df_schools, df_birth_day, df_address

def process_df_schools(df_schools):
    df_schools.drop("Loại Trường", axis = 1, inplace=True)
    df_schools.dropna(inplace=True)
    df_schools["Quận/Huyện"] = None
    for idx, row in df_schools.iterrows():
        address = row["Phòng GD&ĐT"]
        if type(address) is not str:
            continue
        district = address.replace("Phòng GDĐT ", "")
        df_schools.loc[idx, "Quận/Huyện"] = district
    return df_schools

def various_task(df_schools, df_birth_day, df_address):
    students_by_districts = df_address.groupby("Địa chỉ").count()["MSHS"]
    schools_by_districts = df_schools.groupby("Quận/Huyện").value_counts()
    schools_by_districts = pd.DataFrame(schools_by_districts)
    schools_by_districts.drop("count", axis = 1, inplace=True)
    schools_by_category = df_schools.groupby(["Loại hình", "Quận/Huyện"]).count()["Mã trường"]

    df_combine = df_address.join(df_birth_day["Ngày sinh"])
    for idx, row in df_combine.iterrows():
        date = row["Ngày sinh"]
        if type(date) is not str:
            continue
        year = date[len(date) - 4:len(date)]
        df_combine.loc[idx, "Ngày sinh"] = int(year)
    df_combine = df_combine[(df_combine["Ngày sinh"] >= (2023 - 18)) & (df_combine["Ngày sinh"] <= (2023 - 6))]
    students_by_ages = df_combine.groupby("Địa chỉ").count()["MSHS"]
    return students_by_districts, schools_by_districts, schools_by_category, students_by_ages

def writeToExcel(df_schools, t1, t2, t3, t4):
    with pd.ExcelWriter("output.xlsx") as writer:
        df_schools.to_excel(writer, sheet_name="Câu 1")
        t1.to_excel(writer, sheet_name="Câu 2a")
        t2.to_excel(writer, sheet_name="Câu 2b")
        t3.to_excel(writer, sheet_name="Câu 2c")
        t4.to_excel(writer, sheet_name="Câu 2d")

def search(df_schools, df_schools_code, df_schools_new):
    df_schools_code.dropna(inplace = True)
    df_schools.dropna(inplace=True)
    df_schools = df_schools.join(df_schools_code["Tên trường"])

    search_input = input("Input the school name here: ")
    print(df_schools[df_schools["Tên trường"] == search_input])

    search_input = input("Input the district name here: ")
    print(df_schools_new[df_schools_new["Quận/Huyện"] == search_input])

df_schools_code, df_schools, df_birth_day, df_address = read_file("Data.xlsx")
df_schools_original = df_schools
df_schools = process_df_schools(df_schools)
t1, t2, t3, t4 = various_task(df_schools, df_birth_day, df_address)
writeToExcel(df_schools, t1, t2, t3, t4)
search(df_schools_original, df_schools_code, df_schools)
