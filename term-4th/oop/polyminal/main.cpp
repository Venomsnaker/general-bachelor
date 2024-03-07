#include <iostream>
#include "monominal.h"
using namespace std;

int main() {
	Monominal m1, m2, m3;
	m1.Initialize(2, 2);
	m1.Output();
	m2.Initialize();
	m2.Input();
	m2.Output();
	m3 = m1.AddMonominal(m2);
	m3.Output();
	return 0;

}