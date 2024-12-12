/*Write OpenGL Program to draw Sunrise and Sun Set.*/
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>  // For exit()
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;
    int r = 10;
    // Main loop to draw the figure
    while (r <= 50) {
        cleardevice(); // Clear the screen before drawing the next iteration   
        setcolor(WHITE); // Set the color to white for lines
        line(0, 310, 160, 150);    // Draw a line
        line(160, 150, 320, 310);
        line(320, 310, 480, 150);
        line(480, 150, 640, 310);
        line(0, 310, 640, 310);    // Draw another line
        // Draw an arc
        arc(midx, 310, 225, 133, r); // Draw an arc with changing radius
        floodfill(midx, 300, 15);    // Flood fill the area with color 15 (white)
        // Conditional drawing of shapes if the radius exceeds 20
        if (r > 20) {
            setcolor(7);  // Light gray color
            floodfill(2, 2, 15);  // Fill top-left corner (using color 15)
            setcolor(6);  // Yellow color
            floodfill(150, 250, 15);  // Fill bottom-left corner
           	floodfill(550, 250, 15);  // Fill bottom-right corner
            setcolor(2);  // Green color
            floodfill(2, 450, 15);  // Fill bottom-left corner further down
        }
        delay(50);  // Delay for visual effect
        r += 2;     // Increase the radius for the next iteration
    }
    getch();  // Wait for user input
    closegraph(); // Close the graphics window
    return 0;
}

