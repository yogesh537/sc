#include <iostream>
#include <string>
using namespace std;

// Base class
class Publication {
protected:
    string title;
    float price;

public:
    // Default Constructor
    Publication() : title("Unknown"), price(0.0f) {}

    // Method to get publication details
    void getData() {
        try {
            cout << "Enter title: ";
            cin.ignore();     //discards certains number of characters from input buffer
            getline(cin,title);
            cout << "Enter price: ";
            cin >> price;
            if (price < 0) {
                throw invalid_argument("Price cannot be negative!");
            }
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
            title = "Unknown";
            price = 0.0f;
        }
    }

    // Method to display publication details
    void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived class for books
class Book : public Publication {
private:
    int pageCount;

public:
    // Default Constructor
    Book() : Publication(), pageCount(0) {}

    // Method to get book details
    void getData() {
        Publication::getData();
        try {
            cout << "Enter page count: ";
            cin >> pageCount;
            if (pageCount < 0) {
                throw invalid_argument("Page count cannot be negative!");
            }
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
            title = "Unknown";
            price = 0.0f;
            pageCount = 0;
        }
    }

    // Method to display book details
    void putData() const {
        Publication::putData();
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class for tapes
class Tape : public Publication {
private:
    float playingTime;

public:
    // Default Constructor
    Tape() : Publication(), playingTime(0.0f) {}

    // Method to get tape details
    void getData() {
        Publication::getData();
        try {
            cout << "Enter playing time (in minutes): ";
            cin >> playingTime;
            if (playingTime < 0) {
                throw invalid_argument("Playing time cannot be negative!");
            }
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
            title = "Unknown";
            price = 0.0f;
            playingTime = 0.0f;
        }
    }

    // Method to display tape details
    void putData() const {
        Publication::putData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for the book:" << endl;
    book.getData();

    cout << "\nEnter details for the tape:" << endl;
    tape.getData();

    cout << "\nDisplaying details of the book:" << endl;
    book.putData();

    cout << "\nDisplaying details of the tape:" << endl;
    tape.putData();

    return 0;
}
