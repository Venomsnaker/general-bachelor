#include "file-management.h"
#include "large-number.h"
#include "triangles.h"
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	/*createFile("test1.txt", "Ok");
	printFile("test1.txt");
	renameFile("test1.txt", "test2.txt");
	copyFile("test2.txt", "test.txt");
	deleteFile("test1.txt");
	deleteFile("test2.txt");*/

	/*addLargeNumbers("123", "456");
	diffLargeNumbers("123", "456");
	multiplyLargeNumbers("123", "456");*/

	pair<int, int> p1 = { 1,1 }, p2 = { 2,2 }, p3 = { 3,3 };
	//isTriangles(p1, p2, p3);
	getTriangleType(p1, p2, p3);
}

