#pragma once
#include <vector>
#include <iostream>

struct Shape1
{
	enum type { round, square, empty };
	type key;
	struct sphere
	{
		int radius;
	};
	struct parallelepiped
	{
		int heigth;
		int width;
		int depth;
	};
	union
	{
		sphere mySphere;
		parallelepiped myParallelepiped;
	};
};

//class Shape
//{
//public:
//	Shape();
//	Shape(int radius);
//	Shape(int heigth, int width, int depth);
//	~Shape();
//	void setValues(int radius);
//	void setValues(int heigth, int width, int depth);
//	int getRadius();
//	int getHeigth();
//	int getWidth();
//	int getDepth();
//protected:
//	int radius;
//	int heigth;
//	int width;
//	int depth;
//private:
//};

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

//class HashArray
//{
//public:
//	// Adds element to array and return hash and place
//	std::pair <int, int> addElement(Shape newElement);
//	// Delete element from array by hash and place
//	void removeElement(int hash, int place);
//	// Replace element with this hash and place with new 
//	void replaceElement(int hash, int place, Shape newShape);
//	// Return element by hash and place
//	Shape getElement(int hash, int place);
//	int getSizeOfVector(int hash);
//	// Return hash of element
//	int makeHashOfShape(Shape shapeToHash);
//	std::pair <int, int> findElement();
//protected:
//	std::vector<Shape> arrayOfVectorsOfElements[30];
//private:
//};