#ifndef TRIANGLE
#define TRIANGLE

#include <vector>
using namespace std;

class Triangle {
private:
	pair<int, int> p1, p2, p3;

	float CalculateDistance(pair<int, int> p1, pair<int, int> p2);

public:
	void Init(pair<int,  int> p1, pair<int, int> p2, pair<int, int> p3);
	void Init(Triangle t);
	void Init();

	void Delete();

	void Input();
	void Output();

	pair<int, int> GetP1();
	pair<int, int> GetP2();
	pair<int, int> GetP3();

	void SetP1(pair<int, int> p);
	void SetP2(pair<int, int> p);
	void SetP3(pair<int, int> p);

	bool IsTriangle();
	bool IsRightTriangle();
	bool IsIsoscelesTriangle();
	bool IsEquilateralTriangle();
	
	float GetRadius();
	float GetArea();
};

#endif // !TRIANGLES



