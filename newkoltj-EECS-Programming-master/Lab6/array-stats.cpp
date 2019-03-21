
/*
Name: Tess Newkold
Date: October 3rd 2017
Assignment: Lab 6
Description: Functions, Arrays, and Loop Practice
*me: <fill me in>
Date: <fill me in>
Assignment: <fill me in>
Description: <fill me in>
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

void init(int array[], int length, int value){  //function for writing what value is "isin" at a certain position
  for(int i = 0; i < length; i++){
    array[i] = value;
  }
}

void init(string array[], int length, string value){    //function for writing what string is "isin" at a certain position
  for(int i = 0; i < length; i++){
    array[i] = value;
  }
}

int count(int array[], int length, int value){          //counts how many times a value is called in a vector
  int counter = 0;
  for(int i = 0; i < length; i++){
    if(array[i] == value){
      counter++;
    }
  }
  return counter;
}

int count(string array[], int length, string value){    //counts how many times a certain string is called in a vecotr
  int counter = 0;
  for(int i = 0; i < length; i++){
    if(array[i] == value){
      counter++;
    }
  }
  return counter;
}

bool isSorted(int array[], int length){               //returns true is the vector is sorted from smallest to largest
  for(int i = 0; i < length; i++){                    //returns false if the vector is not from smallest to largest
    if(i < (i + 1))  
      return true;
    if(i > (i+1))
      return false;
}
}

void reverse(int array[], int length){                //function reverses the vector
  for (int i = 0; i < length / 2; i++){
    int temp = array[i];
    array[i] = array[(length - 1) - i];
    array[(length - 1) - i] = temp;
  }
}

float mean(float array[], int length){                //function returns the mean
  float sum = 0;
  for(int i = 0; i < length; i++){
    sum = sum + array[i];
  }
  float mean = sum/length;
  return mean;
}

float stdev(float array[], int length){               //function returns the standard deviation of the vecotr
  float sum = 0; 
  float mean = 0; 
  float stdev = 0; 
  int i = 0;
  for(i = 0; i < length; i++){
    sum = sum + array[i];
  }
  mean = sum / length;
  for(i = 0; i < length; i++){
    stdev = stdev + pow(array[i] - mean, 2);
  }
  return sqrt(stdev / length);
}

void shuffle(float array[], int length){              //shuffles the vectors values 
  for(int i = 0; i > length; i++){
    int r = i + rand() % (length - i);
    swap(array[i], array[r]);
  }
}
vector<int> removeDups(vector<int> array){  
    for (int i=0; i < array.size() - 1; i++){
      for(int j= i + 1; j < array.size(); j++){
        if (array.at(j)==array.at(i)){
        array.erase(array.begin()+i); 
        }
      }//removes values that were duplicated 
}
sort(array.begin(), array.end());
    return array;
}
  /*
  std:: sort(array.begin(), array.end());
  array.erase(std::unique(array.begin(), array.end()), array.end());
  return vector<int>();
}
*/

// See below for this function
template<typename T>
string print(T array[], int length);


int main(){           
  srand(time(0));   
 
  cout << "reverse" << endl;
  int a1[] = {1,2,3,4,5};
  reverse(a1, 5);
  cout << "[5,4,3,2,1] = " << print(a1, 5) << endl;
  reverse(a1, 5);
  cout << "[1,2,3,4,5] = " << print(a1, 5) << endl;
  int a2[] = {5};
  cout << "[5] = " << print(a2,1) << endl;
  int a3[] = {1,2,4,5};
  reverse(a3, 4);
  cout << "[5,4,2,1] = " << print(a3, 4) << endl;
  int a4[100] = {1,2};
  reverse(a4, 100);
  cout << "0 = " << a4[0] << endl;
  cout << "2 = " << a4[98] << endl;
  
  float f1[] = {5.6, 2.1, 9.9, 125.4};
  float f2[] = {5.6, 5.6, 5.6, 5.6, 5.6, 5.6};
  cout << endl << "mean:" << endl;
  cout << "35.75 = " << mean(f1, 4) << endl;
  cout << "5.6 = " << mean(f2, 6) << endl;
  
  cout << endl << "stdev:" << endl;
  cout << "51.8331 = " << stdev(f1, 4) << endl;
  cout << "0 = " << stdev(f2, 6) << endl;
  
  cout << endl << "shuffle:" << endl;
  shuffle(f1, 4);
  // These should not match, but there is a chance they will.
  cout << "[94.6,91.1,98.9,214.4] != " << print(f1, 4) << endl;
  cout << "51.8331 = " << stdev(f1, 4) << endl;
  
  cout << endl << "removedups:" << endl;
  //vector<int> v1 = {1,2,3,3,4,5,1};  // Not supported in C++98
  vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(3);
  v1.push_back(4);
  v1.push_back(5);
  v1.push_back(1);
  vector<int> v12 = removeDups(v1);
  cout << "[1,2,3,4,5] = " << print(v12.data(), v12.size()) << endl;
  cout << "5 = " << v12.size() << endl;
  vector<int> v2;
  for(int i = 0; i < 100; i++){
    v2.push_back(i%17 + i %7);
  }
  vector<int> v22 = removeDups(v2);
  cout << "22 = " << v22.size() << endl;
  cout << endl;

  cout << "Init w/ ints" << endl;
  init(a1, 5, 99);
  cout << "99 = " << a1[1] << endl;
  cout << "99 = " << a1[3] << endl;

  cout << endl << "Init w/ strings" << endl;
  string sa2[] = {"", "Bla", "What?", "You don't say!"};
  init(sa2, 4, "Empty");
  cout << "Empty = " << sa2[0] << endl;
  cout << "Empty = " << sa2[3] << endl;

  cout << endl << "Count w/ ints" << endl;
  int ca3[] = {1,2,3,4,5,6,7,1,2};
  cout << "1 = " << count(ca3, 9, 5) << endl;
  cout << "2 = " << count(ca3, 9, 1) << endl;
  int ca4[100];
  for(int i = 0; i < 100; i++){
	  ca4[i] = (i + i %7 ) % 11;
  }
  cout << "8 = " << count(ca4, 100, 5) << endl;
  cout << "9 = " << count(ca4, 100, 1) << endl;

  cout << endl << "Count w/ strings" << endl;
  string a5[] = {"blab", "ha", "ha"};
  cout << "1 = " << count(a5, 3, "blab") << endl;
  cout << "2 = " << count(a5, 3, "ha") << endl;

  cout << endl << "Is Sorted" << endl;
  int a7[] = {1,2,2,3,5,10,100};
  int a8[] = {1,2,3,4,4,5,4};
 // cout << "0 = " << isSorted(a6, 6) << endl;
  cout << "1 = " << isSorted(a1, 5) << endl;
  cout << "1 = " << isSorted(a7, 7) << endl;
  cout << "0 = " << isSorted(a8, 7) << endl;

  return 0;
}

// A sneaky way to allow 1 function to print any typed array, as long as
// the passed array element can be sent to <<.
// The stringstream allows us to 'print' information to a fake output
// stream, and then get the result as a string.  It's a simple way of
// getting a non-string/character into a string.
// Contense of this function will not be tested in this course!
template<typename T>
string print(T array[], int length){
  stringstream out;
  out << '[';
  for(int i = 0; i < length; i++){
    out << array[i];
    if(i != length-1)out << ',';
  }
  out << ']';
  return out.str();
}
