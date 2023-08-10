/*
Author: iftee
Date modified: 5-5-2023
IDE: VSCode
compiler: MinGW-gcc
*/

#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
	double width,height;
public:
	Rectangle()
	{
		width=0;height=0;
	}
	Rectangle(double w, double h)
	{
		width=w;height=h;
	}
	Rectangle(Rectangle &r)
	{
		this->width=r.width;
		this->height=r.height;
	}
	void setWidth(double w){width=w;}
	void setHeight(double h){height=h;}
	double getArea()
	{
		return width*height;
	}
	double checkPerimeter()
	{
		return 2*(height+width);
	}
	bool isSquare()
	{
		return (height==width)? true:false; 
	}
};

int main()
{
	Rectangle r1(5,10);
	Rectangle r2(r1);
	r2.setWidth(7);
	cout << "Area of Rectangle 1: " << r1.getArea() << endl;
	cout << "Area of Rectangle 2: " << r2.getArea() << endl;
	(r1.isSquare())? cout << "R1 is square\n": cout << "R1 isnt square\n";
	Rectangle r3(r1);
	r3.setHeight(5);
	cout << "Area of Rectangle 3: " << r3.getArea() << endl;
	(r3.isSquare())? cout << "R3 is square\n": cout << "R3 isnt square\n";

	return 0;
}