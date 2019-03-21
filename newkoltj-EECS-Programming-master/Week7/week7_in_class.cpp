#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm> 

const int ARRAY_MAX_SIZE = 50;
const int ARRAY_INITIAL_SIZE = 50;
using namespace std;

void DisplayVector(vector<int> display_me) {                        //function to display vector 
  for(vector<int>::iterator it = display_me.begin(); it != display_me.end(); it++){
  	cout << *it << endl;
  }
}
                                                                    //cant figure out how to make random numbers -- too tired --
int main()
{
    int x = 0;
    vector<int> v_array(ARRAY_INITIAL_SIZE,0);

    cout << "Output vector" << endl;
    for(int i = 0; i  < v_array.size(); i++)
  	    cout << v_array.at(i) << endl;
  	
    double max = *max_element(v_array.begin(), v_array.end());      //will find max number
        cout<<"Max value: "<< max << endl;
        
    double min = *min_element(v_array.begin(), v_array.end());      //will find min number
        cout << "Min Value: " << min << endl;
        
    int sum = 0; for (int i = 0; i < v_array.size(); i++)           //sums all values listed in a vector
        sum += v_array[i];
        cout << "Sum of Values: " << sum << endl;

  	  return 0;
}


