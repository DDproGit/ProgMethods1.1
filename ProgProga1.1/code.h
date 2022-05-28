#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

struct Shape1
{
	enum type { round, square, tetra, empty};
	type key;
	struct Sphere
	{
	public:
		int radius;
		float density;
		int temperature;
		float getVolume()
		{
			//return 4 / 3 * 3.14 * radius * radius * radius;
			return 4 / 3 * 3.14 * radius;
		}
	};
	struct Parallelepiped
	{
	public:
		int heigth;
		int width;
		int depth;
		float density;
		int temperature;
		float getVolume()
		{
			return heigth * width * depth;
		}
	};
	struct Tetraedr
	{
		int edge;
		float density;
		int temperature;
		float getVolume()
		{
			return ((pow(edge, 3) * sqrt(2)) / 12);
		}
	};
	union
	{
		Sphere mySphere;
		Parallelepiped myParallelepiped;
		Tetraedr myTetraedr;
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
void sortElements(HashArray1& myArray);
int getSizeOfVector(int hash, HashArray1& myArray);
void showContainer(std::ostream &out, HashArray1 array);
// Return hash of element
int makeHashOfShape(Shape1 shapeToHash);
void showContainer(std::ostream& out, HashArray1 array);
void showContainer(std::ostream& out, HashArray1 array, int limit);