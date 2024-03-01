#include "file-management.h"
#include <cstring>

int main()
{
	createFile("test1.txt", "Ok");
	printFile("test1.txt");
	renameFile("test1.txt", "test2.txt");
	copyFile("test2.txt", "test.txt");
	deleteFile("test1.txt");
	deleteFile("test2.txt");
}

