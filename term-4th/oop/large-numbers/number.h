#ifndef NUMBER
#define NUMBER

#include <string>
using namespace std;

class Number {
private:
	string num;
public:
	void Init();
	void Init(string);
	void Init(Number);

	void Delete();

	void Input();
	void Output();

	string GetNumber();
	void SetNumber(string);

	string GetSum(string);
	string GetDiff(string);
	string GetProduct(string);
	string GetDivision(string);
};

#endif // !NUMBER



