//Tess Newkold
//14November2017 
//Lab 10 Part A
//Description: Operator Overloading
//              Finding the surface area and perimeter of a regular octagon

#include <iostream> 
#include <cmath>

using namespace std;

class Octagon {
    
    friend ostream& operator << (ostream&, const Octagon&);
    friend istream& operator >> (istream&, Octagon&);
    
    public:
        Octagon();
        Octagon(double);
        void SetOctagon(double);
        void SetSide(double);
        void SetSurfaceArea();
        void SetPerimeter();
        double GetSide();
        double GetSurfaceArea();
        double GetPerimeter();
        void PrintOctagon();
        Octagon operator +(Octagon);
        bool operator !=(Octagon);
        double side;
    
    private:
  //      double side;
        double s;
        double SurfaceArea;
        double perimeter;
};


Octagon::Octagon(){
    SetOctagon(1.0);
}

Octagon::Octagon(double s){
    SetOctagon(s);
}

void Octagon::SetOctagon(double s){
    side = s;
    SetPerimeter();
    SetSurfaceArea();
}

void Octagon::SetSide(double){
    SetOctagon(s);
}

void Octagon::SetSurfaceArea(){
    SurfaceArea = 2 * (1 + sqrt(2.0)) * (side* side);
}

void Octagon::SetPerimeter(){
    perimeter = 8 * side;
}

double Octagon::GetSide(){
    return side;
}

double Octagon::GetPerimeter(){
    return perimeter;
}

double Octagon::GetSurfaceArea(){
    return SurfaceArea;
}

void Octagon::PrintOctagon(){
    cout << "____Octagon Dimenstions________" << endl;
    cout << "\tSide Length: " << side << endl;
    cout << "\tSurface Area: " << SurfaceArea << endl;
    cout << "\tPerimeter: " << perimeter << endl;
}

Octagon Octagon::operator+(Octagon first){
    Octagon newOctagon;
    newOctagon.side = side + first.GetSide();
    return newOctagon;
}

bool Octagon::operator !=(Octagon first){
    if(side -0.01 >= first.GetSide() && side + 0.01 <= first.GetSide())
        return false;
    else
    return true;
}

ostream & operator<<(ostream& output, const Octagon& sample){
    output << "Side Length: " << sample.side << endl;
    output << "Perimeter: " << sample.perimeter << endl;
    output << "Surface area: " << sample.SurfaceArea << endl;
    return output;
}

istream & operator>>(istream &input, const Octagon &sample){
    input  >> sample.side;
    return input;
}

int main(){
    Octagon O1;
    Octagon O2(5);
    
    O1.PrintOctagon();
    O2.PrintOctagon();
    
    Octagon O3;
    O3 = O1 + O2;
    O3.PrintOctagon();
    return 0;
}