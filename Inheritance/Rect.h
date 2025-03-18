#pragma once
#include "graphics.h"
#pragma  comment(lib,"graphics.lib") 

class Rect : public Shape {
protected:
	Point UL;
    Point LR;
public:
    int color;
    Rect(Point upperLeft, Point lowerRight, int col) : UL(upperLeft), LR(lowerRight), color(col) {}

    void Draw()  {
        setcolor(color); 
        line(UL.x, UL.y, LR.x, UL.y); 
        line(UL.x, UL.y, UL.x, LR.y); 
        line(UL.x, LR.y, LR.x, LR.y); 
        line(LR.x, UL.y, LR.x, LR.y); 
    }
};
