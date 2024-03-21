#ifndef FRACTION
#define FRACTION

#include <iostream>
using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

public:
	Fraction();
	Fraction(int, int);
	Fraction(int);
	Fraction(const Fraction&);
	~Fraction();

	int GetNumerator();
	int GetDenominator();

	void SetNumerator(int);
	void SetDenominator(int);

	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	Fraction& operator++();
	Fraction operator++(int);

	friend ostream& operator<<(ostream& os, Fraction& f);
};

#endif // !FRACTION


