#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(float radius) : Shape(radius, radius) {}
	float area() {
		return 3.14 * dim1 * dim1;
	}
};

#endif
