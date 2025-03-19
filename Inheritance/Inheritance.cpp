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

    Rect rect2(Point(200, 200), Point(400, 300), BLUE);
    rect2.Draw();

    Line line(Point(200, 200), Point(450, 250), YELLOW);
    line.Draw();

    Circle circle1(Point(100, 100), 50, GREEN);

    circle1.Draw();
	getch();
	closegraph();
	return 0;
}

