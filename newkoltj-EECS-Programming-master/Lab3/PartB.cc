#include <iostream>
using namespace std;

//program lets user enter in values and the program sums the values
int main () {
    
    float num = 0;
    float sum = 0;
    
    do {
        cout << "Enter Positive Number to Add or Enter Zero or Negative Number to End: ";
        cin >> num;
        sum += num;
    } while (num > 0);          //this allows the user to enter a negative number or 0 to exit the program 
    
    cout << "Sum of Entered Numbers: " << sum << endl;
return 0;
}