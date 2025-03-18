#pragma once
#include "graphics.h"
#pragma  comment(lib,"graphics.lib") 

class Shape {
protected:
	int color;
public:
	void setColor(int c)
	{
		color = c;
	}
	void virtual Draw()
	{
	}
};
