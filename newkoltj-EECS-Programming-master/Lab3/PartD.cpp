#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = 3.14159;
double i = 0;

//program outputs the sine, cosine, and tangent values for corresponding degree angles from 0 to 360 in 10degree increments
int main() {
    double angle_in_radians;
    
    cout << "Degrees      Sine           Cosine          Tangent" << endl;  //headers 
    
    for(i = 0; i <= 360; i = i + 10){
        angle_in_radians = i * (pi/180.0);
        cout << i << "\t" << setw(10) << setprecision(4)<< sin(angle_in_radians);       //output sin
        cout << i << "\t" << setw(10) << setprecision(4) << cos(angle_in_radians);      //output cosine
        cout << i << "\t" << setw(10) << setprecision(4) << tan(angle_in_radians) << endl;  //out tangent
    }
return 0;
    }