#ifndef RECTANGLE
#define RECTANGLE

#include "figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(int, int);
	virtual float Area();
	virtual ~Rectangle();
};

#endif // !RECTANGLE


