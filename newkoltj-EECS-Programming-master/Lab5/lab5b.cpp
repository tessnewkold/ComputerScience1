#include <iostream>

using namespace std;

long long Factorial(int n){                         //function that evaluates the factorial from user input
    if(n > 1)
        return (n * Factorial(n - 1));              //function repeats over and over until n = 1 then will stop and return the final answer
    else
        return 1;                                   //this returns 1 beacause 1*1=1
    }


int main() {
    int n;
    
    cout << "Enter a positive number to calulate factorial: ";
    cin >> n; 
    cout << endl;
    cout << "Factorial of " << n << " = " << Factorial (n);
    
    return 0;                                       //end of program
}