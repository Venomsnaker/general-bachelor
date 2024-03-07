#ifndef POLYNOMINAL
#define POLYNOMINAL

#include <vector>
#include "monominal.h"
using namespace std;

class Polynominal
{
private:
	vector<Monominal> polyp;

public:
	void Initialize();
	void Initialize(Polynominal);

	void Delete();

	void Input();
	void Output();
	void WriteToFile();

	vector<Monominal> GetPolyminal();
	void SetPolyminal(vector<int> Polyminal);
};

#endif // !POLYNOMINAL



