#include <iostream>
#include <cstdlib>

using namespace std;

    int rollDie() {
        int rollOut = 0;
        rollOut = rollOut + (rand() % 6) + 1;
        return rollOut;
    }

    bool playOneGame(){
         
        int pickNum = 0; 
        int win = 0;
        int loose = 0; 
        char play = 'x'; 
        int i = 0;
        int die = 0;
        bool score;
    
    cout << "Enter your point value (1-6): " << endl;
    cin >> pickNum;
    
    while(pickNum < 1 || pickNum > 6){
        cout << "Wrong entry -- pick value between 1-6!" << endl;
        cin >> pickNum;
    }
      for(i = 0; i <= 2; i++){
        die = rollDie();
        cout << "The die rolled: " << die << endl;
        
        if (die == pickNum){
            return true;
        }
        else if (die != pickNum){
            score = false;
        }
      }
        return score;
    }
    
int main() {
   srand(time(NULL));
   double wager = 0; 
   bool score;
   int win = 0;
   int loose = 0;
   
   
   score = playOneGame();
   
   if(score == 1){
      cout << "You win!" << endl;
       win = win + 1; 
   }
   else if(score == 0){
       cout << "You loose sucka!" << endl;
       loose = loose + 1;
   }
    return 0;
}