#ifndef FILE_MANAGEMENT
#define FILE_MANAGEMENT


void createFile(const char* file_name, const char* file_contents);

void printFile(const char* file_path);

void deleteFile(const char* file_path);

void renameFile(const char* file_name, const char* file_name_new);

void copyFile(const char* file_name_source, const char* file_name_dest);

#endif