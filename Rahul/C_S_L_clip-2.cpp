#include <iostream>
#include <graphics.h>
using namespace std;

class CohenSutherlandAlgo
{
private:
    double x1, y1, x2, y2;
    double xMax, yMax, xMin, yMin;
    const int INSIDE = 0; // 0000
    const int LEFT = 1;   // 0001
    const int RIGHT = 2;  // 0010
    const int BOTTOM = 4; // 0100
    const int TOP = 8;    // 1000

public:
    CohenSutherlandAlgo()
    {
        x1 = 0.0;
        x2 = 0.0;
        y1 = 0.0;
        y2 = 0.0;
    }
    void getCoordinates();
    void getClippingRectangle();
    int generateCode(double x, double y);
    void cohenSutherland();
    void drawRectangle();
    void drawLine(double x1, double y1, double x2, double y2, int color);
};

void CohenSutherlandAlgo::getCoordinates()
{
    cout << "\nEnter Coordinates of P1(X1,Y1) of Line Segment : ";
    cout << "\nEnter X1 Coordinate : ";
    cin >> x1;
    cout << "\nEnter Y1 Coordinate : ";
    cin >> y1;
    cout << "\nEnter Coordinates of P2(X2,Y2) of Line Segment : ";
    cout << "\nEnter X2 Coordinate : ";
    cin >> x2;
    cout << "\nEnter Y2 Coordinate : ";
    cin >> y2;
}

void CohenSutherlandAlgo::getClippingRectangle()
{
    cout << "\nEnter the Coordinates of Clipping Rectangle.";
    cout << "\nEnter the X_MAX : ";
    cin >> xMax;
    cout << "\nEnter the Y_MAX : ";
    cin >> yMax;
    cout << "\nEnter the X_MIN : ";
    cin >> xMin;
    cout << "\nEnter the Y_MIN : ";
    cin >> yMin;
}

int CohenSutherlandAlgo::generateCode(double x, double y)
{
    int code = INSIDE; // Initially inside the rectangle
    if (x < xMin)      // Lies to the left of the rectangle
        code |= LEFT;
    else if (x > xMax) // Lies to the right of the rectangle
        code |= RIGHT;
    if (y < yMin)      // Lies below the rectangle
        code |= BOTTOM;
    else if (y > yMax) // Lies above the rectangle
        code |= TOP;
    return code;
}

void CohenSutherlandAlgo::drawLine(double x1, double y1, double x2, double y2, int color)
{
    setcolor(color);
    line(x1, y1, x2, y2);
}

void CohenSutherlandAlgo::drawRectangle()
{
    setcolor(RED);
    rectangle(xMin, yMin, xMax, yMax);
}

void CohenSutherlandAlgo::cohenSutherland()
{
    int code1 = generateCode(x1, y1); // Compute region codes for P1.
    int code2 = generateCode(x2, y2); // Compute region codes for P2.
    bool accept = false;               // Initialize line as outside the rectangular window.
    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within the rectangle.
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside the rectangle, in the same region.
            break;
        }
        else
        {
            // Some segment of the line lies within the rectangle.
            int codeOut;
            double x, y;
            // At least one endpoint lies outside the rectangle, pick it.
            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            // Find intersection point by using formulae:
            // y = y1 + slope * (x - x1)
            // x = x1 + (1 / slope) * (y - y1)
            if (codeOut & TOP)
            {
                // Point is above the clip rectangle
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            }
            else if (codeOut & BOTTOM)
            {
                // Point is below the rectangle
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            }
            else if (codeOut & RIGHT)
            {
                // Point is to the right of rectangle
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            }
            else if (codeOut & LEFT)
            {
                // Point is to the left of rectangle
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            // Intersection point x,y is found.
            // Replace point outside rectangle by intersection point.
            if (codeOut == code1)
            {
                drawLine(x1, y1, x, y, WHITE);
                x1 = x;
                y1 = y;
                code1 = generateCode(x1, y1);
            }
            else
            {
                drawLine(x2, y2, x, y, WHITE);
                x2 = x;
                y2 = y;
                code2 = generateCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout << "Line accepted from "
             << "(" << x1 << ", " << y1 << ")"
             << " to "
             << "(" << x2 << ", " << y2 << ")"
             << endl;
    }
    else
        cout << "Line rejected" << endl;

    // Draw the original line, clipped line, and clipping window
    drawLine(x1, y1, x2, y2, WHITE);    // Original line
	drawLine(x1, y1, x2, y2, RED);      // Clipped line
    drawRectangle();                    // Clipping window
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    CohenSutherlandAlgo c;
    c.getCoordinates();
    c.getClippingRectangle();
    c.cohenSutherland();

    delay(5000);
    closegraph();
    return 0;
}
