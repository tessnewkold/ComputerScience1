
#include <iostream>
#include <cstdlib>

using namespace std;

class DiceGame{
public:
    int genRandom(int seed, int lower, int higher) {
        static int seeded = 0;
        if (!seeded) {
                srand(seed);
                seeded = 1;
        }
        return random()%((higher - lower)+1) + lower;

            
        }
        

    void playGame() {
        int seed = 4444;
        int die1 = 0;
        int die2 = 0;
        int done = 0;
        int total = 0;

        cout << "Enter Seed : " << endl;
        cin >> seed;
        

        do {
            die1 = genRandom(seed, 1, 6 );
            die2 = genRandom(seed, 1, 6);
            total = die1 + die2;
            
            if((total == 7) || (total == 9) || (total == 11)) {
               cout << "You rolled Die: " << die1 << " and Die 2: " << die2 << " for a total of: " << total << " was rolled \n"; 
               cout << "You are a Winner!" << endl;
               done = 1;
            }
            else if((total == 2) || (total == 3) || (total == 5)) {
               cout << "You rolled Die: " << die1 << "and Die 2: " << die2 << "for a total of: " << total << "was rolled";
               cout << "You are NOT a Winner!" << endl;
               done = 1;            
            }
            else {
             cout << "You rolled Die 1: " << die1 << "and Die 2: " << die2 << "for a total of: " << total << "was rolled"; 
               cout << "Please Roll Again" << endl;
            }  
        } while (!done);
        cout << "Game Over!" << endl;

        
}
};


int main() {
    
    DiceGame Game1;
    Game1.playGame();
    return 0;
    
}
