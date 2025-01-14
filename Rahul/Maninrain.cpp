#include<iostream>
#include<graphics.h>
#include<math.h>

void man()
{    
    int i, j, x, y;
    
    // Loop to move the man across the screen
    for(i = 0; i < getmaxx() - 140; i++)
    {
        delay(5);
        cleardevice();  // Clear the previous frame

        // Draw the ground
        line(0, 450, getmaxx(), 450);

        // Draw the man
        rectangle(10 + i, 400, 50 + i, 340);    // Body
        line(15 + i, 400, 45 + i, 450);         // Arms
        line(45 + i, 400, 15 + i, 450);
        circle(30 + i, 330, 10);                // Head
        line(30 + i, 350, 70 + i, 390);         // Right leg
        line(50 + i, 370, 70 + i, 350);         // Left leg
        line(70 + i, 350, 70 + i, 310);         // Umbrella handle
        line(0 + i, 310, 140 + i, 310);         // Umbrella top
        arc(70 + i, 310, 180, 0, 70);           // Umbrella curve

        // Draw random raindrops
        for(j = 0; j < 100; j++)
        {
            x = rand() % getmaxx();
            y = rand() % getmaxy();
            line(x, y, x + 4, y + 4);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    man();  // Call the function to animate the man

    delay(10000);  // Pause for 10 seconds
    closegraph();  // Close the graphics window

    return 0;
}
