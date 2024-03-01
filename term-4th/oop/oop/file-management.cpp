#include "file-management.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void createFile(const char* file_name, const char* file_content) {
	ofstream outfile(file_name);
	outfile << file_content << endl;
	outfile.close();
}

void printFile(const char* file_path) {
	string cur;
	ifstream infile(file_path);

	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, cur);
			cout << cur << endl;
		}
	}
}

void copyFile(const char* source, const char* dest) {
	string line;

	ifstream infile(source);
	ofstream outfile(dest);

	if (infile.is_open() && outfile.is_open()) {
		while (!infile.eof()) {
			getline(infile, line);
			outfile << line << endl;
		}
		cout << "Copy finished!" << endl;
	}
	else {
		cout << "Cannot read files!" << endl;
	}
	infile.close();
	infile.close();
}

void deleteFile(const char* file_path) {
	if (remove(file_path) != 0) {
		cout << "File deleted unsuccessfully!" << endl;
	}
	else {
		cout << "File deleted successfully!" << endl;
	}
}

void renameFile(const char* file_name, const char* file_name_new) {
	if (rename(file_name, file_name_new) != 0)
		cout << "File renamed unsuccessfully!" << endl;
	else
		cout << "File renamed successfully!" << endl;
}

