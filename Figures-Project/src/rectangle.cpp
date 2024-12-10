#include"rectangle.h"
#include <stdexcept>
Rectangle::Rectangle(double height, double width) : height(height), width(width) {
	if (height <=0 || width <= 0) {
		throw std::invalid_argument("Parameters must be non-negative.");
	}
};

double Rectangle::getHeight() const {
	return height;
}

double Rectangle::getWidth() const {
	return width;
}

double Rectangle::perimeter() const {
	return 2 * width + 2 * height;
}

std::string Rectangle::to_string() const {
	char buffer[256];
	std::sprintf(buffer, "rectangle %.0f %.0f", height, width);
	return std::string(buffer);
}

Rectangle* Rectangle::clone() const {
	return new Rectangle(*this);
}