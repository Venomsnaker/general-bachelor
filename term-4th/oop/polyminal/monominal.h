#ifndef  MONOMINAL
#define MONIMINAL

class Monominal {
private:
	float coef;
	int power;

public:
	void Initialize();
	void Initialize(float coef, int power);
	void Initialize(float coef);
	void Initialize(int power);
	void Initialize(Monominal);
	
	void Delete();

	void Input();
	void Output();
	void WriteToFile();

	float GetCoef();
	int GetPower();

	void SetCoef(float coef);
	void SetPower(int power);

	int CalculateMonomnal(int var);
	Monominal AddMonominal(Monominal m);
	Monominal SubstractMonominal(Monominal m);
	Monominal MultiplyMonominal(Monominal m);
	Monominal DivideMonominal(Monominal m);
};

#endif // ! MONOMINAL






