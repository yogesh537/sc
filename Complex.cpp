#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator for addition
    Complex operator + (Complex  other )  {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator for subtraction
    Complex operator - (Complex  other) {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload * operator for multiplication
    Complex operator * ( Complex  other)  {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overload / operator for division
    Complex operator / ( Complex  other)  {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }
    void display(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

};

int main() {
    int a,b;
    cout<<"Enter the first complexnumbers \n";
    cout << "real value :\n";
    cin>>a;
    cout << "imaginary value :\n";
    cin>>b;
    Complex c1(a,b);

    cout << "Enter the second complex number:\n";
    cout << "real value :\n";
    cin>>a;
    cout << "imaginary value :\n";
    cin>>b;
    Complex c2(a,b);

    c1.display();
    c2.display();
    
    // Perform addition
    Complex sum = c1 + c2;
    sum.display();

    // Perform subtraction
    Complex diff = c1 - c2;
    diff.display();

    // Perform multiplication
    Complex prod = c1 * c2;
    prod.display();
    

    // Perform division
    try {
        Complex div = c1 / c2;
        div.display();
    } catch (exception& e) {
        cout << "\nError: " << e.what();
    }

    return 0;
}
