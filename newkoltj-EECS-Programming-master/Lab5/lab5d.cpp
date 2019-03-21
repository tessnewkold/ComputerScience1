#include <iostream>

using namespace std;

bool IsMultipleofFive(int number){                          //function that will check if number is a multiple of 5
    if(number % 5 == 0){                                    //returns true or false because function is bool
        return true;
    }
    else
        return false;
}

bool IsMultipleofThree(int number){                         //function that will check if number is a multiple of 3            
    if(number % 3 == 0){                                    //returns true or false because function is bool
        return true;
    }
    else
        return false;
}

bool IsAnOddNumber(int number){                             //function that will check if number is odd
    if(number % 2 == 1){                                    //returns true or false because function is bool
        return true;
    }
    else
        return false;
}

bool IsAnEvenNumber(int number){                            //function that will check if number is even
    if(number % 2 == 0){                                    //returns true or false because function is bool
        return true;
    }
    else
        return false;
}

int main() {                                                //start of program
    int number = 0; 
    
    for(int i = 1; i <= 100; i++){                          //this loop counts from 1 to 100 by 1 checking bool funtions to print cout statements
        if(IsAnEvenNumber(i)){ 
            cout << i << " - " << "even";
            if(IsMultipleofThree(i))
            {
                cout << ", three";
                if(IsMultipleofFive(i))
                {
                cout << ", five";
                }
            }
            else if(IsMultipleofFive(i))
            {
                cout << ", five";
            }
            
        cout << endl;
        }
        if(IsAnOddNumber(i)){                                       //this loop does the same checking for all the odd numbers 
            cout << i << " - " << "odd";
            if(IsMultipleofThree(i)){
               cout << ", three"; 
            }
            if(IsMultipleofFive(i)){
                cout << ", five";
            }
            cout << endl;
        }
    }
    return 0;                                                       //end of program
}