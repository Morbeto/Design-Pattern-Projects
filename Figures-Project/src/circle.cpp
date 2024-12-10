#include"circle.h"
#include<stdexcept>
Circle::Circle(double rad) : radius(rad) {
	if (rad <= 0.0) {
		throw std::invalid_argument("Parameters must be non-negative.");
	}
}

double Circle::getRadius() const {
	return radius;
}


double  Circle::perimeter() const {
	return 2 * 3.14 * radius;
}

std::string Circle::to_string() const {
	char buffer[50]; 
	std::sprintf(buffer, "circle %.0f", radius); 
	return std::string(buffer);
}
Circle* Circle::clone() const {
	return new Circle(*this);
}