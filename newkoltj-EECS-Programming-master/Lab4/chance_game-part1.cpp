#include <iostream>
#include <cstdlib>

using namespace std;

    int rollDie() {
        int rollOut = 0;
        srand(time(NULL));
        rollOut = rollOut + (rand() % 6) + 1;
        return rollOut;
    }

int main() {
    
    int pickNum = 0; 
    cout << "Enter your point value (1-6): " << endl;
    cin >> pickNum;
    
        int die = 0;
        die = rollDie();
        cout << "The die rolled: " << die << endl;
        
 
    return 0;
}