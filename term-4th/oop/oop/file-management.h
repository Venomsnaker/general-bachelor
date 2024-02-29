#ifndef FILE_MANAGEMENT
#define FILE_MANAGEMENT

#include<string>
using namespace std;

void createFile(string file_name, string file_contents);

void printFile(string file_path);

void deleteFile(string file_name);

void changeFileName(string file_name, string file_name_new);

void copyFile(string file_name_source, string file_name_dest);

#endif