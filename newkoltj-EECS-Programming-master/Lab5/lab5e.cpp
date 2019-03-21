#include <iostream>

using namespace std;

float Factorial(float n){                                       //function to calculate factorial in each itteration
    if(n > 1)
        return (n * Factorial(n - 1));                          //this will cause the fuction to continue until n = 1 
    else                                                        //if n = 1 then it will just return 1. bc 1*1 = 1
        return 1;
    }



int main() {                                                    //main function that asks the user to type e first and then using the facotrial funtion outputs the constant e. 
    char e;
    float n = 0;
    float x = 0;
    cout << "Type 'e' to return the mathematical constant!";
    cin >> e;
    cout << endl << "e = ";
    x = 1 + (1/Factorial(1)) + (1/Factorial(2)) + (1/Factorial(3)) + (1/Factorial(4))
    + (1/Factorial(5)) + (1/Factorial(6)) + (1/Factorial(7)) + (1/Factorial(8)) + (1/Factorial(9));
    cout << x;
    return 0;
}