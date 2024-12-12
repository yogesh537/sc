#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

// Class to represent a point
class Point {
public:
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    // Operator overloading for translation
    Point operator + (const Point &p) {
        return Point(x + p.x, y + p.y);
    }
    // Operator overloading for scaling
    Point operator * (const int factor) {
        return Point(x * factor, y * factor);
    }
    // Operator overloading for rotation
    Point operator * (const float angle) {
        float t = angle * (3.14 / 180);  // Convert angle to radians
        int newX = round(x * cos(t) - y * sin(t));
        int newY = round(x * sin(t) + y * cos(t));
        return Point(newX, newY);
    }
    // Function to draw the point
    void draw() {
        putpixel(x, y, 4);  // Red color (you can choose other colors)
    }
};
int main() {
    int gm, gd = DETECT;
    int x1, y1, x2, y2, x3, y3, sx, sy, xt, yt, r, choice;
    Point p1, p2, p3;
    // Getting the coordinates of the triangle
    cout << "\tProgram for basic transformations (Scaling, Translation, Rotation):";
    cout << "\n\tEnter the points of the triangle:" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // Initialize the graphics window
    initgraph(&gd, &gm, NULL);
    // Create the points
    p1 = Point(x1, y1);
    p2 = Point(x2, y2);
    p3 = Point(x3, y3);
    // Draw the original triangle
    line(p1.x, p1.y, p2.x, p2.y);
    line(p2.x, p2.y, p3.x, p3.y);
    line(p3.x, p3.y, p1.x, p1.y);
    // Menu for transformations
    while (true) {
        cout << "\n1. Translation\n2. Rotation\n3. Scaling\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:  // Translation
                cout << "\nEnter the translation factors (xt, yt): ";
                cin >> xt >> yt;
                initgraph(&gd, &gm, NULL);  // Re-initialize graph to clear old drawing
                // Translate the points
                p1 = p1 + Point(xt, yt);
                p2 = p2 + Point(xt, yt);
                p3 = p3 + Point(xt, yt);
                // Draw the translated triangle
                line(p1.x, p1.y, p2.x, p2.y);
                line(p2.x, p2.y, p3.x, p3.y);
                line(p3.x, p3.y, p1.x, p1.y);
                break;
            case 2:  // Rotation
                cout << "\nEnter the angle of rotation (in degrees): ";
                cin >> r;
                initgraph(&gd, &gm, NULL);
                // Convert angle to radians and rotate the points
                p1 = p1 * r;
                p2 = p2 * r;
                p3 = p3 * r;
                // Draw the rotated triangle
                line(p1.x, p1.y, p2.x, p2.y);
                line(p2.x, p2.y, p3.x, p3.y);
                line(p3.x, p3.y, p1.x, p1.y);
                break;
            case 3:  // Scaling
                cout << "\nEnter the scaling factors (sx, sy): ";
                cin >> sx >> sy;
                initgraph(&gd, &gm, NULL);
                // Scale the points
                p1 = p1 * sx;
                p2 = p2 * sx;
                p3 = p3 * sx;
                // Draw the scaled triangle
                line(p1.x, p1.y, p2.x, p2.y);
                line(p2.x, p2.y, p3.x, p3.y);
                line(p3.x, p3.y, p1.x, p1.y);
                break;
            case 4:  // Exit
                closegraph();
                return 0;
            default:
                cout << "\nInvalid choice! Please enter a valid option." << endl;
        }
    }
    return 0;
}

