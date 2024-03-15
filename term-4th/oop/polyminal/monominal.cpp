#include "monominal.h"
#include <iostream>
#include <math.h>
using namespace std;

Monominal::Monominal() {
	this->coef = 1;
	this->exponent = 1;
}

Monominal::Monominal(float coef, int exponent) {
	this->coef = coef;
	this->exponent = exponent;
}

Monominal::Monominal(float coef) {
	this->coef = coef;
	this->exponent = 1;
}

Monominal::Monominal(int exponent) {
	this->coef = 1;
	this->exponent = exponent;
}

Monominal::~Monominal() {}

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

	res.SetCoef(this->coef * m.GetCoef());
	res.SetExponent(this->exponent + m.GetExponent());
	return res;
}

Monominal Monominal::DivideMonominal(Monominal m) {
	Monominal res;

	res.SetCoef(this->coef / m.GetCoef());
	res.SetExponent(this->exponent - m.GetExponent());
	return res;

}

Polynominal::Polynominal() {
	polyp = {};
}

Polynominal::~Polynominal() {
	cout << "No data allocation." << endl;
}

void Polynominal::Input() {
	static Monominal polyp_new[99];
	int idx = 0;
	bool done = false;
	
	cout << "Input polynominal:" << endl;
	while (!done) {
		Monominal m;
		cout << "Input monominal:" << endl;
		m.Input();
		polyp_new[idx++] = m;
		cout << "Done ? (0/1)" << endl;
		cin >> done;
	}
	this->size = idx;
	this->polyp = polyp_new;
}

void Polynominal::Output() {

}
