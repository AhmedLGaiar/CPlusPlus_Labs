#include <iostream>
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Shape.h"
using namespace std;
	
float sumOfArea(Shape* shapes[], int size) {
	float totalArea = 0;
	for (int i = 0; i < size; i++) {
		totalArea += shapes[i]->area();
	}
	return totalArea;
}

int main()
{
	Rectangle rect(74, 78);
	Square square(60);
	Triangle triangle(20, 16);
	Circle circle(22);

	cout << "Area of Rectangle: " << rect.area() << endl;
	cout << "Area of Square: " << square.area() << endl;
	cout << "Area of Triangle: " << triangle.area() << endl;
	cout << "Area of Circle: " << circle.area() << endl;
	cout << "=================================================" << endl;

	Shape* shapes[] = { &rect, &triangle, &circle };
	int size = sizeof(shapes) / sizeof(shapes[0]);

	cout << "Sum of Areas: " << sumOfArea(shapes, size) << endl;

	system("pause");
}

