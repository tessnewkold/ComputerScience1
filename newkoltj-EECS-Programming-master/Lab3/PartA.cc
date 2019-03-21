#include <iostream>
using namespace std;

//program Writes a for loop that goes from 25 to 0 in loop steps of .5 
//it then outputs the sum of all the numbers
//and the average
int main () {                                   
    float value = 0;
    int sum = 0;
    //Loop 1
    for(value = 2; value <= 35; value = value + 3){

        sum += value;
    }
        cout << "Sum: ";
        cout << sum << endl;

    //Loop 2 
    int average = 0;
    sum = 0;
    
    for(value = 2; value <= 40; value = value +2){
        sum += value;
    }
        average = sum / 20;
        cout << "Average: " << average << endl;

    //Loop3
    
    for(double j = 25; j >= 0; j = j - 0.5){
        cout << j;
        if (j > 0.4)
            cout << ", ";
    }
return 0;
}

