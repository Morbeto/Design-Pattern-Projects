#include"triangle.h"
#include <stdexcept>
Triangle::Triangle(double first, double second, double third) : sideOne(first), sideTwo(second), sideThree(third) {
	if (first <= 0 || second <= 0 || third <= 0) {
		throw std::invalid_argument("Parameters must be non-negative.");
	}
	if ((first + second < third) || (second + third < first) || (third + first < second)) {
		throw std::invalid_argument("Parameters must be with valid values for a triangle.");
 } 
	
};


double Triangle::getSideOne() const {
	return sideOne;
}

double Triangle::getSideTwo() const {
	return sideTwo;
}

double Triangle::getSideThree() const {
	return sideThree;
}

double Triangle::perimeter() const {
	return sideOne + sideTwo + sideThree;
}

std::string Triangle::to_string() const {
	char buffer[256];
	std::sprintf(buffer, "triangle %.0f %.0f %.0f", sideOne, sideTwo, sideThree);
	return std::string(buffer);
}

Triangle* Triangle::clone() const {
	return new Triangle(*this);
}