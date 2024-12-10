#include "abstract_factory.h"
#include <iostream>
#include <sstream>

figure_factory* AbstractFactory::getFactory(std::string type) {
    if (type == "random") {
        return new RandomFigureFactory();
    }
    else if (type == "stream") {
        std::string userInput;
        std::cout << "Enter figure data (e.g., 'circle 10' or 'rectangle 10 20'):\n";
        std::getline(std::cin, userInput);

        std::istringstream stream(userInput);
        return new StreamFigureFactory(stream);
    }
    else {
        std::cout << "Invalid factory type.\n";
        return nullptr;
    }
}
