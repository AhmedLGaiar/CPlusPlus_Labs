#include "Shape.h"

class Triangle : public Shape
{
public:

	Triangle(float base, float height) : Shape(base, height) {}
	float area() {
		return 0.5 * dim1 * dim2;
	}
};
