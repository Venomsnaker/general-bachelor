#ifndef FRACTION
#define FRACTION
	
class Fraction {

private:
	int numerator;
	int denominator;

public:
	void Initialize(int n, int d);
	void Initialize(int n);
	void Initialize();
	void Initialize(Fraction&);

	void Delete();

	void Input();
	void Output();

	int GetNumerator();
	int GetDenominator();

	void SetNumerator(int);
	void SetDenominator(int);

	Fraction GetFractionSum(Fraction& f_new);
	void AddFraction(Fraction& f_new);

	Fraction();
	virtual ~Fraction();
};
#endif