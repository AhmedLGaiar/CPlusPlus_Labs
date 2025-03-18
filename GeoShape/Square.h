#include "Rectangle.h"

class Square : protected Rectangle
{
private:
	float side;
public:
	Square(float dim) : Rectangle(dim, dim), side(dim) {}
	void setSide(float a)
	{
		side = a;
	}
	float getSide()
	{
		return side;
	}
	float area() override {
		return side * side;
	}
};