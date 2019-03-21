// Tess Newkold
// 31 October 2017
// Lab 8 Part B
//Description: A number Guessing game where the user has 7 tries to guess a random generated number
//The user is told higher or lower and continues to guess from there 

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <algorithm>

using namespace std;

class numberGuess{
    public:
        void playGame();                //Plays 1 game
        void PrintResults();            //Prints game statistics 
    private:
        int numWins = 0; 
        int numPlays = 0;
        int randNumber = 0;
};

void numberGuess::playGame(){
    int guess = 0;
    int i = 0; 
    cout << "What is your guess between 0-100 (press 0 to quit)---";
    cin >> guess;
    do{
        if(guess == 0){
            break;
        }
        randNumber = rand() % 100 + 1;
    for (i = 1; i <= 7; i++){
        if(guess > randNumber){
            cout << "Your guess is too high. Guess again.---";
            cin >> guess;
        }
        else if(guess < randNumber){
            cout << "Your guess is too low. Guess again.---";
            cin >> guess;
        }
        else if(guess == randNumber){
            numWins++;
            cout << "YOU WIN!!!!!";
            break;
        }
}
numPlays++;
cout << "To play again, guess a new number between 1-100---";
cin >> guess;
}
while (guess != 0);
}

void numberGuess::PrintResults(){
    cout << "Number of Wins: ";
    cout << numWins << endl;
    cout << "Number of Times you Played: ";
    cout << numPlays << endl;
}

int main(){
    srand(time(NULL));
    numberGuess Game1;
    Game1.playGame();
    Game1.PrintResults();
}