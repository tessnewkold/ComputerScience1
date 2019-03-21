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
    int win = 0;
    int loose = 0; 
    char play; 
    int i = 0;
    
    cout << "Enter your point value (1-6): " << endl;
    cin >> pickNum;
    
      do{
        int die = 0;
        die = rollDie();
        cout << "The die rolled: " << die << endl;
        
        if (die == pickNum){
            win++; 
            cout << "You have won " << win << " times!" << endl;
        }
        else if (die != pickNum){
            loose++;
            cout << "You have lost " << loose << " times!" << endl;
        }
        cout << "Enter any character to roll again, except x to quit" << endl;
        cin >> play;
      }
      while (play != 'x');
      
    
    return 0;
}