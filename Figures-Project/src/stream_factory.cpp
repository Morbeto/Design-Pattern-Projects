#include"stream_factory.h"
#include <iostream>
#include <limits>
#include <algorithm>
figure* StreamFigureFactory::create() {
    if (!stream) {
        return nullptr;
    }

    std::string figureType;
    stream >> figureType;

    std::transform(figureType.begin(), figureType.end(), figureType.begin(), ::tolower);

    if (figureType == "triangle") {
        int side1, side2, side3;
        stream >> side1 >> side2 >> side3;
        if (stream && side1 > 0 && side2 > 0 && side3 > 0) {
            return new Triangle(side1, side2, side3);
        }
    }
    else if (figureType == "rectangle") {
        int width, height;
        stream >> width >> height;
        if (stream && width > 0 && height > 0) {
            return new Rectangle(width, height);
        }
    }
    else if (figureType == "circle") {
        int radius;
        stream >> radius;
        if (stream && radius > 0) {
            return new Circle(radius);
        }
    }

    return nullptr;
}
