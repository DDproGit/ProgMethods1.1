#include "code.h"
Shape::Shape()
{
	key = empty;
	myParallelepiped.depth = 0;
	myParallelepiped.heigth = 0;
	myParallelepiped.density = 0.00;
	myParallelepiped.temperature = 0;
	myParallelepiped.width = 0;
}
// Adds element to array and return hash
std::pair <int, int> addElement(Shape newElement, HashArray1& myArray)
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
void replaceElement(int hash, int place, Shape newShape, HashArray1& myArray)
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
Shape getElement(int hash, int place, HashArray1& myArray)
{
	Shape tmp;
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
int makeHashOfShape(Shape shapeToHash)
{
	int hash = 0;
	if (shapeToHash.key == Shape::type::tetra)
		hash += shapeToHash.myTetraedr.edge * 27;
	if (shapeToHash.key == Shape::type::round)
		hash += shapeToHash.mySphere.radius * 23;
	if (shapeToHash.key == Shape::type::square)
	{
		hash += shapeToHash.myParallelepiped.heigth * 17;
		hash += shapeToHash.myParallelepiped.depth * 11;
		hash += shapeToHash.myParallelepiped.width * 7;
	}
	hash = hash % 30;
	return hash;
}

bool sort(Shape a, Shape b)
{
	int aValue = 0;
	int bValue = 0;
	if (a.key == Shape::type::round)
		aValue = a.mySphere.getVolume();
	else if (a.key == Shape::type::square)
		aValue = a.myParallelepiped.getVolume();
	if (b.key == Shape::type::round)
		bValue = a.mySphere.getVolume();
	else if (b.key == Shape::type::square)
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
void showContainer(std::ostream& out, HashArray1 array)
{
	int counter = 0;
	for (int i = 0; i < 30; i++)
	{
		Shape tmp;
		if (getSizeOfVector(i, array) != 0)
		{
			int size = getSizeOfVector(i, array);
			for (int j = 0; j < size; j++)
			{
				tmp = getElement(i, j, array);
				if (tmp.key == Shape::type::round)
				{
					out << "Element number " << counter << " is a sphere with radius: ";
					out << tmp.mySphere.radius << ", temperature ";
					out << tmp.mySphere.temperature << ", density ";
					out << tmp.mySphere.density << ", volume ";
					out << tmp.mySphere.getVolume() << "\n";
					counter++;
				}
				else if (tmp.key == Shape::type::square)
				{
					out << "Element number " << counter << " is a parallelepiped with edges: ";
					out << tmp.myParallelepiped.heigth << ", ";
					out << tmp.myParallelepiped.width << ", ";
					out << tmp.myParallelepiped.depth << ", temperature ";
					out << tmp.myParallelepiped.temperature << ", density ";
					out << tmp.myParallelepiped.density << ", volume ";
					out << tmp.myParallelepiped.getVolume() << "\n";
					counter++;
				}
				else if (tmp.key == Shape::type::tetra)
				{
					out << "Element number " << counter << " is a tetraedr with edge: ";
					out << tmp.myTetraedr.edge << ", temperature ";
					out << tmp.myTetraedr.temperature << ", density ";
					out << tmp.myTetraedr.density << ", volume ";
					out << tmp.myTetraedr.getVolume() << "\n";
				}
				else if (tmp.key == Shape::type::empty)
				{
					out << "Element number " << i << " is empty\n";
					counter++;
				}
			}
		}
	}
	out << "Total number of objects: " << counter << "\n";
}
void showContainer(std::ostream& out, HashArray1 array, int limit)
{
	int counter = 0;
	for (int i = 0; i < 30; i++)
	{
		Shape tmp;
		if (getSizeOfVector(i, array) != 0)
		{
			int size = getSizeOfVector(i, array);
			for (int j = 0; j < size; j++)
			{
				tmp = getElement(i, j, array);
				if (tmp.key == Shape::type::round)
				{
					if (limit == 1)
					{
						counter++;
						continue;
					}
					out << "Element number " << counter << " is a sphere with radius: ";
					out << tmp.mySphere.radius << ", temperature ";
					out << tmp.mySphere.temperature << ", density ";
					out << tmp.mySphere.density << ", volume ";
					out << tmp.mySphere.getVolume() << "\n";
					counter++;
				}
				else if (tmp.key == Shape::type::square)
				{
					if (limit == 2)
					{
						counter++;
						continue;
					}
					out << "Element number " << counter << " is a parallelepiped with edges: ";
					out << tmp.myParallelepiped.heigth << ", ";
					out << tmp.myParallelepiped.width << ", ";
					out << tmp.myParallelepiped.depth << ", temperature ";
					out << tmp.myParallelepiped.temperature << ", density ";
					out << tmp.myParallelepiped.density << ", volume ";
					out << tmp.myParallelepiped.getVolume() << "\n";
					counter++;
				}
				else if (tmp.key == Shape::type::tetra)
				{
					if (limit == 3)
					{
						counter++;
						continue;
					}
					out << "Element number " << counter << " is a tetraedr with edge: ";
					out << tmp.myTetraedr.edge << ", temperature ";
					out << tmp.myTetraedr.temperature << ", density ";
					out << tmp.myTetraedr.density << ", volume ";
					out << tmp.myTetraedr.getVolume() << "\n";
				}
				else if (tmp.key == Shape::type::empty)
				{
					out << "Element number " << i << " is empty\n";
					counter++;
				}
			}
		}
	}
	out << "Total number of objects: " << counter << "\n";
}