#include <iostream>
using namespace std;

int main () {
    
    int startNum = 0;
    int endNum = 0;
    int steps = 0;
    int sumODD = 0;
    int sumEVEN = 0;
    int sumALL = 0;
    int avg = 0; 
    int counter = 0;
    
    cout << "Start Number: ";
    cin >> startNum;
    cout << "Ending Number: ";
    cin >> endNum;
    cout << "Steps: ";
    cin >> steps;
    
    if ((endNum > startNum) && (steps >= 1))
    {
    for(int i = startNum; i<=endNum; i = i+steps)
    {
        if(i % 2 == 1)
        {sumODD = sumODD + i;}
        if(i % 2 == 0)
        {sumEVEN = sumEVEN + i;}
        ++counter; 
    }
    
    sumALL = sumEVEN + sumODD;
    avg = sumALL/counter;
    
    cout << "ODD Number Sum: " << sumODD << endl;
    cout << "EVEN Number Sum: " << sumEVEN << endl;
    cout << "Sum of ALL Numbers: " << sumALL << endl;
    cout << "Average: " << avg << endl;
    
    }
    
return 0;
}