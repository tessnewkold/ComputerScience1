#include <iostream>

using namespace std;

int returnMax(int x, int y){                            //funtion that will take the 2 integers the user inputs
    if (x > y) {
        return x;
    }
        return y;

}



int main(){
    int a = 0;
    int b = 0;
        cout << "Enter first integer: ";
        cin >> a;                                           //user input a
        cout << endl;
        cout << "Enter second integer: ";
        cin >> b;                                           //user input b
        int maxNumber = returnMax(a, b);                    //takes user input a and b up to returnMax funtion
        cout << endl;
        cout << "Maximum Value: ";
        cout << maxNumber << endl;                          //return from function was set to maxNumber and then output here
    return 0;                                               //program ends
}