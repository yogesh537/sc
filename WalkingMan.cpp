/*Write C++ program to draw man walking in the rain with an umbrella.Apply the
concept of polymorphism*/
#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h> // Delay function
using namespace std;

class walkingman
{
    int rhx, rhy;
public:
    void draw(int);        // Drawing the walking man animation
    void draw(int, int);   // Drawing random text at specific location
};

void walkingman::draw(int i)
{
    line(20, 380, 580, 380); // Draw the ground
    if (i % 2) {
        // Walking position for one leg
        line(25 + i, 380, 35 + i, 340);    // Left leg up
        line(45 + i, 380, 35 + i, 340);    // Right leg up
        line(35 + i, 310, 25 + i, 330);    // Left leg down
        delay(20);  // Delay for animation effect
    } else {
        // Walking position for the other leg
        line(35 + i, 340, 35 + i, 310);    // Left leg down
        line(35 + i, 310, 40 + i, 330);    // Right leg down
        delay(20);  // Delay for animation effect
    }

    line(35 + i, 340, 35 + i, 310);   // Main body part of the walking man
    circle(35 + i, 300, 10);           // Head
    line(35 + i, 310, 50 + i, 330);    // Right arm
    line(50 + i, 330, 50 + i, 280);    // Right arm line
    line(15 + i, 280, 85 + i, 280);    // Body line
    arc(50 + i, 280, 0, 180, 35);      // Body arc
    arc(55 + i, 330, 180, 360, 5);     // Leg arc for motion effect
}

void walkingman::draw(int x, int y)
{
    int j;
    rhx = x; 
    rhy = y;
    for (j = 0; j < 100; j++) {
        // Random text on screen
        outtextxy(rand() % rhx, rand() % (rhy - 50), "|");
        setcolor(WHITE);  // Text color
    }
}

int main()
{
    int gd = DETECT, gm;
    int rhx, rhy, j, i;
    walkingman obj;

    initgraph(&gd, &gm, "");
    for (i = 0; i < 500; i++) {
        obj.draw(i);  // Animate walking man
        rhx = getmaxx();
        rhy = getmaxy();
        obj.draw(rhx, rhy);  // Display random text on the screen
        delay(150);  // Delay to create walking effect
        cleardevice();  // Clear the screen for next frame
    }

    getch();  // Wait for user input before closing the window
    closegraph();  // Close the graphics window
    return 0;
}
