#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "random_figure_factory.h"
#include "stream_factory.h"
bool checkThirdSide(int n) {
    if (n >= 2 && n <= 200) return true;
    return false;
}
TEST_CASE("RandomFigureFactory Tests", "[RandomFigureFactory]") {
    RandomFigureFactory factory;

    auto check_range = [](int value, int min = 1, int max = 100) {
        return value >= min && value <= max;
        };
    auto check_third_side = [](int value, int min = 2, int  max = 200) {
        return value >= min && value <= max;
        };
    SECTION("Test creation of random figures within expected range") {
        const int N = 1000;
        int triangleCount = 0, rectangleCount = 0, circleCount = 0;

        for (int i = 0; i < N; ++i) {
            std::unique_ptr<figure> fig(factory.create());
            REQUIRE(fig != nullptr);

            if (auto triangle = dynamic_cast<Triangle*>(fig.get())) {
                REQUIRE(check_range(triangle->getSideOne()));
                REQUIRE(check_range(triangle->getSideTwo()));
                REQUIRE(check_third_side(triangle->getSideThree()));
                triangleCount++;
            }
            else if (auto rectangle = dynamic_cast<Rectangle*>(fig.get())) {
                REQUIRE(check_range(rectangle->getWidth()));
                REQUIRE(check_range(rectangle->getHeight()));
                rectangleCount++;
            }
            else if (auto circle = dynamic_cast<Circle*>(fig.get())) {
                REQUIRE(check_range(circle->getRadius()));
                circleCount++;
            }
            else {
                REQUIRE(false);
            }
        }
        REQUIRE(triangleCount > 0);
        REQUIRE(rectangleCount > 0);
        REQUIRE(circleCount > 0);
    }
}

TEST_CASE("StreamFigureFactory Tests with valid input") {
    std::stringstream input;
    input << "Triangle 3 4 5\n";  
    std::streambuf* originalCin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    StreamFigureFactory factory(std::cin);
    std::unique_ptr<figure> fig(factory.create());

    REQUIRE(fig != nullptr);

    if (auto triangle = dynamic_cast<Triangle*>(fig.get())) {
        REQUIRE(triangle->getSideOne() == 3);
        REQUIRE(triangle->getSideTwo() == 4);
        REQUIRE(triangle->getSideThree() == 5);
    }

    std::cin.rdbuf(originalCin);
}

TEST_CASE("StreamFigureFactory Tests with invalid input") {
    std::stringstream input;
    input << "a b c\n";  // Invalid input for a triangle
    std::streambuf* originalCin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    StreamFigureFactory factory(std::cin);
    std::unique_ptr<figure> fig(factory.create());
    REQUIRE(fig == nullptr);

    std::cin.rdbuf(originalCin);
}

TEST_CASE("StreamFigureFactory Tests with empty input") {
    std::stringstream input;
    input << "\n";  // Empty input, which should not be valid
    std::streambuf* originalCin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    StreamFigureFactory factory(std::cin);
    std::unique_ptr<figure> fig(factory.create());
    REQUIRE(fig == nullptr);

    std::cin.rdbuf(originalCin);
}