#ifndef  MONOMIAL
#define MONOMIAL

#include <vector>

class Monomial {
private:
	float coef;
	int exponent;

public:
	Monomial();
	Monomial(float coef, int exponent);
	Monomial(float coef);
	Monomial(int exponent);

	~Monomial();

	void Input();
	void Output();

	float GetCoef();
	int GetExponent();

	void SetCoef(float coef);
	void SetExponent(int exponent);

	int CalculateMonomnal(int var);
	Monomial AddMonomial(Monomial m);
	Monomial SubstractMonomial(Monomial m);
	Monomial MultiplyMonomial(Monomial m);
	Monomial DivideMonomial(Monomial m);
};

class Polynomial {
private:
	Monomial* poly;
	int size;

public:
	Polynomial();
	Polynomial(Monomial*, int);
	~Polynomial();

	void Input();
	void Output();

	Monomial *GetPolyp();
	void SetPolyp(Monomial*, int);

	Polynomial AddPolynomial(Polynomial p, int size);
	Polynomial SubstractPolynomial(Polynomial p, int size);
	Polynomial MultiplyPolynomial(Polynomial p);
};

#endif // ! MONOMIAL






