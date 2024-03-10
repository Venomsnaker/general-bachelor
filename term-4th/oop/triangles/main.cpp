#include "triangles.h"
#include <iostream>
using namespace std;

int main()
{
    Triangles t;
    t.SetP1({ 0, 0 });
    t.SetP2({ 1, 0 });
    t.SetP3({ 0, 1 });
    cout << t.GetRadius() << endl;
    cout << t.IsEquilateralTriangle() << endl;
    cout << t.IsIsoscelesTriangle() << endl;
    cout << t.IsRightTriangle() << endl;
}

