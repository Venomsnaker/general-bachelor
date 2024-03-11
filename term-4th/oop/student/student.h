#ifndef STUDENT
#define STUDENT

#include <string>
#include <vector>
using namespace std;

class Student {
private:
	string code;
	string name;
	float scoreMath;
	float scoreLiterature;
	float scorePhysics;
	float scoreChemistry;
	float scoreFL;
	string address;
	string note;
	float scoreAverage;
	string type;

public:
	void Init();
	void Init(string code, string name, float scoreMath, float scoreLiterature, float scorePhysics, float scoreChemistry, float scoreFL, string address, string note);
	
	string GetCode();
	string GetName();
	float GetMathScore();
	float GetLiteratureScore();
	float GetPhysiscScore();
	float GetChemistryScore();
	float GetFLScore();
	string GetAddress();
	string GetNote();
	float GetAverageScore();
	string GetType();

	void SetCode(string);
	void SetName(string);
	void SetMathScore(float);
	void SetLiteratureScore(float);
	void SetPhysiscScore(float);
	void SetChemistryScore(float);
	void SetFLScore(float);
	void SetAddress(string);
	void SetNote(string);
	void SetAverageScore(float);
	void SetType(string);
};

class StudentDatabase {
private:
	vector<Student> students;

public:
	void Init();
	void Output();

	void AddStudent(Student s);
	void DeleteStudent(string studentCode);

	void SortByCodeAscending();
	void SortByCodeDescending();
	void SortByScoreAscending();
	void SortByScoreDescending();

	void UpdateAverageScore();
	void UpdateType();
};

#endif // !STUDENT





