#ifndef  MONOMINAL
#define MONIMINAL

#include <vector>

class Monominal {
private:
	float coef;
	int exponent;

public:
	void Initialize();
	void Initialize(float coef, int exponent);
	void Initialize(float coef);
	void Initialize(int exponent);
	void Initialize(Monominal);
	
	void Delete();

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

#endif // ! MONOMINAL






