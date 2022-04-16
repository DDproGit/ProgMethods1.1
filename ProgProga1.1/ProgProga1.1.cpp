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
        int type, radius, heigth, width, depth, temperature = 0;
        in >> type;
        switch(type)
        {
            case Shape1::type::round:
            {
                Shape1 tmp;
                in >> radius >> temperature;
                tmp.key = Shape1::type::round;
                tmp.mySphere.radius = radius;
                tmp.mySphere.temperature = temperature;
                myElement = addElement(tmp, array);
                cout << "Element number " << i << ": ";
                cout << tmp.mySphere.radius << ", ";
                cout << tmp.mySphere.temperature << ". That's a sphere.\n";
                break;
            }
            case Shape1::type::square:
            {
                Shape1 tmp;
                in >> heigth >> width >> depth >> temperature;
                tmp.key = Shape1::type::square;
                tmp.myParallelepiped.heigth = heigth;
                tmp.myParallelepiped.width = width;
                tmp.myParallelepiped.depth = depth;
                tmp.myParallelepiped.temperature = temperature;
                myElement = addElement(tmp, array);
                cout << "Element number " << i << ": ";
                cout << tmp.myParallelepiped.heigth << ", ";
                cout << tmp.myParallelepiped.width << ", ";
                cout << tmp.myParallelepiped.depth << ", ";
                cout << tmp.myParallelepiped.temperature << ". That's a parallelepiped.\n";
                break;
            }
            case Shape1::type::empty:
            {
                Shape1 tmp;
                cout << "Element number " << i << " is empty\n";
                tmp.key = Shape1::type::empty;
                tmp.myParallelepiped.heigth = 0;
                tmp.myParallelepiped.width = 0;
                tmp.myParallelepiped.depth = 0;
                tmp.myParallelepiped.temperature = 0;
                myElement = addElement(tmp, array);
                break;
            }
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
                    out << tmp.mySphere.radius << " ";
                    out << " and temperature: ";
                    out << tmp.mySphere.temperature << "\n";
                    counter++;
                }
                else if (tmp.key == Shape1::type::square)
                    {
                        out << "Element number " << counter << " is a parallelepiped with edges: ";
                        out << tmp.myParallelepiped.heigth << ", ";
                        out << tmp.myParallelepiped.width << ", ";
                        out << tmp.myParallelepiped.depth << " and temperature:";
                        out << tmp.myParallelepiped.temperature << "\n";
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
    out << "Total number of objects: " << counter << "\n";
    return 0;
}
