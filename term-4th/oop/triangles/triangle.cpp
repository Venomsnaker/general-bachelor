#include "triangle.h"
#include <iostream>
#include <math.h>
using namespace std;

#define EPSILON 1e-6

float Triangle::CalculateDistance(pair<int, int> p1, pair<int, int> p2) {
	int x_diff = p1.first - p2.first;
	int y_diff = p1.second - p2.second;
	return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

void Triangle::Init() {
	p1 = { 0, 0 };
	p2 = { 0, 0 };
	p3 = { 0, 0 };
}

void Triangle::Init(Triangle t) {
	p1 = t.GetP1();
	p2 = t.GetP2();
	p3 = t.GetP3();
}

void Triangle::Init(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

void Triangle::Delete() {
	cout << "No data allocation" << endl;
}

void Triangle::Input() {
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

void Triangle::Output() {
	cout << "P1 - x: " << p1.first << " y: " << p1.second << endl;
	cout << "P2 - x: " << p2.first << " y: " << p2.second << endl;
	cout << "P3 - x: " << p3.first << " y: " << p3.second << endl;
}

pair<int, int> Triangle::GetP1() {
	return p1;
}

pair<int, int> Triangle::GetP2() {
	return p2;
}

pair<int, int> Triangle::GetP3() {
	return p3;
}

void Triangle::SetP1(pair<int, int> p) {
	p1 = p;
}

void Triangle::SetP2(pair<int, int> p) {
	p2 = p;
}

void Triangle::SetP3(pair<int, int> p) {
	p3 = p;
}

bool Triangle::IsTriangle() {
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);

	if (abs(x - (y + z)) < EPSILON || abs(y - (x + z)) < EPSILON || abs(z - (y + x)) < EPSILON) {
		return false;
	}
	if (x > y + z || y > x + z || z > x + y) {
		return false;
	}
	else {
		return true;
	}
}

bool Triangle::IsRightTriangle() {
	if (!IsTriangle()) return false;
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);
	float x_pow = pow(x, 2), y_pow = pow(y, 2), z_pow = pow(z, 2);

	if ( (abs(x_pow - (y_pow + z_pow)) < EPSILON) || (abs(y_pow - (x_pow + z_pow)) < EPSILON) || (abs(z_pow - (y_pow + x_pow)) < EPSILON) ) return true;
	else return false;
}

bool Triangle::IsIsoscelesTriangle() {
	if (!IsTriangle()) return false;
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);

	if (abs(x - y) < EPSILON || abs(z - y) < EPSILON || abs(x - z) < EPSILON) return true;
	else return false;
}

bool Triangle::IsEquilateralTriangle() {
	if (!IsTriangle()) return false;
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);

	if (abs(x - y) < EPSILON && abs(z - y) < EPSILON) return true;
	else return false;
}

float Triangle::GetRadius() {
	if (!IsTriangle()) return false;
	float x = CalculateDistance(p1, p2), y = CalculateDistance(p2, p3), z = CalculateDistance(p1, p3);
	return x + y + z;
}

float Triangle::GetArea() {
	if (!IsTriangle()) return false;
	return 1 / 2 * abs(p1.first * (p2.second - p3.second) + p2.first * (p3.second - p1.second) + p3.first * (p1.second - p2.second));
}