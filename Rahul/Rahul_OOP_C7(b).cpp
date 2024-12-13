#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Define and initialize a map to store state populations
    map<string, int> statePopulations{
        {"California", 39512223},
        {"Texas", 28995881},
        {"Florida", 21477737},
        {"New York", 19453561},
        {"Pennsylvania", 12801989},
        // Add more states and populations as needed
    };
	
	cout<< "SIZE OF POUPULATION: "<< statePopulations.size()<< endl;
	
	for(auto iter = statePopulations.begin(); iter != statePopulations.end(); ++iter)
	{
		cout<< "Population of "<< iter->first<< ": "<< iter->second<< endl;
	}
	
    // Prompt the user to enter the name of a state
    cout << "Enter the name of a state: ";
    string stateName;
    getline(cin, stateName);

    // Search for the state in the map
    auto iter = statePopulations.find(stateName);

    // Check if the state was found
    if (iter != statePopulations.end()) {
        // State found, print the population
        cout << "Population of " << stateName << ": " << iter->second << " million." << endl;
    } else {
        // State not found
        cout << "State not found in the map." << endl;
    }

    return 0;
}
