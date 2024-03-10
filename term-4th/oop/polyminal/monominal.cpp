#include "monominal.h"
#include <iostream>
#include <math.h>
using namespace std;

void Monominal::Initialize() {
	this->coef = 1;
	this->exponent = 1;
}

void Monominal::Initialize(float coef, int exponent) {
	this->coef = coef;
	this->exponent = exponent;
}

void Monominal::Initialize(float coef) {
	this->coef = coef;
	this->exponent = 1;
}

void Monominal::Initialize(int exponent) {
	this->coef = 1;
	this->exponent = exponent;
}

void Monominal::Initialize(Monominal m) {
	this->coef = m.GetCoef();
	this->exponent = m.GetExponent();
}

void Monominal::Delete() {
	cout << "No data allocation." << endl;
}

void Monominal::Input() {
	cout << "Input coef: ";
	cin >> this->coef;
	cout << "Input product: ";
	cin >> this->exponent;
}

void Monominal::Output() {
	cout << this->coef << "x^" << this->exponent << endl;
}

float Monominal::GetCoef() {
	return this->coef;
}

int Monominal::GetExponent() {
	return this->exponent;
}

void Monominal::SetCoef(float coef) {
	this->coef = coef;
}

void Monominal::SetExponent(int exponent) {
	this->exponent = exponent;
}

int Monominal::CalculateMonomnal(int var) {
	int res = this->coef * pow(var, this->exponent);
	return res;
}

Monominal Monominal::AddMonominal(Monominal m) {
	Monominal res;
	res.Initialize();

	if (this->exponent != m.GetExponent()) {
		cout << "The monominals don't have the same exponent." << endl;
		return res;
	}
	res.SetCoef(this->coef + m.GetCoef());
	res.SetExponent(m.GetExponent());
	return res;
}

Monominal Monominal::SubstractMonominal(Monominal m) {
	Monominal res;
	res.Initialize();

	if (this->exponent != m.GetExponent()) {
		cout << "The monominals don't have the same exponent." << endl;
		return res;
	}
	res.SetCoef(this->coef - m.GetCoef());
	res.SetExponent(m.GetExponent());
	return res;
}

Monominal Monominal::MultiplyMonominal(Monominal m) {
	Monominal res;
	res.Initialize();

	res.SetCoef(this->coef * m.GetCoef());
	res.SetExponent(this->exponent + m.GetExponent());
	return res;
}

Monominal Monominal::DivideMonominal(Monominal m) {
	Monominal res;
	res.Initialize();

	res.SetCoef(this->coef / m.GetCoef());
	res.SetExponent(this->exponent - m.GetExponent());
	return res;

}