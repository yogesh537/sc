#include <iostream>
#include <vector>
#include <algorithm>  // for sort, find_if
#include <string>
using namespace std;

struct Personnel {
    int id;
    string name;
    int age;

    // Constructor to easily initialize Personnel
    Personnel(int id, string name, int age) : id(id), name(name), age(age) {}
};

// Function to print personnel information
void printPersonnel(const vector<Personnel>& personnel) {
    for (const auto& p : personnel) {
        cout << "ID: " << p.id << ", Name: " << p.name << ", Age: " << p.age << endl;
    }
}

// Comparator function to sort by age
bool compareByAge(const Personnel& a, const Personnel& b) {
    return a.age < b.age;  // Ascending order
}

int main() {
    vector<Personnel> personnel;

    // Adding personnel records
    personnel.push_back(Personnel(1, "John Doe", 28));
    personnel.push_back(Personnel(2, "Jane Smith", 35));
    personnel.push_back(Personnel(3, "Alice Johnson", 22));
    personnel.push_back(Personnel(4, "Bob Brown", 30));

    cout << "Personnel Information (Unsorted):" << endl;
    printPersonnel(personnel);

    // Sorting personnel by age
    sort(personnel.begin(), personnel.end(), compareByAge);

    cout << "\nPersonnel Information (Sorted by Age):" << endl;
    printPersonnel(personnel);

    // Searching for a personnel by name
    string searchName = "Alice Johnson";
    auto it = find_if(personnel.begin(), personnel.end(), [&](const Personnel& p) {
        return p.name == searchName;
    });

    if (it != personnel.end()) {
        cout << "\nFound Personnel: ID: " << it->id << ", Name: " << it->name << ", Age: " << it->age << endl;
    } else {
        cout << "\nPersonnel not found." << endl;
    }

    return 0;
}
