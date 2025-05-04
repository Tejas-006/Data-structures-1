/*2. Write a C++ menu-driven program that calculates and displays the area of a square, cube, rectangle, and cuboid. 
Consider length as the side value for the square and cuboid. Identify proper data members and member functions. 
Design and create an appropriate class for the given scenario.  Maintain proper boundary conditions and follow 
coding best practices. The menus are as follows,
 a) Square
 b) Cube
 c) Rectangle
 d) Cuboid
 e) Exit*/


#include <iostream>
using namespace std;

class shapes
{
public:
    int cube(int side)
    {
        return 6 * (side * side);
    }

    int cuboid(int l, int b, int h)
    {
        return 2 * ((l * b) + (b * h) + (h * l));
    }

    int rectangle(int l, int b)
    {
        return l * b;
    }

    int square(int side)
    {
        return side * side;
    }
};

int main()
{
    int choice;
    shapes shape;  // Creating an object of the class

    cout << "Select the shape whose area is required:\n";
    cout << "1. Square\n2. Cube\n3. Rectangle\n4. Cuboid\n5. Exit\n";
    cin >> choice;

    if (choice == 1)
    {
        int side;
        cout << "Enter the side: ";
        cin >> side;
        cout << "Area of the square is: " << shape.square(side) << endl;
    }
    else if (choice == 2)
    {
        int side;
        cout << "Enter the side: ";
        cin >> side;
        cout << "Surface area of the cube is: " << shape.cube(side) << endl;
    }
    else if (choice == 3)
    {
        int l, b;
        cout << "Enter the length and breadth: ";
        cin >> l >> b;
        cout << "Area of the rectangle is: " << shape.rectangle(l, b) << endl;
    }
    else if (choice == 4)
    {
        int l, b, h;
        cout << "Enter the length, breadth, and height: ";
        cin >> l >> b >> h;
        cout << "Surface area of the cuboid is: " << shape.cuboid(l, b, h) << endl;
    }
    else
    {
        cout << "Exiting program...\n";
    }

    return 0;
}
