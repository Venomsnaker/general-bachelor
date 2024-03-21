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

Fraction::Fraction(const Fraction& f) {
	numerator = f.numerator;
	denominator = f.denominator;
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

Fraction& Fraction::operator++() {
	numerator += denominator;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction res = *this;
	numerator += denominator;
	return numerator;
}

ostream& operator<<(ostream& os, Fraction& f) {
	os << f.GetNumerator() << "/" << f.GetDenominator() << endl;
	return os;
}


