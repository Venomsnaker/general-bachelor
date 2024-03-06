#include "fraction.h"

#include <iostream>
using namespace std;

Fraction::Fraction() {

}

Fraction::~Fraction() {

}

void Fraction::Initialize(int n, int d) {
	numerator = n;
	if (d != 0) denominator = d;
	else denominator = 1;
}

void Fraction::Initialize(int n) {
	numerator = n;
	denominator = 1;
}

void Fraction::Initialize() {
	numerator = 0;
	denominator = 1;
}

void Fraction::Initialize(Fraction& f) {
	numerator = f.numerator;
	denominator = f.denominator;
}

void Fraction::Delete() {}

void Fraction::Input() {
	cout << "Input numerator: ";
	cin >> numerator;

	do {
		cout << "Input denominator: ";
		cin >> denominator;
	} while (denominator == 0);
}

void Fraction::Output() {
	cout << numerator << " / " << denominator << endl;
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

Fraction Fraction::GetFractionSum(Fraction& f) {
	Fraction res;
	res.SetNumerator(numerator * f.GetDenominator() + denominator * f.GetNumerator());
	res.SetDenominator(denominator * f.GetDenominator());
	return res;
}