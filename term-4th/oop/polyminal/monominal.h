#ifndef  MONOMINAL
#define MONIMINAL

#include <vector>

class Monominal {
private:
	float coef;
	int exponent;

public:
	Monominal();
	Monominal(float coef, int exponent);
	Monominal(float coef);
	Monominal(int exponent);

	~Monominal();

	void Input();
	void Output();

	float GetCoef();
	int GetExponent();

	void SetCoef(float coef);
	void SetExponent(int exponent);

	int CalculateMonomnal(int var);
	Monominal AddMonominal(Monominal m);
	Monominal SubstractMonominal(Monominal m);
	Monominal MultiplyMonominal(Monominal m);
	Monominal DivideMonominal(Monominal m);
};

class Polynominal {
private:
	Monominal* polyp;
	int size;

public:
	Polynominal();
	~Polynominal();

	void Input();
	void Output();
};

#endif // ! MONOMINAL






