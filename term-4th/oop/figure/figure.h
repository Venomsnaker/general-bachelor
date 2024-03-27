#pragma once
#ifndef FIGURE
#define FIGURE

class Figure {
protected:
	int mWidth;
	int mHeight;

public:
	Figure();
	Figure(int, int);

	virtual float CalculateArea() = 0;
	virtual ~Figure();
};
#endif



