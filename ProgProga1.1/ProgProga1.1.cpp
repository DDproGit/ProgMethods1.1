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
        int type, radius, heigth, width, depth, temperature, edge = 0;
        float density = 0.00;
        in >> type;
        switch(type)
        {
            case Shape1::type::round:
            {
                Shape1 tmp;
                in >> density;
                in >> temperature;
                in >> radius;
                tmp.key = Shape1::type::round;
                tmp.mySphere.radius = radius;
                tmp.mySphere.temperature = temperature;
                tmp.mySphere.density = density;
                myElement = addElement(tmp, array);
                std::cout << "Element number " << i << " is a sphere with radius: ";
                std::cout << tmp.mySphere.radius << ", temperature ";
                std::cout << tmp.mySphere.temperature << ", density ";
                std::cout << tmp.mySphere.density << ", volume ";
                std::cout << tmp.mySphere.getVolume() << "\n";
                break;
            }
            case Shape1::type::square:
            {
                Shape1 tmp;
                in >> density;
                in >> temperature;
                in >> heigth >> width >> depth;
                tmp.key = Shape1::type::square;
                tmp.myParallelepiped.heigth = heigth;
                tmp.myParallelepiped.width = width;
                tmp.myParallelepiped.depth = depth;
                tmp.myParallelepiped.temperature = temperature;
                tmp.myParallelepiped.density = density;
                myElement = addElement(tmp, array);
                std::cout << "Element number " << i << " is a parallelepiped with edges: ";
                std::cout << tmp.myParallelepiped.heigth << ", ";
                std::cout << tmp.myParallelepiped.width << ", ";
                std::cout << tmp.myParallelepiped.depth << ", temperature ";
                std::cout << tmp.myParallelepiped.temperature << ", density ";
                std::cout << tmp.myParallelepiped.density << ", volume ";
                std::cout << tmp.myParallelepiped.getVolume() << "\n";
                break;
            }
            case Shape1::type::tetra:
            {
                Shape1 tmp;
                in >> density;
                in >> temperature;
                in >> edge;
                tmp.key = Shape1::type::tetra;
                tmp.myTetraedr.edge = edge;
                tmp.myTetraedr.temperature = temperature;
                tmp.myTetraedr.density = density;
                myElement = addElement(tmp, array);
                std::cout << "Element number " << i << " is a tetraedr with edge: ";
                std::cout << tmp.myTetraedr.edge << ", temperature ";
                std::cout << tmp.myTetraedr.temperature << ", density ";
                std::cout << tmp.myTetraedr.density << ", volume ";
                std::cout << tmp.myTetraedr.getVolume() << "\n";
                break;
            }
            case Shape1::type::empty:
            {
                Shape1 tmp;
                std::cout << "Element number " << i << " is empty\n";
                tmp.key = Shape1::type::empty;
                tmp.myParallelepiped.heigth = 0;
                tmp.myParallelepiped.width = 0;
                tmp.myParallelepiped.depth = 0;
                tmp.myParallelepiped.temperature = 0;
                tmp.myParallelepiped.density = 0.00;
                myElement = addElement(tmp, array);
                break;
            }
        }
    }
    std::cout << "Full - 0, no spheres - 1, no parallelepipeds - 2, no tetras - 3: ";
    int limit = 0;
    cin >> limit;
    showContainer(cout, array, limit);
    showContainer(out,array);
    return 0;
}
