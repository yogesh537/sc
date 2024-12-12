#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class KochCurve {
public:
    void koch(int it, int x1, int y1, int x5, int y5) {
        int x2, y2, x3, y3, x4, y4;
        int dx, dy;
        if (it == 0) {
            line(x1, y1, x5, y5);  // Draw the line when iterations reach 0
        } else {
            delay(10);  // Small delay for visualization effect
            dx = (x5 - x1) / 3;  // Divide the line into 3 parts
            dy = (y5 - y1) / 3;

            // Calculate the intermediate points
            x2 = x1 + dx;
            y2 = y1 + dy;

            // Calculating the peak of the triangle
            x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6);
            y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);

            x4 = 2 * dx + x1;
            y4 = 2 * dy + y1;

            // Recursive calls to draw the smaller Koch curves
            koch(it - 1, x1, y1, x2, y2);
            koch(it - 1, x2, y2, x3, y3);
            koch(it - 1, x3, y3, x4, y4);
            koch(it - 1, x4, y4, x5, y5);
        }
    }
};

int main() {
    KochCurve k;
    int it;
    
    // Take user input for number of iterations
    cout << "Enter Number of Iterations: " << endl;
    cin >> it;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Initialize graphics mode

    // Draw the 3 sides of the Koch triangle fractal
    k.koch(it, 150, 20, 20, 280);
    k.koch(it, 280, 280, 150, 20);
    k.koch(it, 20, 280, 280, 280);

    getch();  // Wait for the user to press a key
    closegraph();  // Close the graphics window
    return 0;
}

