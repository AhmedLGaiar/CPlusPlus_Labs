#pragma once
#include "graphics.h"
#include "Shape.h"
#include "Point.h"
#pragma  comment(lib,"graphics.lib") 


class Line: public Shape
{
public:
	int color;
	Point start;
	Point end;
	Line(Point p1, Point p2, int col) : start(p1), end(p2), color(col) { }

	void Draw()
	{
		setcolor(color);
		line(start.x, start.y, end.x, end.y);
	}
};
