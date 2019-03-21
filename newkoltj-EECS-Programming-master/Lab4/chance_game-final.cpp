#include <iostream>
#include <cstdlib>                                  //added <cstdlib>

using namespace std;

int win;
int loose;

    int rollDie() {                                 //this function is to output the randomness of rolling 1 die
        int rollOut = 0;
        rollOut = rollOut + (rand() % 6) + 1;       //produce random number with the roll of a die
        return rollOut;                             //will return the random number under rollOut
    }

    bool playOneGame(){                             //function is for one game of rolling the dice
        int pickNum = 0; 
        double win = 0;
        double loose = 0; 
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
  
   double WinFinal(){
 //       double win = 0;
//        double loose = 0;
        double winFinal = ((win / (win + loose)) * 100);
        return winFinal;
    }
        
    double LooseFinal(){   
 //       double win = 0;
   //     double loose = 0;
        double looseFinal = ((loose / (win + loose)) * 100);
        return looseFinal;
    }
    
    
int main() {                                                            // program starts here
   srand(time(NULL));
   float wager = 0; 
   float balance = 100;
   bool score;
   double win = 0;
   double loose = 0;
   double looseScore = 0;
   double winScore = 0;
   
   
   do{
       cout << "Account Balance: " << balance << endl;                  //initially showing the user there balance
       cout << "Enter wager (0 to quit): ";                             //this happens eveytime they win or loose 
       cin >> wager;
       if(wager == 0){
           cout << "Your final account balance is: " << balance << endl;
           cout << "Total Wins: " << win << endl;
           cout << "Win Percentage: " << WinFinal() << endl;                //these will show the final win/loss count with %
           cout << "Total Looses: " << loose << endl;
           cout << "Looses Percentage: " << LooseFinal() << endl;
       break;
       }
       
       while(wager > balance){
           cout << "You dont have that much money, ya foo! Bet less money: ";
           cin >> wager;
       }

   
   score = playOneGame();                                           //the playOneGame function will be executed
   
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
   // WinScore();
 //   LooseScore();
 }
   while(wager != 0);                                           // once use enters 0 the program will terminate
    return 0;                                                   //end of program 
}