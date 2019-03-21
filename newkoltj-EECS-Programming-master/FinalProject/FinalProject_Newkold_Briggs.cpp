#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

class Hangman{                                                  //made a class called hangman 
    public:
        string Word();
        void Game();
    private:
        int strikes;
};

string Hangman::Word(){                                   //function that cycles when the player starts the game
        srand(time(0));                                         //also repeats if the user chooses to play again by pressing 'y'
        int number = ((rand() %10) + 1);                        //made 10 words that can be randomly generated
        string word;
        if(number == 1){                                        //words are all related to finals and the perils they bring 
            word = "finals";
        }
        else if(number == 2){
            word = "classes";
        }
        else if(number == 3){
            word = "coffee";
        }
        else if(number == 4){
            word = "stress";
        }
        else if(number == 5){
            word = "caffeine";
        }
        else if(number == 6){
            word = "programming";
        }
        else if(number ==7){
            word = "sleep";
        }
        else if(number == 8){
            word = "calculus";
        }
        else if(number == 9){
            word = "soda";
        }
        else if(number == 10){
            word == "sandwitches";
        }
        else{                                                   //this should never happen because the random generator only gives numbers between 1-10
            cout << "error" << endl;                            //however, i uncluded it just in case 
        }
        return word;                                            //this funtion will return the random word generated to the funtion below 
}

void Hangman::Game(){
    bool done = 0;
        while(done == 0){ 
            cout << endl << "\tThank you for choosing to play HANGMAN!" << endl;
            cout << "\t\tLets start playing!" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "You lose if you make 5 wrong guesses. You will see the man being hung..." << endl;
            cout << "Hint: Words are finals related..." << endl;
            strikes = 0;
            string word = Word();                         //Word() is called and the funtion below is executed and will return a random word and stored in word for further use below
            char current [word.length()];
            for(unsigned i = 0; i < word.length(); i++){        //this starts out the word as all underscores at the length of the word generated before letters are correctly guessed
                current[i] = '_';
            }
            bool correct = 0;
            vector <char> guesses;                              //creates a vector to store previous guesses, wrong or right
            char guess;
            unsigned final_count = 0;
            while(correct == 0 && strikes < 5){                 //continue to prompt for letter guesses until they guess wrong 5 times or get the word correct
                cout << "Wrong guesses: " << strikes << endl;   //counts the number of wrong guesses so user can keep track. Also user can look at picture of hangman being drawn
                cout << "Quesses left: " << 5-strikes <<  endl; //tells the user how many guesses they have left
                for(unsigned i = 0; i < word.length(); i++){     //displays the word with any correctly identified letters
                    cout << current[i] << " ";
                }
                cout << endl << endl;

                cout << "Guess a letter: ";                     //prompts user to enter guess 
                cin >> guess;                                   //user enters guess here

                bool found = 0;
                for(unsigned i = 0; i < guesses.size(); i++){   //checks to see if the guess has already been made
                    if(guesses[i] == tolower(guess)){
                        found = true;
                    }
                }
                if(found){                                      //this searches to see if the guess has already been entered
                    cout << endl << "You have already guessed """ << guess << """" << endl;
                }
                else{
                    guesses.push_back(tolower(guess));          //add the guess to the vector to keep track of number of guessand and what they were 

                    int count = 0;
                    for(unsigned i = 0; i < word.length(); i++){ //checks to see if the guess is found in the word

                        if(word[i] == tolower(guess)){
                            current[i] = tolower(guess);
                            count++;
                            final_count++;
                        }
                    }
                    if(count > 0){
                        cout << endl << "Your guess was correct!" << endl;
                    }
                    else{
                        cout << endl << "Your guess was incorrect." << endl;
                        strikes++;
                        if (strikes == 1){                      //this loop displays the hangman image as the user guesses wrong each time 
                            cout <<" +-----+" << endl;          //the image is progressively displayed 
                            cout <<" |     |" <<endl <<" |" <<endl <<" |" <<endl <<" |"<< endl <<" |" << endl;
                            cout << "==========" << endl; 
                        }
                        else if (strikes == 2){
                            cout <<" +-----+" << endl;
                            cout <<" |     |" <<endl;
                            cout <<" |     O" << endl;
                            cout <<" |" <<endl <<" |"<< endl <<" |" << endl;
                            cout <<" |     " <<endl;
                            cout << "==========" << endl;
                        }
                        else if (strikes == 3){
                            cout <<" +-----+" << endl;
                            cout <<" |     |" <<endl;
                            cout <<" |     O" << endl;
                            cout <<" |   ~-|-~" << endl;
                            cout << " |"<< endl <<" |" << endl;
                            cout <<" |     " <<endl;
                            cout << "==========" << endl;
                        }
                        else if (strikes == 4){
                            cout <<" +-----+" << endl;
                            cout <<" |     |" <<endl;
                            cout <<" |     O" << endl;
                            cout <<" |   ~-|-~" << endl;
                            cout <<" |     | " << endl;
                            cout <<" |     " <<endl;
                            cout << "==========" << endl;
                        }
        
                        else if (strikes == 5){
                            cout <<" +-----+" << endl;
                            cout <<" |     |" <<endl;
                            cout <<" |     O" << endl;
                            cout <<" |   ~-|-~" << endl;
                            cout <<" |     | " << endl;
                            cout <<" |    ( ) " << endl;
                            cout <<" |     " <<endl;
                            cout << "==========" << endl;
                        }
                    }
                    if(final_count == word.length()){           //if all the letters have been correctly identified, exit the loop, but program is not terminated. the user can choose to play again
                        correct = 1;
                    }
                }
            }
            if(correct == 1){
                cout << "You guessed the word correct! And prevented the man from being hung!" << endl;
                cout << "The word was: " << word << endl;       //displays the word that was randomly generated
            }
            else{
                cout << "Sorry, you have lost, your man has been hung." << endl;
                cout << "The word was: " << word << endl;
            }
    
            char ans;
            cout << "Play again? (y/n) ";                       //asks the user if they want to play again 
            cin >> ans;
            if(ans == 'n' || ans == 'N'){
                done = 1;                                       //if user enters n or N the done equals 1 and will prompt the bool statement to exit code 
            }
    }
}

int main() {                                                    //main function as small as possible 
    srand(time(NULL));                                          //random umber generator
    Hangman G1;                                                 // hangman class with added variable G1 - stants for Game 1
    G1.Game();                                                  //variable G1 calls the Game() function
}