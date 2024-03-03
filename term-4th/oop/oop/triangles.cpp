#include "triangles.h"

#include <iostream>
#include <vector>
using namespace std;

float calculateDistance2D(pair<int, int> p1, pair<int, int> p2) {
	int x_diff = p1.first - p2.first;
	int y_diff = p1.second - p2.second;

	return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

bool isTriangles(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	float x = calculateDistance2D(p1, p2), y = calculateDistance2D(p2, p3), z = calculateDistance2D(p1, p3);

	if (x == y + z || y == z + x || z == x + y) {
		cout << "The points are on a straight line." << endl;
		return false;
	}
	if (x > y + z || y > x + z || z > x + y) {
		cout << "Not a triangle." << endl;
		return false;
	}
	else {
		cout << "Is a triangle." << endl;
		return true;
	}
}

void getTriangleType(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	if (!isTriangles(p1, p2, p3)) return;
	float x = calculateDistance2D(p1, p2), y = calculateDistance2D(p2, p3), z = calculateDistance2D(p1, p3);

	if (x == y && y == z) cout << "Is a equilateral triangle." << endl;
	else {
		if (x == y || y == z || x == z) cout << "Is a isosceles triangle." << endl;
		else cout << "Is a normal triangle." << endl;
	}
	return;
}

float getTriangleRadius(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	if (!isTriangles(p1, p2, p3)) return;
	float x = calculateDistance2D(p1, p2), y = calculateDistance2D(p2, p3), z = calculateDistance2D(p1, p3);
	return x + y + z;
}

float getTriangleArea(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	if (!isTriangles(p1, p2, p3)) return;
	return 1/2 * abs(p1.first*(p2.second - p3.second) + p2.first*(p3.second - p1.second) + p3.first*(p1.second - p2.second));
}