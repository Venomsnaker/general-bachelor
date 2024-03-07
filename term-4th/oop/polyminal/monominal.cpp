#include "monominal.h"
#include <iostream>
#include <math.h>
using namespace std;

void Monominal::Initialize() {
	this->coef = 1;
	this->power = 1;
}

void Monominal::Initialize(float coef, int power) {
	this->coef = coef;
	this->power = power;
}

void Monominal::Initialize(float coef) {
	this->coef = coef;
	this->power = 1;
}

void Monominal::Initialize(int power) {
	this->coef = 1;
	this->power = power;
}

void Monominal::Initialize(Monominal m) {
	this->coef = m.GetCoef();
	this->power = m.GetPower();
}

void Monominal::Delete() {
	cout << "No data allocation." << endl;
}

void Monominal::Input() {
	cout << "Input coef: ";
	cin >> this->coef;
	cout << "Input product: ";
	cin >> this->power;
}

void Monominal::Output() {
	cout << this->coef << "x^" << this->power << endl;
}

float Monominal::GetCoef() {
	return this->coef;
}

int Monominal::GetPower() {
	return this->power;
}

void Monominal::SetCoef(float coef) {
	this->coef = coef;
}

void Monominal::SetPower(int power) {
	this->power = power;
}

int Monominal::CalculateMonomnal(int var) {
	int res = this->coef * pow(var, this->power);
	return res;
}

Monominal Monominal::AddMonominal(Monominal m) {
	Monominal res;
	res.Initialize();

	if (this->power != m.GetPower()) {
		cout << "The monominals don't have the same power." << endl;
		return res;
	}
	res.SetCoef(this->coef + m.GetCoef());
	res.SetPower(m.GetPower());
	return res;
}

Monominal Monominal::SubstractMonominal(Monominal m) {
	Monominal res;
	res.Initialize();

	if (this->power != m.GetPower()) {
		cout << "The monominals don't have the same power." << endl;
		return res;
	}
	res.SetCoef(this->coef - m.GetCoef());
	res.SetPower(m.GetPower());
	return res;
}

Monominal Monominal::MultiplyMonominal(Monominal m) {
	Monominal res;
	res.Initialize();

	res.SetCoef(this->coef * m.GetCoef());
	res.SetPower(this->power + m.GetPower());
	return res;
}

Monominal Monominal::DivideMonominal(Monominal m) {
	Monominal res;
	res.Initialize();

	res.SetCoef(this->coef / m.GetCoef());
	res.SetPower(this->power - m.GetPower());
	return res;

}