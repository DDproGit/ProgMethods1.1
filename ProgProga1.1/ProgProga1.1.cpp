#include <iostream>
#include "code.h"
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    string filename;
    pair <int, int> myElement;
    HashArray1 array;
    ifstream in;
    ofstream out;
    if (argc != 3)
    {
        cout << "Input file name \n";
        cin >> filename;
        in.open(filename);
        cout << "Output file name \n";
        cin >> filename;
        out.open(filename);
    }
    else
    {
        filename = argv[1];
        in.open(filename);
        filename = argv[2];
        out.open(filename);
    }
    int n = 0;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        int radius, heigth, width, depth = 0;
        in >> radius >> heigth;
        in >> width >> depth;
        if (radius == 0)
            if (heigth != 0)
            {
                Shape1 tmp;
                tmp.key = Shape1::type::square;
                tmp.myParallelepiped.heigth = heigth;
                tmp.myParallelepiped.width = width;
                tmp.myParallelepiped.depth = depth;
                myElement = addElement(tmp, array);
                cout << "Element number " << i << ": ";
                cout << tmp.myParallelepiped.heigth << ", ";
                cout << tmp.myParallelepiped.width << ", ";
                cout << tmp.myParallelepiped.depth << ". That's a parallelepiped.\n";
            }
            else
            {
                Shape1 tmp;
                cout << "Element number " << i << " is empty\n";
                tmp.key = Shape1::type::empty;
                tmp.myParallelepiped.heigth = 0;
                tmp.myParallelepiped.width = 0;
                tmp.myParallelepiped.depth = 0;
                myElement = addElement(tmp, array);
            }
        else
            if (heigth != 0)
            {
                cout << "Element number " << i << " is broken. It has both radius and heigth\n";
            }
            else
            {
                Shape1 tmp;
                tmp.key = Shape1::type::round;
                tmp.mySphere.radius = radius;
                myElement = addElement(tmp, array);
                cout << "Element number " << i << ": ";
                cout << tmp.mySphere.radius << ". That's a sphere.\n";
            }
    }
    int counter = 0;
    for (int i = 0; i < 30; i++)
    {
        Shape1 tmp;
        if (getSizeOfVector(i, array) != 0)
        {
            int size = getSizeOfVector(i, array);
            for (int j = 0; j < size; j++)
            {
                tmp = getElement(i, j, array);
                if (tmp.key == Shape1::type::round)
                {
                    out << "Element number " << counter << " is a sphere with radius: ";
                    out << tmp.mySphere.radius << "\n";
                    counter++;
                }
                else if (tmp.key == Shape1::type::square)
                    {
                        out << "Element number " << counter << " is a parallelepiped with edges: ";
                        out << tmp.myParallelepiped.heigth << ", ";
                        out << tmp.myParallelepiped.width << ", ";
                        out << tmp.myParallelepiped.depth << "\n";
                        counter++;
                    }
                else if (tmp.key == Shape1::type::empty)
                {
                    out << "Element number " << i << " is empty\n";
                    counter++;
                }
            }
        }
    }
    return 0;
}
