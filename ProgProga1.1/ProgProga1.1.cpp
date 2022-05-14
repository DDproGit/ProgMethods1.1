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
    std::string tmpstr;
    std::getline(in, tmpstr);
    for (int i = 0; i < n; i++)
    {
        int type, radius, heigth, width, depth, temperature, edge = 0;
        float density = 0.00;
        std::string inputline;
        std::getline(in, inputline);
        std::vector<std::string> split_vector;
        boost::split(split_vector, inputline, boost::is_any_of(" "), boost::token_compress_on);
        split_vector.erase(
            std::remove_if(split_vector.begin(), split_vector.end(),
                [](std::string const& s) { return s.size() == 0; }), split_vector.end());
        switch(stoi(split_vector[0]))
        {
            case Shape1::type::round:
            {
                if (split_vector.size() == 4)
                {
                    Shape1 tmp;
                    density = stof(split_vector[1]);
                    temperature = stoi(split_vector[2]);
                    radius = stoi(split_vector[3]);
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
                }
                else
                {
                    std::cout << "Incorrect number of arguments \n";
                }
                break;
            }
            case Shape1::type::square:
            {
                if (split_vector.size() == 6)
                {
                    Shape1 tmp;
                    density = stof(split_vector[1]);
                    temperature = stoi(split_vector[2]);
                    heigth = stoi(split_vector[3]);
                    width = stoi(split_vector[4]);
                    depth = stoi(split_vector[5]);
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
                }
                else
                {
                    std::cout << "Incorrect number of arguments \n";
                }
                break;
            }
            case Shape1::type::tetra:
            {
                if (split_vector.size() == 4)
                {
                    Shape1 tmp;
                    density = stof(split_vector[1]);
                    temperature = stoi(split_vector[2]);
                    heigth = stoi(split_vector[3]);
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
                }
                else
                {
                    std::cout << "Incorrect number of arguments \n";
                }
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
