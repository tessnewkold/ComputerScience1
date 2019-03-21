#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <fstream>


using namespace std;

//Accepts a double value as degrees and returns the radian equivalent. 


double degreesToRadians (double degrees)
{

    float pi = 3.14159265;
    double radiis = 0;

    
    if (degrees >= 0)           //for positive degree values
    {
        radiis = degrees * (pi / 180);
        
        while (radiis > (2*pi)) //Checking to make sure the radian value is between 0 and 2*PI 
        {
            radiis = radiis - pi;
        }
        
    }
    else                    //for negative degree values
    {
        radiis = (degrees * (pi / 180)); 
        
         while (radiis < -(2*pi))   //Checking to make sure radian value is between 0 and -2*PI
        {
            radiis = radiis + pi;
        }
    }
    
    return radiis;
}

//Create a structure to hold an x,y coordinate pair. 

struct coord 
{
    double x;
    double y;
};


double slopeFunction (coord First, coord Second)
{
    double slope = 0;
    
    slope = (Second.y - First.y)/(Second.x - First.x);
    
    return slope;
}


//And a create a second function that takes two coordinate pairs and returns the y-intercept.
double yIntercept(coord First, coord Second)
{
    double slope = 0;
    double yInt = 0;
    
    slope = slopeFunction(First, Second);
    
    yInt = First.y - slope * First.x;
    
    return yInt;
}

//Rectangle information function
double rectInfo(coord First, coord Second)
{
    double upperCordx = 0;
    double upperCordy = 0;
    double lowerCordx = 0;
    double lowerCordy = 0;
    double distx = 0;
    double disty = 0;
    double width = 0;
    double height = 0;
    double area = 0;
    
    if (First.y > Second.y)
    {
        upperCordx = First.x;
        upperCordy = First.y;
       
       //Lower and upper coordinates 
        cout << "Upper coordinates are: (" << upperCordx << ", " << upperCordy << ")" << endl;
    }
    else if (First.y < Second.y)
    {
        upperCordx = Second.x;
        upperCordy = Second.y;
        cout << "Upper coordinates are: (" << upperCordx << ", " << upperCordy << ")" << endl;
    }
    
    //Rectangle Width
    
    width = abs(Second.x - First.x);
    cout << "Rectangle width is: " << width << endl;
    
    //Rectangle Height
    
    height = abs(Second.y - First.y);
    cout << "Rectangle height is: " << height << endl;
    
    //Rectangle Area
    area = height * width;
    cout << "Rectangle area is: " << area << endl;
    
    
}

int main()
{
    //for egrees to Radians Function
    double deg = 8995;
    cout <<"The value of " << deg << " in radians is: " << degreesToRadians (deg) << endl;
    
    //for struct slope and y intercept functions
    coord first;
    coord second;
    
    first.x = 5;
    first.y = 8;
    
    second.x = 2;
    second.y = 3;
    
    cout <<"The slope of the 2 points is: " << slopeFunction(first, second) << endl;
    cout <<"The y intercept of the 2 points is: " << yIntercept(first, second) << endl;
    
    //for the rectangle funciton
    cout << rectInfo(first, second) << endl;
    
    
    
    
    return 0;
}