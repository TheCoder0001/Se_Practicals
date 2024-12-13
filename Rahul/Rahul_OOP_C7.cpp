#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> population_map;

    population_map.insert(pair<string, int>("Goa", 210));
    population_map.insert(pair<string, int>("Bihar", 1270));
    population_map.insert(pair<string, int>("Rajasthan", 412));
    population_map.insert(pair<string, int>("TamilNadu", 712));
    population_map.insert(pair<string, int>("Kerela", 745));
    population_map.insert(pair<string, int>("Maharashtra", 1138));

    map<string, int>::iterator iter;

    cout << "SIZE OF POUPULATION: " << population_map.size() << endl;

    for (iter = population_map.begin(); iter != population_map.end(); ++iter)
    {
        cout << "Population of " << iter->first << ": " << iter->second << " million." << endl;
    }
    char ch = 'y';
    do
    {
        string state;
        cout << "Enter the state to be checked: ";
        cin >> state;

        iter = population_map.find(state);
        if (iter != population_map.end())
        {
            cout << iter->first << "'s population is " << iter->second << " million." << endl;
        }
        else
        {
            cout << "State not found.\n";
        }

        cout << "DO YOU WANT TO CONTINUE YOUR SEARCH? (y/n)\n";
        cin >> ch;
    } while (ch == 'y');

    cout << "Program terminated.";
    return 0;
}
