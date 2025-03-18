#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(float length, float width) : Shape(length, width) {}
	float area() {
		return dim1 * dim2;
	}
};