#pragma once
#include <vector>
#include <iostream>

struct Shape1
{
	enum type { round, square, empty, tetra };
	type key;
	struct sphere
	{
	public:
		int radius;
		int temperature;
		int getVolume()
		{
			return 4 / 3 * 3.14 * radius * radius * radius;
		}
	};
	struct parallelepiped
	{
	public:
		int heigth;
		int width;
		int depth;
		int temperature;
		int getVolume()
		{
			return heigth * width * depth;
		}
	};
	struct tetraedr
	{
		int getVolume()
		{
			return (pow(edge,3)*sqrt(2)/12);
		}
		int edge;
	};
	union
	{
		sphere mySphere;
		parallelepiped myParallelepiped;
		tetraedr myTetraedr;
	};
	Shape1();
};


struct HashArray1
{
	std::vector<Shape1> arrayOfVectorsOfElements[30];
};

// Adds element to array and return hash and place
std::pair <int, int> addElement(Shape1 newElement, HashArray1& myArray);
// Delete element from array by hash and place
void removeElement(int hash, int place, HashArray1& myArray);
// Replace element with this hash and place with new 
void replaceElement(int hash, int place, Shape1 newShape, HashArray1& myArray);
// Return element by hash and place
Shape1 getElement(int hash, int place, HashArray1& myArray);
int getSizeOfVector(int hash, HashArray1& myArray);
// Return hash of element
int makeHashOfShape(Shape1 shapeToHash);
