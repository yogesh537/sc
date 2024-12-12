#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;

    static int studentCount; // Static member variable

public:
    // Constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        studentClass = "None";
        division = 'X';
        dob = "00-00-0000";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "0000000000";
        drivingLicenseNumber = "Unknown";
        studentCount++;
    }

    // Parameterized Constructor
    Student(string name, int roll, string cls, char div, string dob, string bg, string addr, string tel, string dl) {
        this->name = name;
        this->rollNumber = roll;
        this->studentClass = cls;
        this->division = div;
        this->dob = dob;
        this->bloodGroup = bg;
        this->contactAddress = addr;
        this->telephoneNumber = tel;
        this->drivingLicenseNumber = dl;
        studentCount++;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicenseNumber = s.drivingLicenseNumber;
        studentCount++;
    }

    // Static Member Function
    static int getStudentCount() {
        return studentCount;
    }

    // Member Function to Display Student Details
    void display() {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << rollNumber;
        cout << "\nClass: " << studentClass;
        cout << "\nDivision: " << division;
        cout << "\nDate of Birth: " << dob;
        cout << "\nBlood Group: " << bloodGroup;
        cout << "\nContact Address: " << contactAddress;
        cout << "\nTelephone Number: " << telephoneNumber;
        cout << "\nDriving License Number: " << drivingLicenseNumber << endl;
    }

    // Friend Class Declaration
    friend class Admin;
};

// Initialize Static Member
int Student::studentCount = 0;

class Admin {
public:
    void updateAddress(Student &s, const string &newAddress) {
        s.contactAddress = newAddress;
    }
};

int main() {
    try {
        // Dynamic Memory Allocation
        Student *s1 = new Student("John Doe", 101, "10th", 'A', "01-01-2005", "O+", "123 Street, City", "9876543210", "DL12345");
        Student s2("Jane Smith", 102, "10th", 'B', "15-05-2005", "A+", "456 Avenue, City", "9876509876", "DL54321");

        cout << "\nStudent Information System";

        cout << "\nDetails of Student 1:";
        s1->display();

        cout << "\nDetails of Student 2:";
        s2.display();

        // Updating Address Using Friend Class
        Admin admin;
        admin.updateAddress(*s1, "789 New Street, New City");
        cout << "\nUpdated Address for Student 1:";
        s1->display();

        // Displaying Student Count
        cout << "\nTotal Students: " << Student::getStudentCount() << endl;

        // Freeing Memory
        delete s1;
        cout << "\nTotal Students after deletion: " << Student::getStudentCount() << endl;

    } catch (bad_alloc &e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
    } catch (...) {
        cerr << "An unexpected error occurred." << endl;
    }

    return 0;
}
