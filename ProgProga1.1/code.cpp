#include "code.h"

//Shape::Shape()
//{
//	radius = 0;
//	heigth = 0;
//	width = 0;
//	depth = 0;
//}
//Shape::Shape(int radius)
//{
//	this->radius = radius;
//	heigth = 0;
//	width = 0;
//	depth = 0;
//}
//Shape::Shape(int heigth, int width, int depth)
//{
//	radius = 0;
//	this->heigth = heigth;
//	this->width = width;
//	this->depth = depth;
//}
//Shape::~Shape() 
//{
//
//}
//void Shape::setValues(int radius)
//{
//	this->radius = radius;
//	heigth = 0;
//	width = 0;
//	depth = 0;
//}
//void Shape::setValues(int heigth, int width, int depth)
//{
//	radius = 0;
//	this->heigth = heigth;
//	this->width = width;
//	this->depth = depth;
//}
//int Shape::getRadius()
//{
//	return radius;
//}
//int Shape::getHeigth()
//{
//	return heigth;
//}
//int Shape::getWidth()
//{
//	return width;
//}
//int Shape::getDepth()
//{
//	return depth;
//}

//// Adds element to array and return hash
//std::pair <int, int> HashArray::addElement(Shape newElement)
//{
//	int hash = makeHashOfShape(newElement);
//	arrayOfVectorsOfElements[hash].push_back(newElement);
//	std::pair <int, int> tmp;
//	tmp = std::make_pair(hash, arrayOfVectorsOfElements[hash].size() - 1);
//	return tmp;
//}
//// Delete element from array by hash and place
//void HashArray::removeElement(int hash, int place)
//{
//	if (30)
//		if (place <= arrayOfVectorsOfElements[hash].size())
//			arrayOfVectorsOfElements[hash].erase(arrayOfVectorsOfElements[hash].begin() + place);
//		else
//			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << arrayOfVectorsOfElements[hash].size() << "\n";
//	else
//		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
//}
//// Replace element with this hash and place with new element
//void HashArray::replaceElement(int hash, int place, Shape newShape)
//{
//	if (30)
//		if (place <= arrayOfVectorsOfElements[hash].size())
//		{
//			arrayOfVectorsOfElements[hash][place] = newShape;
//		}
//		else
//			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << arrayOfVectorsOfElements[hash].size() << "\n";
//	else
//		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
//}
//// Return element by hash and place
//Shape HashArray::getElement(int hash, int place)
//{
//	Shape tmp;
//	if (hash <= 30)
//		if (place <= arrayOfVectorsOfElements[hash].size())
//		{
//			tmp = arrayOfVectorsOfElements[hash][place];
//		}
//		else
//			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << arrayOfVectorsOfElements[hash].size() << "\n";
//	else
//		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
//	return tmp;
//}
//// Return size of vector
//int HashArray::getSizeOfVector(int hash)
//{
//	return arrayOfVectorsOfElements[hash].size();
//}
//// Return hash of element
//int HashArray::makeHashOfShape(Shape shapeToHash)
//{
//	int hash = 0;
//	hash += shapeToHash.getRadius() * 23;
//	hash += shapeToHash.getHeigth() * 17;
//	hash += shapeToHash.getWidth() * 11;
//	hash += shapeToHash.getDepth() * 7;
//	hash = hash % 30;
//	return hash;
//}

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
		if (place <= myArray.arrayOfVectorsOfElements[hash].size())
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
		if (place <= myArray.arrayOfVectorsOfElements[hash].size())
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
		if (place <= myArray.arrayOfVectorsOfElements[hash].size())
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
	hash += shapeToHash.mySphere.radius * 23;
	hash += shapeToHash.myParallelepiped.heigth * 17;
	hash += shapeToHash.myParallelepiped.depth * 11;
	hash += shapeToHash.myParallelepiped.width * 7;
	hash = hash % 30;
	return hash;
}