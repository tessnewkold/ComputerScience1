// Tess Newkold
// Lab 9 Part A
// Due: 7 November 2017 
// Ohm's Law 
//       Program that has one resistor, and a voltage source.
//       Calculate the current and power dissipation based on these 2 values.

#include <iostream> 

using namespace std;

struct node{
    double resistance;
    double newcurrent;
    double voltageAcross;
    double powerAcross;
    double current;
};

void powerAcross(node & power){
     power.powerAcross = power.voltageAcross * power.newcurrent;//calculates the power given the voltage and current that was calulated in the other function
}

void current(node & toView){
    toView.newcurrent = toView.voltageAcross/toView.resistance; // will callculate the currect with the voltage and resistance given
}

void DisplayCircuitParameters(node display){                    //this funtion will display all of the informtaion calculated
   double newcurrent;
    node N1;
    cout << endl;
    cout << "Circuit Parameters" << endl;
    cout << "\tResistance: " << display.resistance << endl;
    cout << "\tVoltage: " << display.voltageAcross << endl;
    cout << "\tCurrent: " << display.newcurrent << endl;
    cout << "\tPower: " << display.powerAcross << endl;
    return;
}

int main(){
    node N1;

    cout << "Enter Voltage: ";
    cin >> N1.voltageAcross;                        //user inputs voltage
    
    cout << "Resistor: ";
    cin >> N1.resistance;                           //user inputs resistance
    
    current(N1);                                    //calls on current function
    powerAcross(N1);                                //calls on power function
    DisplayCircuitParameters(N1);                   //calls to display all information
    return 0;
}