
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cctype>
#include <ctime>
#include <algorithm>


using namespace std;

//histogram - Accepts an integer vector and displays  histogram of the values
//stored in that vector scaled to fit the page.

int histogram (vector <int> numVect)
{
    srand(time(0)); 
   
    int i = 0;
    int j, k, l = 0;
    int numStars1 = 0;
    int numStars2 = 0;
    int numStars3 = 0;
    char numStars[] = "*";
    
    int rando = 0;
    
    
    
       
    for (i = 0; i < 60; i++)        //This is a vector of 60 random terms from 1-9
    {
        rando = (rand()% 9) + 1;
        numVect.push_back(rando);
    }
    
    
    for (i = 0; i < 60; i++)        //Going through the vector to keep track of all the occurances of each number grouped in 3s
    {
    if (numVect.at(i) == 1 || numVect.at(i) == 2 || numVect.at(i) == 3)
    {
        numStars1++;    
    }
    else if (numVect.at(i) == 4 || numVect.at(i) == 5 || numVect.at(i) == 6)
    {
        numStars2++;    
    }
    else if (numVect.at(i) == 7 || numVect.at(i) == 8 || numVect.at(i) == 9)
    {
        numStars3++;
    }
    else
    {
        return 0;
    }
    }
    
    //Displaying the histogram
    cout << "Value Ranges: " << endl;
    cout << "From 1 - 3:\t";
    for (j = 0; j < numStars1; j++)
    {
    numStars[numStars1] = '*';
    cout << numStars;
    }
    
    cout << endl << "From 4 - 6:\t";
     for (k = 0; k < numStars2; k++)
    {
    numStars[numStars2] = '*';
    cout << numStars;
    }
    
    cout << endl << "From 7 - 9:\t";
     for (l = 0; l < numStars3; l++)
    {
    numStars[numStars3] = '*';
    cout << numStars;
    }
    
    return 0;
   
}

int main()
{
    
  

vector <int> histoNums; 


    histogram(histoNums);
    
    return 0;
}