
class Shape
{
protected:
	float dim1;
	float dim2;
public:
	Shape(float a, float b)
	{
		dim1 = a;
		dim2 = b;
	}
	void setDim1(float a) { dim1 = a; }
	void setDim2(float a) { dim2 = a; }
	float getDim1() { return dim1; }
	float getDim2() { return dim2; }
	virtual float area() = 0;
	virtual ~Shape() {}; 
};