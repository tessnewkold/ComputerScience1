// Tess Newkold
// Lab 9 Part C
// Due: 7 November 2017 
// Ohm's Law 
//      implement a series network that has "unlimited" number of resistors stored in a vector
//      part C is adding the menu option to part B

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class OhmsLaw
{
	public:
		void choice();			     
		void printCircuit(); 
	private:
	    void addResistor();
	    void changeInputV();
		void deleteResistor();
		void editResistor();
		void groupAddSeries();
		vector<double> resistors;
		void setVoltage();
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

void OhmsLaw::setVoltage() {                        //user sets initial voltage
    cout << "Enter voltage: ";
    cin >> voltage;
    voltage = checkVals(voltage, "voltage");
}
    
void OhmsLaw::choice() {                            //user initially pick a choice on which option to pick 
    setVoltage();
    int input;
    do {
    cout << endl << "1 || Add a resistor" << endl;
    cout << "2 || Change input voltage" << endl;
    cout << "3 || Delete a resistor" << endl;
    cout << "4 || Edit a resistor" << endl;
    cout << "5 || Print the current circuit" << endl;
    cout << "6 || Group add a series" << endl; 
    cout << "0 || End program!!" << endl;
    cout << "-----------------------" << endl;
    cout << "Please select an option 1-6 (press 0 to quit): ";
    cin >> input;
    switch (input) {
        case 0: break;
        case 1: addResistor();    break;
        case 2: setVoltage();     break;
        case 3: deleteResistor(); break;
        case 4: editResistor();   break;
        case 5: printCircuit();   break;
        case 6: groupAddSeries(); break;
        default: cout << "Invalid option."; break;
        }
    } while (input != 0);
    cout << "Displaying final circuit parameters." << endl;
    printCircuit();
}

void OhmsLaw::addResistor() {                               //user gets to add resisitors if they pick option 1
    double resistorVal;
    cout << "Enter a value for the resistor: ";
    cin >> resistorVal;
    resistorVal = checkVals(resistorVal, "resistance");
    resistors.push_back(resistorVal);
}

void OhmsLaw::deleteResistor() {                            //user gets to delete resistors if they pick option 2
    if (resistors.size() != 0) {
        int resistorLocation;
        cout << "Which resistor do you want to delete? (1-" << resistors.size() << "): ";
        cin >> resistorLocation;
        resistors.erase(resistors.begin() + resistorLocation - 1);
    }
    else
        cout << "There are no resistors to erase";
}

void OhmsLaw::editResistor() {                              //user can pick a resistor to change by first picking the resistor number to change
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

void OhmsLaw::groupAddSeries() {                            //user can add a bunch of resisitors at once 
    double resistorVal;
    cout << "Keep entering resistor values to add multiple resistors: ";
    do{
    addResistor();
    }
    while(resistorVal != 0);
}
    /*
    while (resistorVal >= 0) {
        cin >> resistorVal;
        if (resistorVal < 0)
            break;
        resistors.push_back(resistorVal);
    }
    */

void OhmsLaw::printCircuit() {                      //this function will print the information for the total resistors and then the individaul ones 
    // total circuit vals:
    double totalRes = std::accumulate(resistors.begin(),resistors.end(),0);
    double seriesCurrent = voltage / totalRes;
    cout << endl;
    cout << "Total resistance: " << totalRes << " Ohms." << endl;
    cout << "Input voltage: " << voltage << " Volts." << endl;
    cout << "Total current: " << voltage / totalRes << " Amps." << endl;
    cout << "Total power: " << voltage * seriesCurrent << " Watts." << endl;
    
    for (int i = 0; i < resistors.size(); i++) {
        cout << endl;
        cout << "Resistor " << i + 1 << " info:" << endl;
        cout << "Resistance: " << resistors[i] << " Ohms." << endl;
        cout << "Voltage: " << seriesCurrent * resistors[i] << " Volts." << endl;
        cout << "Power: " << seriesCurrent * seriesCurrent * resistors[i] << " Watts." << endl;
    }
}

int main() {                                    //main function - make as short as possible 
    OhmsLaw run;
    run.choice();
    return 0;
}