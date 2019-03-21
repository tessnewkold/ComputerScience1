#include<iostream>
#include<math.h>

using namespace std;

int main(){                                                     //start of program
   int n = 0;                                                   //declaring all variables
   int num = 1;
   int primeCount = 0;
   
   cout << "Enter what number you want to see the prime numbers go up to. ";
   cin >> n;                                                    //user inputs number 
   
   cout << 1 << endl;
   
   for(int j =1; j <= n; j++){
       num++;
       primeCount = 0;
       for(int i = 1; i <= num; i++){
           if(num % i == 0){                                    //number has to be divisible by itself with no remainder
               primeCount++;                                    //prime counter
           }
       }
       if(primeCount == 2){
           cout << num << endl;
       }
   }
   
    return 0;
}