#include<catch2/catch_test_macros.hpp>
#include "rectangle.h"

TEST_CASE("perimeter of the rectangle is correct") {
    SECTION("valid perimeter with height = 10 and width = 5") {
        Rectangle rec(10, 5);
        REQUIRE(rec.perimeter() == 30);
    }

    SECTION("valid perimeter with height = 20 and width = 30") {
        Rectangle rec(20, 30);
        REQUIRE(rec.perimeter() == 100);
    }

    SECTION("invalid rectangle parameters exception") {
        REQUIRE_THROWS_AS(Rectangle(-2, -5), std::invalid_argument);
    }
}

TEST_CASE("Check if to_string for rectangle works as intended", "[Rectangle]") {
    SECTION("valid string with height 10 width 20 ") {
        Rectangle bomba(10, 20);
        REQUIRE(bomba.to_string() == "rectangle 10 20");
    }
}