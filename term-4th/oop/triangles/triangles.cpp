#include "triangles.h"
#include <iostream>
#include <math.h>
using namespace std;

float Triangles::CalculateDistance(pair<int, int> p1, pair<int, int> p2) {
	int x_diff = p1.first - p2.first;
	int y_diff = p1.second - p2.second;
	return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

void Triangles::Init() {
	p1 = { 0, 0 };
	p2 = { 0, 0 };
	p3 = { 0, 0 };
}

void Triangles::Init(Triangles t) {
	p1 = t.GetP1();
	p2 = t.GetP2();
	p3 = t.GetP3();
}

void Triangles::Init(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

void Triangles::Delete() {
	cout << "No data allocation" << endl;
}

void Triangles::Input() {
	cout << "Input p1:" << endl;
	cout << "x:";
	cin >> p1.first;
	cout << "y:";
	cin >> p1.second;

	cout << "Input p2:" << endl;
	cout << "x:";
	cin >> p2.first;
	cout << "y:";
	cin >> p2.second;

	cout << "Input p3:" << endl;
	cout << "x:";
	cin >> p3.first;
	cout << "y:";
	cin >> p3.second;
}

void Triangles::Output() {
	cout << "P1 - x: " << p1.first << " y: " << p1.second << endl;
	cout << "P2 - x: " << p2.first << " y: " << p2.second << endl;
	cout << "P3 - x: " << p3.first << " y: " << p3.second << endl;
}

pair<int, int> Triangles::GetP1() {
	return p1;
}

pair<int, int> Triangles::GetP2() {
	return p2;
}

pair<int, int> Triangles::GetP3() {
	return p3;
}

void Triangles::SetP1(pair<int, int> p) {
	p1 = p;
}

void Triangles::SetP2(pair<int, int> p) {
	p2 = p;
}

void Triangles::SetP3(pair<int, int> p) {
	p3 = p;
}

bool Triangles::IsTriangle() {
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);

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

bool Triangles::IsRightTriangle() {
	if (!IsTriangle()) return false;
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);
	if ((pow(x, 2) == pow(y, 2) + pow(z, 2)) || (pow(y, 2) == pow(x, 2) + pow(z, 2)) || (pow(z, 2) == pow(y, 2) + pow(x, 2))) return true;
	else return false;
}

bool Triangles::IsIsoscelesTriangle() {
	if (!IsTriangle()) return false;
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);

	if (x == y || y == z || x == z) return true;
	else return false;
}

bool Triangles::IsEquilateralTriangle() {
	if (!IsTriangle()) return false;
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);

	if (x == y && y == z) return true;
	else return false;
}

float Triangles::GetRadius() {
	if (!IsTriangle()) return false;
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);
	return x + y + z;
}

float Triangles::GetArea() {
	if (!IsTriangle()) return false;
	return 1 / 2 * abs(p1.first * (p2.second - p3.second) + p2.first * (p3.second - p1.second) + p3.first * (p1.second - p2.second));
}