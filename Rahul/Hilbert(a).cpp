/*
Name: DARSHAN MAYUR SHAH
Class: SE COMP 2nd SHIFT
Subject: Computer Graphics
Roll No: 31
Exam Seat No: S150324244
Assignment B17: Hilbert Curve
*/

#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

// Function to move the cursor based on the direction and step size
void move(int j, int h, int &x, int &y)
{
    if(j==1) 
        y-=h; // Move up
    else if(j==2)
        x+=h; // Move right
    else if(j==3)
        y+=h; // Move down
    else if(j==4)
        x-=h; // Move left

    lineto(x, y); // Draw a line to the new position
    delay(50);    // Introduce a small delay for visualization
}

// Recursive function to generate Hilbert Curve
void hilbert(int d, int r, int u, int l, int i, int h, int &x, int &y)
{
    if(i > 0)
    {
        i--;

        // Recursively draw the Hilbert curve
        hilbert(r, d, l, u, i, h, x, y);
        move(d, h, x, y);

        hilbert(d, r, u, l, i, h, x, y);
        move(r, h, x, y);

        hilbert(d, r, u, l, i, h, x, y);
        move(u, h, x, y);

        hilbert(l, u, r, d, i, h, x, y);
    }
}

int main()
{
    int n, x0 = 50, y0 = 150;
    int x, y, h = 10, u = 1, r = 2, d = 3, l = 4;

    cout << "\nGive the value of n: ";
    cin >> n;

    x = x0;
    y = y0;

    int gd = DETECT, gm = 0;
    initgraph(&gd, &gm, NULL);

    moveto(x, y);         // Move to the starting point
    hilbert(d, r, u, l, n, h, x, y);  // Call the Hilbert function to draw the curve
    delay(5000);          // Pause for visualization

    closegraph();
    return 0;
}