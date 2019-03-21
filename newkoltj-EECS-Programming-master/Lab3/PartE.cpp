#include <iostream>

using namespace std;

int main() {
    
 for(int i=1; i<=100; i++){
    cout << i << " - ";
    if(i % 2 == 0){
         cout << "even";        //if number is even 
    }
    else{
         cout << "odd";         //if number is odd
    }
    if(i % 3 == 0){
        cout << ", three";      //if number is divisible by 3
    }
    if(i % 5 == 0){
        cout << ", five";       //if number is divisible by 5 
    }
    cout << endl;
 }
    return 0; 
}