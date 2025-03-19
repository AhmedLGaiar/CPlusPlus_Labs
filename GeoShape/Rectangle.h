#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(float length, float width) : Shape(length, width) {}
	float area() {
		return dim1 * dim2;
	}
};

#endif