// Name:
//
// Problem 1: Class RectangularSolid	 - 50-Points 
// 
// Notes: A Rectangular Solid can be defined as 3 unique sets of points in 
//	  the x, y, and z planes,  
//	  The height (H) of the cube is the absolute value of y2 - y1
//        The width (W) of the cube is the absolute value of z2 - z1
//	  The length (L) of the cube is the absolute value of x2 - x1
//	  Surface Area of a cube is 2LH + 2HW + 2LW
//	  Volume of a cube is L X W X H
//	  A Rectangular Solid is a cube with equal W, L, H

#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>

using std::setw;
using std::setprecision;
using std::showpoint;
using std::setfill;

// Fully implement the following class
// Note: SetRectangularSolid should set the h, w, l variables as
//       well as x1, x2, y1, y2, z1, z2
//	 The SurfaceArea function should return the Surface Area of the Solid
//	 The Volume should return the Volume of the Solid
//	 The PrintRectangularSolid should print all the private data
//       plus display if it is a cube or plain rectangular solid

class RectangularSolid
{
	public:
		RectangularSolid(int = 0, int = 0, int = 0, // x1,x2,y1,y2,z1,z2
				 int = 0, int = 0, int = 0);
		void SetRectangularSolid(int, int, int, // x1,x2,y1,y2,z1,z2
					 int, int, int );
		int SurfaceArea();
		int Volume();
		bool IsCube();
		void PrintRectangularSolid();
	private:
		int x1, y1, x2, y2, z1, z2;
		int h,w,l;
		
};

RectangularSolid::RectangularSolid(int X1, int X2, int Y1, int Y2, 
		int Z1, int Z2)
{
	SetRectangularSolid(X1,X2, Y1, Y2, Z1,Z2);
}

void RectangularSolid::SetRectangularSolid(int X1, int X2, int Y1, int Y2,
		int Z1, int Z2)
{
	x1 = X1;
	x2 = X2;
	y1 = Y1;
	y2 = Y2;
	z1 = Z1;
	z2 = Z2;

	h = abs(y2 - y1);
	w = abs(z2 - z1);
	l = abs(x2 - x1);

}

int  RectangularSolid::SurfaceArea()
{
	 return 2*l*h + 2*h*w + 2*l*w;

}

int  RectangularSolid::Volume()
{
       	return l * w * h;
}

bool  RectangularSolid::IsCube()
{
	if (l == h && h == w)
		return true;

	return false;
}

void RectangularSolid::PrintRectangularSolid()
{
	if(IsCube())
		cout << "Rectangular Solid is a Cube" << endl;
	else
		cout << "Rectangular Solid is a Plain Rectangular Solid" 
			<< endl;
	
	cout << "length = " << l << endl;
	cout << "width = " << w << endl;
	cout << "hgt = " << h << endl;
	cout << "Surface Area" << SurfaceArea() << endl;
	cout << "Volume" << Volume() << endl;
}

// Please supply the rest of the class functions.

// In the driver (from within main()) test the following conditions:
// Condition 1:
// x1 = 0, x2 = 1, y1 = 0, y2 = 1, z1 = 0, z2 = 1
// 
// Condition 2:
// No Values passed to constructor
//
// Condition 3:
// x1 = 2, x2 = 4, y1 = 0, y2 = 2, z1 = 0, z2 = 4

// For each condtion please test the IsCube, SurfaceArea, Volume, 
// and PrintRectangularSolid funcitons.

main()
{
	RectangularSolid R1( 0,  1,  0,  1, 0, 1);
	RectangularSolid R2;
	RectangularSolid R3 ( 2, 4, 0,2,0,4);

	R1.PrintRectangularSolid();
	R2.PrintRectangularSolid();
	R3.PrintRectangularSolid();
}
