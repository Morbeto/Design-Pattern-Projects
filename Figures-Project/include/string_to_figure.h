#ifndef STRING_TO_FIGURE_H
#define STRING_TO_FIGURE_H
#include"circle.h"
#include"triangle.h"
#include"rectangle.h"
#include <sstream>
class string_to_figure {
public:
	figure* create_from(std::string representation) {
    std::istringstream stream(representation);
    std::string info;
    stream >> info;

    if (info == "triangle") {
        int a, b, c;
        if (stream >> a >> b >> c) {
            return new Triangle(a, b, c);
        } else {
            throw std::invalid_argument("Invalid parameters for triangle.");
        }
    }
    else if (info == "rectangle") {
        int width, height;
        if (stream >> width >> height) {
            return new Rectangle(width, height);  
        } else {
            throw std::invalid_argument("Invalid parameters for rectangle.");
        }
    }
    else if (info == "circle") {
        int radius;
        if (stream >> radius) {
            return new Circle(radius);
        } else {
            throw std::invalid_argument("Invalid parameters for circle.");
        }
    }
    else {
        throw std::invalid_argument("Unknown figure type.");
    }
}
};
#endif // !STRING_TO_FIGURE_H