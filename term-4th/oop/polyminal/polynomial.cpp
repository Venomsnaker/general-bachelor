#include "polynomial.h"
#include <iostream>
#include <math.h>
using namespace std;

Monomial::Monomial() {
	this->coef = 1;
	this->exponent = 1;
}

Monomial::Monomial(float coef, int exponent) {
	this->coef = coef;
	this->exponent = exponent;
}

Monomial::Monomial(float coef) {
	this->coef = coef;
	this->exponent = 1;
}

Monomial::Monomial(int exponent) {
	this->coef = 1;
	this->exponent = exponent;
}

Monomial::~Monomial() {}

void Monomial::Input() {
	cout << "Input coef: ";
	cin >> this->coef;
	cout << "Input product: ";
	cin >> this->exponent;
}

void Monomial::Output() {
	cout << this->coef << "x^" << this->exponent << endl;
}

float Monomial::GetCoef() {
	return this->coef;
}

int Monomial::GetExponent() {
	return this->exponent;
}

void Monomial::SetCoef(float coef) {
	this->coef = coef;
}

void Monomial::SetExponent(int exponent) {
	this->exponent = exponent;
}

int Monomial::CalculateMonomnal(int var) {
	int res = this->coef * pow(var, this->exponent);
	return res;
}

Monomial Monomial::AddMonomial(Monomial m) {
	Monomial res;

	if (this->exponent != m.GetExponent()) {
		cout << "The monominals don't have the same exponent." << endl;
		return res;
	}
	res.SetCoef(this->coef + m.GetCoef());
	res.SetExponent(m.GetExponent());
	return res;
}

Monomial Monomial::SubstractMonomial(Monomial m) {
	Monomial res;

	if (this->exponent != m.GetExponent()) {
		cout << "The monominals don't have the same exponent." << endl;
		return res;
	}
	res.SetCoef(this->coef - m.GetCoef());
	res.SetExponent(m.GetExponent());
	return res;
}

Monomial Monomial::MultiplyMonomial(Monomial m) {
	Monomial res;

	res.SetCoef(this->coef * m.GetCoef());
	res.SetExponent(this->exponent + m.GetExponent());
	return res;
}

Monomial Monomial::DivideMonomial(Monomial m) {
	Monomial res;

	res.SetCoef(this->coef / m.GetCoef());
	res.SetExponent(this->exponent - m.GetExponent());
	return res;

}

Polynomial::Polynomial() {
	poly = {};
	size = 0;
}

Polynomial::Polynomial(Monomial* new_polyp, int size) {
	poly = new_polyp;
	this->size = size;
}

Polynomial::~Polynomial() {
	cout << "No data allocation." << endl;
}

void Polynomial::Input() {
	int n = 0;
	cout << "Input size: ";
	cin >> n;

	Monomial* polyp_new = new Monomial(n);

	for (int x = 0; x < n; x++) {
		Monomial m;
		cout << "Input monominal " << x << " :" << endl;
		m.Input();
		polyp_new[x] = m;
	}
	this->size = n;
	this->poly = polyp_new;
}

void Polynomial::Output() {
	for (int i = 0; i < size; i++) {
		poly[i].Output();
	}
}

void Polynomial::SetPolyp(Monomial* new_polyp, int size) {
	poly = new_polyp;
	this->size = size;
}

Monomial* Polynomial::GetPolyp() {
	return poly;
}

Polynomial Polynomial::AddPolynomial(Polynomial p, int p_size) {
	Monomial* p_poly = p.GetPolyp();
	int new_size = this->size;

	for (int i = 0; i < p_size; i++) {
		bool isDuplicate = false;

		for (int j = 0; j < this->size; j++) {
			if (poly[j].GetExponent() == p_poly[i].GetExponent()) {
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate) new_size++;
	}

	Monomial* res_poly = new Monomial(new_size);
	int idx = 0;

	for (int i = 0; i < this->size; i++) {
		res_poly[idx++] = poly[i];
	}
	for (int i = 0; i < p_size; i++) {
		bool isDuplicate = false;

		for (int j = 0; j < this->size; j++) {
			if (res_poly[j].GetExponent() == p_poly[i].GetExponent()) {
				isDuplicate = true;
				res_poly[j].SetCoef(res_poly[j].GetCoef() + p_poly[i].GetCoef());
				break;
			}
		}
		if (!isDuplicate) {
			res_poly[idx++] = p_poly[i];
		}
	}

	Polynomial res(res_poly, new_size);
	res.Output();
	return res;
}

Polynomial Polynomial::SubstractPolynomial(Polynomial p, int p_size) {
	Monomial* p_poly = p.GetPolyp();
	int new_size = this->size;

	for (int i = 0; i < p_size; i++) {
		bool isDuplicate = false;

		for (int j = 0; j < this->size; j++) {
			if (poly[j].GetExponent() == p_poly[i].GetExponent()) {
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate) new_size++;
	}

	Monomial* res_poly = new Monomial(new_size);
	int idx = 0;

	for (int i = 0; i < this->size; i++) {
		res_poly[idx++] = poly[i];
	}
	for (int i = 0; i < p_size; i++) {
		bool isDuplicate = false;

		for (int j = 0; j < this->size; j++) {
			if (res_poly[j].GetExponent() == p_poly[i].GetExponent()) {
				isDuplicate = true;
				res_poly[j].SetCoef(res_poly[j].GetCoef() - p_poly[i].GetCoef());
				break;
			}
		}
		if (!isDuplicate) {
			Monomial m_res = p_poly[i];
			m_res.SetCoef(-m_res.GetCoef());
			res_poly[idx++] = m_res;
		}
	}

	Polynomial res(res_poly, new_size);
	res.Output();
	return res;
}
