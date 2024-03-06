#ifndef MONO
#define MONO

class Mono
{
private:
	int coef;
	int product;

public:
	void Initialize();
	void Initialize(int coef, int product);
	void Initialize(Mono m);

	void Delete();

	void Input();
	void Output();

	int GetCoef();
	int GetProduct();

	void SetCoef();
	void SetProduct();

	Mono();
	virtual ~Mono();
};
#endif

