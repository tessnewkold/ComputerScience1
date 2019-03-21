/* Tess Newkold
31 October 2017
Lab 8 Part C
Description: The user needs to find the hidden latte or coffee in a 2D maze
                whatever they find first is what they get to drink.
                The computer can give clues in which direction to move.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

class Coordinate{
    public:
        void playGame();
        void PrintResults();
    private:
        int num1;
        int num2;
        int num3;
        int i=0;
        int k=0;
        int location=0;
        int x;
        int y;
        int play=0;
        int x1;
        int x2;
        int y1;
        int y2;
        int total=0;
        int right=0;
        int attempts=0;
        char choice;
        char initialguess;
};

void Coordinate::playGame(){
    int arr[10][10]; //array for game
 
    do{
        for(i=0;i<10;i++){
            for(k=0;k<10;k++){
                arr[i][k]=0;
            }
        }
        
        //random generator for location
        srand(time(0));
        num1=rand()%100+1;
        arr[num1/10][num1%10]=1;
        location=rand()%100+1;
        
        while(location==num1){
            location=rand()%100+1;
        }
        
        num2=location;
        arr[num2/10][num2%10]=2;
        location=rand()%100+1;
        
        while(location==num1 && location == num2){
            location=rand()%100+1;
        }
        
        num3 = location;
        x=num3/10;
        y=num3%10;
        arr[x][y]=-1;
        cout << endl;
        cout << "Find out how Basic you are, try to find the PSL!!!"<< endl;
        cout << endl;
        
        do{
            x1=abs(num1/10-x);//distances from latte
            y1=abs(num1%10-y);
            x2=abs(num2/10-x);
            y2=abs(num2%10-y);
            
            cout << "Enter your guess of direction (n, e, s, w) "<< endl;
            cin>> initialguess;
            attempts++;
            
            // each case whether its n,s,e,or w
            if (initialguess=='n'){
                if(arr[x-1][y]==1){
                    cout << "You found the Latte!"<< endl;
                    right++;
                    play=1;
                }
                else if (arr[x-1][y]==2){
                    cout << "You found a Coffee"<< endl;
                    total += attempts;
                    play =1;
                }
                else{
                    arr[x-1][y]=-1;
                    arr[x][y]=0;
                    x=x-1;
                    if(abs(num1/10-x)<x1||abs(num2/10-x)<x2){
                        cout << "Getting Warmer"<< endl;
                    }
                    else{
                        cout << "Getting Colder"<< endl;
                    }
                }
            }
            else if(initialguess == 's'){
                if (arr[x+1][y]==1){
                    cout << "You found the Latte!"<< endl;
                    right++;
                    play=1;
                }
                else if (arr[x+1][y]==2){
                    cout << "You found a coffee"<< endl;
                    total += attempts;
                    play=1;
                }
                else{
                    arr[x+1][y]=-1;
                    arr[x][y]=0;
                    x=x+1;
                    if(abs(num1/10-x)<x1|| abs(num2/10-x)<x2){
                        cout << "Getting Warmer"<< endl;
                    }
                    else{
                        cout << "Getting Colder"<< endl;
                    }
                }
            }
            else if(initialguess == 'w'){
                if (arr[x][y-1]==1){
                    cout << "You found the Latte!"<< endl;
                    right++;
                    play=1;
                }
                else if (arr[x][y-1]==2){
                    cout << "You found a coffee"<< endl;
                    total += attempts;
                    play=1;
                }
                else {
                    arr[x][y-1]=-1;
                    arr[x][y]=0;
                    y=y-1;
                    if(abs(num1%10-y)<y1||abs(num2%10-x)<y2){
                        cout << "Getting warmer"<< endl;
                    }
                    else{
                        cout << "Getting colder"<< endl;
                    }
                }
            }
            else if(initialguess == 'e'){
                if (arr[x][y+1]==1){
                    cout << "You found the latte!"<< endl;
                    right++;
                    play=1;
                }
                else if (arr[x][y+1]==2){
                    cout << "You found a coffee"<< endl;
                    total += attempts;
                    play=1;
                }
                else{
                    arr[x][y+1]=-1;
                    arr[x][y]=0;
                    y=y+1;
                    if (abs(num1%10-y)<y1 || abs(num2%10-x)<y2){
                        cout << "You are getting Warmer"<< endl;
                    }
                    else{
                        cout << "You are getting colder"<< endl;
                    }
                }
            }
            else{
                cout << "Input Error"<< endl;
            }
        }while (play==0);
        
    total += attempts;
    cout << "Do you want to Play again? Y or N" << endl;
    cin >> choice;
    cout << endl;
    
    choice = tolower(choice);
    if (!(choice == 'y'|| choice =='n')){
        cout << "Error, enter y or n";
    }
}
    while(choice == 'y');
}

void Coordinate::PrintResults(){
    cout << "Total Moves: "<< total << endl;
    cout << "Times you found the PSL: "<< right << endl;
}

int main(){
    srand(time(NULL));
    Coordinate Game1;
    Game1.playGame();
    Game1.PrintResults();

return 0;   
}