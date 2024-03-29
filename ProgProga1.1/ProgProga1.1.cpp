﻿#include <iostream>
#include "code.h"
#include <vector>
#include <fstream>
#include <string> 
#include <fstream>
#include <boost/algorithm/string.hpp>

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
        while (in.is_open() != true)
        {
            cout << "Input file name \n";
            cin >> filename;
            in.open(filename);
            cout << "Input file can't be opened";            
        }
        while (out.is_open() != true)
        {
            cout << "Output file name \n";
            cin >> filename;
            out.open(filename);
            cout << "Output file can't be opened";
        }
    }
    else
    {
        filename = argv[1];
        in.open(filename);
        filename = argv[2];
        out.open(filename);
        while (in.is_open() != true)
        {
            cout << "Input file name \n";
            cin >> filename;
            in.open(filename);
            cout << "Input file can't be opened";
        }
        while (out.is_open() != true)
        {
            cout << "Output file name \n";
            cin >> filename;
            out.open(filename);
            cout << "Output file can't be opened";
        }
    }
    std::string tmpstr;
    std::getline(in, tmpstr);
    int n = 0;
    try
    {
        n = stoi(tmpstr);
    }
    catch (...)
    {
        cout << "Invalid number of elements";
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        int type, radius, heigth, width, depth, temperature, edge = 0;
        float density = 0.00;
        std::string inputline;
        std::getline(in, inputline);
        std::vector<std::string> splitVector;
        boost::split(splitVector, inputline, boost::is_any_of(" "), boost::token_compress_on);
        splitVector.erase(
            std::remove_if(splitVector.begin(), splitVector.end(),
                [](std::string const& s) { return s.size() == 0; }), splitVector.end());
        int caser = 0;
        try
        {
            if (splitVector.size() > 0)
                caser = stoi(splitVector[0]);
        }
        catch (...)
        {
            cout << "Invalid type of element in line " << i + 2 << endl;;
            exit(0);
        }
        switch(caser)
        {
            case Shape::type::round:
            {
                if (splitVector.size() == 4)
                {
                    Shape tmp;
                    try
                    {
                        density = stof(splitVector[1]);
                        temperature = stoi(splitVector[2]);
                        radius = stoi(splitVector[3]);
                    }
                    catch (...)
                    {
                        cout << "Invalid arguments in line " << i + 2 << endl;
                        exit(0);
                    }
                    tmp.key = Shape::type::round;
                    tmp.mySphere.radius = radius;
                    tmp.mySphere.temperature = temperature;
                    tmp.mySphere.density = density;
                    myElement = addElement(tmp, array);
                    std::cout << "Element number " << i << " is a sphere with radius: ";
                    std::cout << tmp.mySphere.radius << ", temperature ";
                    std::cout << tmp.mySphere.temperature << ", density ";
                    std::cout << tmp.mySphere.density << ", volume ";
                    std::cout << tmp.mySphere.getVolume() << "\n";
                }
                else
                {
                    std::cout << "Incorrect number of arguments \n";
                }
                break;
            }
            case Shape::type::square:
            {
                if (splitVector.size() == 6)
                {
                    Shape tmp;
                    try
                    {
                        density = stof(splitVector[1]);
                        temperature = stoi(splitVector[2]);
                        heigth = stoi(splitVector[3]);
                        width = stoi(splitVector[4]);
                        depth = stoi(splitVector[5]);
                    }
                    catch (...)
                    {
                        cout << "Invalid arguments in line " << i + 2 << endl;
                        exit(0);
                    }
                    tmp.key = Shape::type::square;
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
                }
                else
                {
                    std::cout << "Incorrect number of arguments \n";
                }
                break;
            }
            case Shape::type::tetra:
            {
                if (splitVector.size() == 4)
                {
                    Shape tmp;
                    try
                    {
                        density = stof(splitVector[1]);
                        temperature = stoi(splitVector[2]);
                        heigth = stoi(splitVector[3]);
                    }
                    catch (...)
                    {
                        cout << "Invalid arguments in line " << i + 2 << endl;
                        exit(0);
                    }
                    tmp.key = Shape::type::tetra;
                    tmp.myTetraedr.edge = edge;
                    tmp.myTetraedr.temperature = temperature;
                    tmp.myTetraedr.density = density;
                    myElement = addElement(tmp, array);
                    std::cout << "Element number " << i << " is a tetraedr with edge: ";
                    std::cout << tmp.myTetraedr.edge << ", temperature ";
                    std::cout << tmp.myTetraedr.temperature << ", density ";
                    std::cout << tmp.myTetraedr.density << ", volume ";
                    std::cout << tmp.myTetraedr.getVolume() << "\n";
                }
                else
                {
                    std::cout << "Incorrect number of arguments \n";
                }
                break;
            }
            case Shape::type::empty:
            {
                Shape tmp;
                std::cout << "Element number " << i << " is empty\n";
                tmp.key = Shape::type::empty;
                tmp.myParallelepiped.heigth = 0;
                tmp.myParallelepiped.width = 0;
                tmp.myParallelepiped.depth = 0;
                tmp.myParallelepiped.temperature = 0;
                tmp.myParallelepiped.density = 0.00;
                myElement = addElement(tmp, array);
                break;
            }
            default:
            {
                std::cout << "Wrong type of shape\n";
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
