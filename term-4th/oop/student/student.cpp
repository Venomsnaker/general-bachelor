#include "student.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Student::Init() {
	code = name = address = note = type = "";
	scoreMath = scoreLiterature = scorePhysics = scoreChemistry = scoreFL = scoreAverage = 0;
}

void Student::Init(string code, string name, float scoreMath, float scoreLiterature, float scorePhysics, float scoreChemistry, float scoreFL, string address, string note) {
	this->code = code;
	this->name = name;
	this->scoreMath = scoreMath;
	this->scoreLiterature = scoreLiterature;
	this->scorePhysics = scorePhysics;
	this->scoreChemistry = scoreChemistry;
	this->scoreFL = scoreFL;
	this->address = address;
	this->note = note;
}

string Student::GetCode() {
    return code;
}

string Student::GetName() {
	return name;
}

string Student::GetAddress() {
	return address;
}

string Student::GetNote() {
	return note;
}

string Student::GetType() {
	return type;
}

float Student::GetMathScore() {
	return scoreMath;
}

float Student::GetLiteratureScore() {
	return scoreLiterature;
}

float Student::GetPhysiscScore() {
	return scorePhysics;
}

float Student::GetChemistryScore() {
	return scoreChemistry;
}

float Student::GetFLScore() {
	return scoreFL;
}

float Student::GetAverageScore() {
	return scoreAverage;
}

void Student::SetCode(string c) {
	code = c;
}

void Student::SetName(string n) {
	name = n;
}

void Student::SetMathScore(float s) {
	scoreMath = s;
}

void Student::SetLiteratureScore(float s) {
	scoreLiterature = s;
}

void Student::SetPhysiscScore(float s) {
	scorePhysics = s;
}

void Student::SetChemistryScore(float s) {
	scoreChemistry = s;
}

void Student::SetFLScore(float s) {
	scoreFL = s;
}

void Student::SetAddress(string a) {
	address = a;
}

void Student::SetNote(string n) {
	note = n;
}

void Student::SetAverageScore(float s) {
	scoreAverage = s;
}

void Student::SetType(string t) {
	type = t;
}

void StudentDatabase::Init() {
	students = {};
}

void StudentDatabase::AddStudent(Student s) {
	students.push_back(s);
}

void StudentDatabase::DeleteStudent(string studentCode) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].GetCode() == studentCode) {
			students.erase(students.begin() + i);
			return;
		}
	}
	cout << "No student with matching code in the database" << endl;
	return;
}

void StudentDatabase::Output() {
	for (auto s : students) {
		cout << s.GetCode() << " " << s.GetName() << " " << s.GetAverageScore() << endl;
	}
}

void StudentDatabase::SortByCodeAscending() {
	for (int i = 0; i < students.size(); i++) {
		int idx = i;

		for (int j = i + 1; j < students.size(); j++) {
			if (students[idx].GetCode() > students[j].GetCode()) {
				idx = j;
			}
		}

		if (idx != i) {
			swap(students[i], students[idx]);
		}
	}
}

void StudentDatabase::SortByCodeDescending() {
	for (int i = 0; i < students.size(); i++) {
		int idx = i;

		for (int j = i + 1; j < students.size(); j++) {
			if (students[idx].GetCode() < students[j].GetCode()) {
				idx = j;
			}
		}

		if (idx != i) {
			swap(students[i], students[idx]);
		}
	}
}

void StudentDatabase::SortByScoreAscending() {
	for (int i = 0; i < students.size(); i++) {
		int idx = i;

		for (int j = i + 1; j < students.size(); j++) {
			if (students[idx].GetAverageScore() > students[j].GetAverageScore()) {
				idx = j;
			}
		}

		if (idx != i) {
			swap(students[i], students[idx]);
		}
	}
}

void StudentDatabase::SortByScoreDescending() {
	for (int i = 0; i < students.size(); i++) {
		int idx = i;

		for (int j = i + 1; j < students.size(); j++) {
			if (students[idx].GetAverageScore() < students[j].GetAverageScore()) {
				idx = j;
			}
		}

		if (idx != i) {
			swap(students[i], students[idx]);
		}
	}
}

void StudentDatabase::UpdateAverageScore() {
	for (int i = 0; i < students.size(); i++) {
		float cur = students[i].GetMathScore() + students[i].GetLiteratureScore() + students[i].GetPhysiscScore()
			+ students[i].GetChemistryScore() + students[i].GetFLScore();
		cur = cur / 5;
		students[i].SetAverageScore(cur);
	}
}
