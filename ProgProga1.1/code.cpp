#include "code.h"
Shape1::Shape1()
{
	myParallelepiped.depth = 0;
	myParallelepiped.heigth = 0;
	myParallelepiped.temperature = 0;
	myParallelepiped.width = 0;
}
// Adds element to array and return hash
std::pair <int, int> addElement(Shape1 newElement, HashArray1& myArray)
{
	int hash = makeHashOfShape(newElement);
	
	myArray.arrayOfVectorsOfElements[hash].push_back(newElement);
	std::pair <int, int> tmp;
	tmp = std::make_pair(hash, myArray.arrayOfVectorsOfElements[hash].size() - 1);
	return tmp;
}
// Delete element from array by hash and place
void removeElement(int hash, int place, HashArray1& myArray)
{
	if (30)
		if (place <= (int)myArray.arrayOfVectorsOfElements[hash].size())
			myArray.arrayOfVectorsOfElements[hash].erase(myArray.arrayOfVectorsOfElements[hash].begin() + place);
		else
			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << myArray.arrayOfVectorsOfElements[hash].size() << "\n";
	else
		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
}
// Replace element with this hash and place with new element
void replaceElement(int hash, int place, Shape1 newShape, HashArray1& myArray)
{
	if (30)
		if (place <= (int)myArray.arrayOfVectorsOfElements[hash].size())
		{
			myArray.arrayOfVectorsOfElements[hash][place] = newShape;
		}
		else
			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << myArray.arrayOfVectorsOfElements[hash].size() << "\n";
	else
		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
}
// Return element by hash and place
Shape1 getElement(int hash, int place, HashArray1& myArray)
{
	Shape1 tmp;
	if (hash <= 30)
		if (place <= (int)myArray.arrayOfVectorsOfElements[hash].size())
		{
			tmp = myArray.arrayOfVectorsOfElements[hash][place];
		}
		else
			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << myArray.arrayOfVectorsOfElements[hash].size() << "\n";
	else
		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
	return tmp;
}
// Return size of vector
int getSizeOfVector(int hash, HashArray1& myArray)
{
	return myArray.arrayOfVectorsOfElements[hash].size();
}
// Return hash of element
int makeHashOfShape(Shape1 shapeToHash)
{
	int hash = 0;
	hash += shapeToHash.myTetraedr.edge * 27;
	hash += shapeToHash.mySphere.radius * 23;
	hash += shapeToHash.myParallelepiped.heigth * 17;
	hash += shapeToHash.myParallelepiped.depth * 11;
	hash += shapeToHash.myParallelepiped.width * 7;
	hash = hash % 30;
	return hash;
}

bool sort(Shape1 a, Shape1 b)
{
	int aValue = 0;
	int bValue = 0;
	if (a.key == Shape1::type::round)
		aValue = a.mySphere.getVolume();
	else if (a.key == Shape1::type::square)
		aValue = a.myParallelepiped.getVolume();
	if (b.key == Shape1::type::round)
		bValue = a.mySphere.getVolume();
	else if (b.key == Shape1::type::square)
		bValue = a.myParallelepiped.getVolume();
	return aValue < bValue;
}
void sortElements(HashArray1& myArray)
{
	for (int i = 0; i < 30; i++)
	{
		std::sort(myArray.arrayOfVectorsOfElements[i].begin(), myArray.arrayOfVectorsOfElements[i].end(), sort);
	}
}
void showContainer(std::ostream &out, HashArray1 array)
{
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
					out << tmp.mySphere.getVolume() << "\n";
					counter++;
				}
				else if (tmp.key == Shape1::type::square)
				{
					out << "Element number " << counter << " is a parallelepiped with edges: ";
					out << tmp.myParallelepiped.heigth << ", ";
					out << tmp.myParallelepiped.width << ", ";
					out << tmp.myParallelepiped.depth << " ";
					out	<< tmp.myParallelepiped.getVolume() << "\n";
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
}