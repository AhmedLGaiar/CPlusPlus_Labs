#include "graphics.h"
#pragma  comment(lib,"graphics.lib") 
#include "Line.h"
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Rect.h"
#include <iostream>
using namespace std;

int main()
{
	initwindow(500, 500);
	
	Rect rect1(Point(50, 50), Point(150, 150), RED);
	Rect rect2(Point(200, 200), Point(400, 300), BLUE);
	rect1.Draw();
	rect2.Draw();
	Circle circle1(Point(100, 100), 50, GREEN);
	circle1.Draw();

	getch();
	closegraph();
	return 0;
}

