// Name: Tess Newkold
//
// Class Cylinder
// 
// Notes: A cylinder can be defined in terms of its radius or diameter.
//													radius is Diameter/2
// 
//	  Surface Area of a cyliner is 2 * PI *(radius * (radius*height))
//	  Volume of a cylinder is height * PI (Radius * Radius)
//	  

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const double PI =  3.14159265358979323846;

// Fully implement the following class

class Cylinder
{
	public:
		Cylinder();			// default constructor
		Cylinder(double);	// double is the Radius
		void SetCylinder(double);		// double is the Radius,
		void SetVolume(double);				// Should set volume, and area
		void SetSurfaceArea(double);
															// too.
		double GetRadius();			// Return the Radius
		double GetHeight();			// Return the height
		double SurfaceArea();		// Calculates the SufaceArea
		double Volume();			// Calculates the Volume
		void PrintCylinder();		// Prints Information about 
	private:
		double radius;
		double height;
		int h;
		double volume;
		double surfacearea;
		
};

Cylinder::Cylinder()
{
	SetCylinder(1.0);
}

Cylinder::Cylinder(double r)
{
	SetCylinder(r);
}

void Cylinder::SetCylinder(double r)
{
	radius = r;
	height = h;
	surfacearea = 2.0 * PI * (radius * (radius * height));
	volume 	    = height * PI * (radius * radius);
}

double Cylinder::GetRadius(){
	return radius;
}

double Cylinder::GetHeight(){
	return height;
}

double Cylinder::SurfaceArea(){
	return surfacearea;
}

double Cylinder::Volume(){
	return volume;
}

void Cylinder::PrintCylinder(){
	cout << "Radius: ";
	cout << radius << endl;
	cout << "Height: ";
	cout << height << endl;
	cout << "Volume: ";
	cout << volume << endl;
	cout << "Surface Area: ";
	cout << surfacearea << endl;
}


int main() {
	Cylinder C1(2), C2, C3(5);


	C1.PrintCylinder();
	C2.PrintCylinder();
	C3.PrintCylinder();
	C3.SetCylinder(6);
	C3.PrintCylinder();

	return 0;
}