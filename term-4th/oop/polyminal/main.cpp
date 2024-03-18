#include <iostream>
#include "polynomial.h"
using namespace std;

int main() {
	Monomial m1(2, 3), m2 (3, 2), m3 (4, 1);
	Monomial m4(3, 3), m5(2, 1), m6(5, 4);
	/*m1.Output();
	m2.Output();
	m3.Output();
	cout << endl;

	m4 = m1.AddMonomial(m2);
	cout << "Add" << endl;
	m4.Output();

	m4 = m1.SubstractMonomial(m2);
	cout << "Subtract" << endl;
	m4.Output();

	m4 = m1.MultiplyMonomial(m3);
	cout << "Multiply" << endl;
	m4.Output();

	m4 = m2.DivideMonomial(m3);
	cout << "Divide" << endl;
	m4.Output();*/

	Monomial* ms1 = new Monomial(3);
	ms1[0] = m1;
	ms1[1] = m2;
	ms1[2] = m3;

	Monomial* ms2 = new Monomial(3);
	ms2[0] = m4;
	ms2[1] = m5;
	ms2[2] = m6;
	Polynomial p1(ms1, 3), p2(ms2, 3);
	p1.Output();
	cout << endl;
	p2.Output();
	cout << endl;
	p1.AddPolynomial(p2, 3);
	p1.SubstractPolynomial(p2, 3);
	return 0;
}