#pragma once
#include <cstdlib>
#include <ctime>
#include"random_figure_factory.h"
RandomFigureFactory::RandomFigureFactory() {
    srand(static_cast<unsigned>(time(0)));
}

figure* RandomFigureFactory::create() {
    int type = rand() % 3; 

    if (type == 0) {
        int first = rand() % 100 + 1, second = rand() % 100 + 1;
        return new Triangle(first, second, first + second);
    }
    else if (type == 1) {
        return new Rectangle(rand() % 100 + 1, rand() % 100 + 1);
    }
    else if (type == 2) {
        return new Circle(rand() % 100 + 1);
    }
}
