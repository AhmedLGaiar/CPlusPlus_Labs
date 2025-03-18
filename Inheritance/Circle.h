#pragma once
#include "graphics.h"
#include "Point.h"

class Circle : public Shape {
protected:
	int radius;
	Point center;
public:
	int color;
	Circle(Point c, int r, int col) : radius(r), center(c), color(col) { }

	void Draw()  {
		setcolor(color);
		circle(center.x, center.y, radius);
	}
};