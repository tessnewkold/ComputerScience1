// Name: Tess Newkold
//
// Class Cube
// 
// Notes: A cube can be defined in terms of its length only
//	  Surface Area of a cube is 6 * (length * length)
//	  Volume of a cube is length * length * length
//	  

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// Fully implement the following class

class Cube
{
	public:
		Cube();			// default constructor
		Cube(double);	// double is the length
		void SetCube(double);		// double is the length,
		void SetVolume(double);			
		void SetSurfaceArea(double);

		double GetLength();			// Return the length
		double SurfaceArea();		// Calculates the SufaceArea
		double Volume();			// Calculates the Volume
		void PrintCube();		// Prints Information about 
	private:
		double length;
		int l;
		double volume;
		double surfacearea;
		
};

Cube::Cube()
{
	SetCube(1.0);
}

Cube::Cube(double l)
{
	SetCube(l);
}

void Cube::SetCube(double l)
{
	length = l;
	surfacearea = 6 * (length * length);
	volume = length * length * length;
}

double Cube::GetLength(){
	return length;
}

double Cube::SurfaceArea(){
	return surfacearea;
}

double Cube::Volume(){
	return volume;
}

void Cube::PrintCube(){
	cout << "Length: ";
	cout << length << endl;
	cout << "Volume: ";
	cout << volume << endl;
	cout << "Surface Area: ";
	cout << surfacearea << endl;
}


int main() {
	Cube C1(2), C2, C3(5);


	C1.PrintCube();
	C2.PrintCube();
	C3.PrintCube();
	C3.SetCube(6);
	C3.PrintCube();

	return 0;
}