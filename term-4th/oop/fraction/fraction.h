#ifndef FRACTION
#define FRACTION

class Fraction {
private:
	int numerator;
	int denominator;

public:
	Fraction();
	Fraction(int, int);
	Fraction(int);
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
	
};

#endif // !FRACTION


