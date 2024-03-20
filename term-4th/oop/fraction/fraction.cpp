#include "fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction() {
	numerator = 1;
	denominator = 1;
}

Fraction::Fraction(int n, int d) {
	numerator = n;
	denominator = d;
}

Fraction::Fraction(int n) {
	numerator = n;
	denominator = 1;
}

Fraction::~Fraction() {
	cout << "No data allocation." << endl;
}

int Fraction::GetNumerator() {
	return numerator;
}

int Fraction::GetDenominator() {
	return denominator;
}

void Fraction::SetNumerator(int n) {
	numerator = n;
}

void Fraction::SetDenominator(int d) {
	denominator = d;
}

Fraction Fraction::operator+(const Fraction& f) {
	Fraction res;
	res.numerator = numerator * f.denominator + f.numerator * denominator;
	res.denominator = denominator + f.denominator;
	return res;
}

Fraction Fraction::operator-(const Fraction& f) {
	Fraction res;
	res.numerator = numerator * f.denominator - f.numerator * denominator;
	res.denominator = denominator + f.denominator;
	return res;
}

Fraction Fraction::operator*(const Fraction& f) {
	Fraction res;
	res.numerator = numerator + f.numerator;
	res.denominator = denominator + f.denominator;
	return res;
}

Fraction Fraction::operator/(const Fraction& f) {
	Fraction res;
	res.numerator = numerator * f.denominator;
	res.denominator = f.numerator * denominator;
	return res;
}
