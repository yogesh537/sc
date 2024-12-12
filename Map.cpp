#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map where key is state name and value is population
    map<string, long long> statePopulation;

    // Add data to the map (state names and populations)
    statePopulation["California"] = 39538223;
    statePopulation["Texas"] = 29145505;
    statePopulation["Florida"] = 21538187;
    statePopulation["New York"] = 20201249;
    statePopulation["Pennsylvania"] = 13002700;

    // Prompt the user for a state name
    string state;
    cout << "Enter the name of a state: ";
    getline(cin, state);

    // Search for the state in the map and return the population
    auto it = statePopulation.find(state);
    if (it != statePopulation.end()) {
        cout << "The population of " << state << " is " << it->second << endl;
    } else {
        cout << "State not found in the database." << endl;
    }

    return 0;
}
