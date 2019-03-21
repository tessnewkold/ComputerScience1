// Tess Newkold
// Lab 9 Part B
// Due: 7 November 2017 
// Ohm's Law 
//      implement a series network that has "unlimited" number of resistors stored in a vector

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class OhmsLaw                           //class is set as "Ohms law"
{
	public:
		void printCircuit(); 
		void addResistor();
	    void changeInputV();
		void deleteResistor();
		void editResistor();
		void groupAddSeries();
		void setVoltage();
	private:
		vector<double> resistors;
		double voltage;
		double checkVals(double input, string text);
};

double OhmsLaw::checkVals(double input, string text) { 
    while (input < 0) {
        cout << "Error - enter a valid value for " << text << "." << endl;
        cin >> input;
    }
    return input;
}

void OhmsLaw::setVoltage() {                //user is prompted to enter the initial voltage 
    cout << "Enter voltage: ";
    cin >> voltage;
    voltage = checkVals(voltage, "voltage");
}

void OhmsLaw::addResistor() {               //user can add a resistor 
    double resistorVal;
    do{
    cout << "Enter a value (press 0 to stop adding resistors) for the resistor: ";
    cin >> resistorVal;
    resistorVal = checkVals(resistorVal, "resistance");
    resistors.push_back(resistorVal);
    }
    while(resistorVal != 0);
}

void OhmsLaw::deleteResistor() {            //user can delete a resistor 
    if (resistors.size() != 0) {
        int resistorLocation;
        cout << "Which resistor do you want to delete? (1-" << resistors.size() << "): ";
        cin >> resistorLocation;
        resistors.erase(resistors.begin() + resistorLocation - 1);
    }
    else
        cout << "There are no resistors to erase";
}

void OhmsLaw::editResistor() {              //user can pick a resistor to chacge to a diff value 
    if (resistors.size() != 0) {
        int resistorLocation; double resistorVal;
        cout << "Which resistor do you want to change? (1-" << resistors.size() << "): ";
        cin >> resistorLocation;
        cout << "What would you like to change the resistor value to? ";
        cin >> resistorVal;
        checkVals(resistorVal, "resistance");
        resistors[resistorLocation - 1] = resistorVal;
    }
    else
        cout << "There are no resistors to change";
}


void OhmsLaw::printCircuit() {          //function to print total resistor info which includes the resistance in ohms, voltage and power. 
    double totalRes = std::accumulate(resistors.begin(),resistors.end(),0);
    double seriesCurrent = voltage / totalRes;
    cout << endl;
    cout << "Total resistance: " << totalRes << " Ohms." << endl;
    cout << "Input voltage: " << voltage << " Volts." << endl;
    cout << "Total current: " << voltage / totalRes << " Amps." << endl;
    cout << "Total power: " << voltage * seriesCurrent << " Watts." << endl;
    
    for (int i = 0; i < resistors.size(); i++) {            //this prints the individual values for each resistor
        cout << endl;
        cout << "Resistor " << i + 1 << " info:" << endl;
        cout << "Resistance: " << resistors[i] << " Ohms" << endl;
        cout << "Voltage: " << seriesCurrent * resistors[i] << " Volts" << endl;
        cout << "Power: " << seriesCurrent * seriesCurrent * resistors[i] << " Watts" << endl;
    }
    
}

int main() {
    OhmsLaw run;                    //declaring the variable "run" in the class "OhmsLaw"
    run.setVoltage();               //main funtion calls a bunch of functions only
    run.addResistor();
    run.deleteResistor();
    run.editResistor();
    run.printCircuit();             //this will print the results for each resistor
    return 0;
}