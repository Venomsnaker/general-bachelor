#include <iostream>
#include "monominal.h"
using namespace std;

int main() {
	Monominal m1, m2, m3, m4;
	m1.Initialize(2, 3);
	m2.Initialize(3, 3);
	m3.Initialize(4, 2);
	m1.Output();
	m2.Output();
	m3.Output();

	cout << endl;
	m4.Initialize();

	m4 = m1.AddMonominal(m2);
	cout << "Add" << endl;
	m4.Output();

	m4 = m1.SubstractMonominal(m2);
	cout << "Subtract" << endl;
	m4.Output();

	m4 = m1.MultiplyMonominal(m3);
	cout << "Multiply" << endl;
	m4.Output();

	m4 = m2.DivideMonominal(m3);
	cout << "Divide" << endl;
	m4.Output();
	return 0;
}