#include<iostream>
#include<graphics.h>
#include<math.h>
#include<cstdlib>
using namespace std;

typedef struct coordinate {
    int x, y;
    char code[4];  // Codes for left, right, top, bottom (in that order)
} PT;

void drawwindow();
void drawline(PT p1, PT p2);
PT setcode(PT p);
int visibility(PT p1, PT p2);
PT resetendpt(PT p1, PT p2);

int main() {
    int gd = DETECT, gm;
    PT p1, p2, p3, p4, ptemp;
    
    cout << "\nEnter (x1, y1) & (x2, y2)\n";
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    
    initgraph(&gd, &gm, NULL);
    drawwindow();
    delay(500);
    drawline(p1, p2);
    delay(500);
    cleardevice();
    delay(500);
    
    p1 = setcode(p1);
    p2 = setcode(p2);
    
    int v = visibility(p1, p2);
    delay(500);
    
    switch (v) {
    case 0:
        drawwindow();
        delay(500);
        drawline(p1, p2);
        break;
    case 1:
        drawwindow();
        delay(500);
        break;
    case 2:
        p3 = resetendpt(p1, p2);
        p4 = resetendpt(p2, p1);
        drawwindow();
        delay(500);
        drawline(p3, p4);
        break;
    }
    
    delay(5000);
    closegraph();
    return 0;
}

void drawwindow() {
    line(150, 100, 450, 100);  // Top edge
    line(450, 100, 450, 350);  // Right edge
    line(450, 350, 150, 350);  // Bottom edge
    line(150, 350, 150, 100);  // Left edge
}

void drawline(PT p1, PT p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

PT setcode(PT p) {
    PT ptemp;
    
    // Top
    if (p.y < 100)
        ptemp.code[0] = '1';
    else
        ptemp.code[0] = '0';
    
    // Bottom
    if (p.y > 350)
        ptemp.code[1] = '1';
    else
        ptemp.code[1] = '0';
    
    // Right
    if (p.x > 450)
        ptemp.code[2] = '1';
    else
        ptemp.code[2] = '0';
    
    // Left
    if (p.x < 150)
        ptemp.code[3] = '1';
    else
        ptemp.code[3] = '0';
    
    ptemp.x = p.x;
    ptemp.y = p.y;
    return ptemp;
}

int visibility(PT p1, PT p2) {
    int i, flag = 0;

    // If both points are inside the window
    for (i = 0; i < 4; i++) {
        if ((p1.code[i] != '0') || (p2.code[i] != '0'))
            flag = 1;
    }
    if (flag == 0)
        return 0; // Fully inside
    
    // If both points have the same outcode (both outside)
    for (i = 0; i < 4; i++) {
        if ((p1.code[i] == p2.code[i]) && (p1.code[i] == '1'))
            flag = 0;
    }
    if (flag == 0)
        return 1; // Completely outside
    
    return 2; // Partially inside
}

PT resetendpt(PT p1, PT p2) {
    PT temp;
    int x, y, i;
    float m, k;

    // For left boundary (x = 150)
    if (p1.code[3] == '1')
        x = 150;
    // For right boundary (x = 450)
    else if (p1.code[2] == '1')
        x = 450;

    // Clip the line with either left or right boundary
    if ((p1.code[3] == '1') || (p1.code[2] == '1')) {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        k = (float)p1.y + (m * (x - p1.x));
        temp.y = k;
        temp.x = x;
        for (i = 0; i < 4; i++)
            temp.code[i] = p1.code[i];
        
        // If the new point is inside the window
        if (temp.y <= 350 && temp.y >= 100)
            return temp;
    }

    // For top boundary (y = 100)
    if (p1.code[0] == '1')
        y = 100;
    // For bottom boundary (y = 350)
    else if (p1.code[1] == '1')
        y = 350;

    // Clip the line with either top or bottom boundary
    if ((p1.code[0] == '1') || (p1.code[1] == '1')) {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        k = (float)p1.x + (float)(y - p1.y) / m;
        temp.x = k;
        temp.y = y;
        for (i = 0; i < 4; i++)
            temp.code[i] = p1.code[i];

        return temp;
    }

    // If no clipping is needed, return original point
    return p1;
}

