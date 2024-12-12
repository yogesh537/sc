#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "example.txt";
    string dataToWrite = "This is a sample text written to the file.";
    string readData;

    // Create and write to the file
    ofstream outFile(filename); // Open file in write mode
    cout << "Writing to the file: " << dataToWrite << endl;
    outFile << dataToWrite; // Write data to the file
    outFile.close(); // Close the file after writing

    // Open the file again to read from it
    ifstream inFile(filename); // Open file in read mode
    cout << "\nReading from the file:" << endl;
    while (getline(inFile, readData)) { // Read line by line
        cout << readData << endl;
    }
    inFile.close(); // Close the file after reading
    return 0;
}
