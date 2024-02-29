#include "file-management.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

void createFile(string file_name, string file_content) {
	ofstream outfile(file_name + ".txt");
	outfile << file_content << endl;
	outfile.close();
}

void printFile(string file_path) {
	string cur;
	ifstream infile(file_path);

	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, cur);
			cout << cur << endl;
		}
	}
}

void deleteFile(string file_path) {
	remove(file_path);
}

