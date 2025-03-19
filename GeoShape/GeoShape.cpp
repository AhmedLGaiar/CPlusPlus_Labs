#include <iostream>
using namespace std;

class GeoShape
{
protected:
	float dim1;
	float dim2;
public:
	GeoShape(float a, float b)
	{
		dim1 = a;
		dim2 = b;
	}
	void setDim1(float a) { dim1 = a; }
	void setDim2(float a) { dim2 = a; }
	float getDim1() { return dim1; }
	float getDim2() { return dim2; }
	virtual float area() = 0;
};
class Rectangle : public GeoShape
{
public:
	Rectangle(float length, float width) : GeoShape(length, width) {}
	float area() {
		return dim1 * dim2;
	}
};
class Square : protected Rectangle
{
private:
	float side;
public:
	Square(float dim) : Rectangle (dim,dim) , side(dim) {}
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
class Triangle : public GeoShape
{
public:

	Triangle(float base, float height) : GeoShape(base, height) {}
	float area() {
		return 0.5 * dim1 * dim2;
	}
};
class Circle : public GeoShape
{
public:
	Circle(float radius) : GeoShape(radius, radius) {}
	float area() {
		return 3.14 * dim1 * dim1;
	}
};
	
float sumOfArea(GeoShape* shapes[], int size) {
	float totalArea = 0;
	for (int i = 0; i < size; i++) {
		totalArea += shapes[i]->area();
	}
	return totalArea;
}


int main()
{
	Rectangle rect(5, 10);
	Square square(5);
	Triangle triangle(6, 8);
	Circle circle(4);

	cout << "Area of Rectangle: " << rect.area() << endl;
	cout << "Area of Square: " << square.area() << endl;
	cout << "Area of Triangle: " << triangle.area() << endl;
	cout << "Area of Circle: " << circle.area() << endl;
	cout << "=================================================" << endl;

	GeoShape* shapes[] = { &rect, &triangle, &circle };
	int size = sizeof(shapes) / sizeof(shapes[0]);

	cout << "Sum of Areas: " << sumOfArea(shapes, size) << endl;

	system("pause");
}

