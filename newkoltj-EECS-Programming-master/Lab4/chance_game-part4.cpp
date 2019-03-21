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
           // win++; 
            //cout << "You have won " << win << " times!" << endl;
            return true;
        }
        else if (die != pickNum){
         //   loose++;
           // cout << "You have lost " << loose << " times!" << endl;
            score = false;
        }
      }
        return score;
    }
  //      cout << "Enter any character to roll again, except x to quit" << endl;
    //    cin >> play;
      //while (play != 'x');
      
    //return score;
//    }
int main() {
   srand(time(NULL));
   double wager = 0; 
   double balance = 100;
   bool score;
   int win = 0;
   int loose = 0;
   
   
   do{
       cout << "Enter wager (0 to quit): ";
       cin >> wager;
       if(wager == 0)
       break;
       
       while(wager > balance){
           cout << "You dont have that much money, ya foo! Bet less money: ";
           cin >> wager;
       }

   
   score = playOneGame();
   
   if(score == 1){
      cout << "You win!" << endl;
       win = win + 1; 
       balance = balance + wager;
       cout << "Your new balance is: " << balance << endl;
   }
   else if(score == 0){
       cout << "You loose sucka!" << endl;
       loose = loose + 1;
       balance = balance - wager;
       cout << "Your new balance is: " << balance << endl;
   }
 }
   while(wager != 0);
    return 0;
}