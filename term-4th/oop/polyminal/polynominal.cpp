#include "polynominal.h"
#include "monominal.h"
#include <iostream>
#include <vector>
using namespace std;

void Polynominal::Initialize() {
	this->polyp = {};
}

void Polynominal::Initialize(Polynominal p) {
	this->polyp = {};
	for (auto m : p.GetPolyminal()) {
		this->polyp.push_back(m);
	}
}

void Polynominal::Delete() {
	cout << "No data allocation." << endl;
}

void Polynominal::Input() {
	bool isDone = false;

	while (!isDone) {
		Monominal m;
		m.Initialize();
		m.Input();

		(this->polyp).push_back(m);
		cout << "Do you wish to continue 0/1:";
		cin >> isDone;
	}
}