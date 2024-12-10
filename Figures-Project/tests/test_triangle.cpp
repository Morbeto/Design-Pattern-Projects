#include<catch2/catch_test_macros.hpp>
#include"triangle.h"

TEST_CASE("Triangle perimeter is calculated correctly", "[Triangle]") {
    SECTION("Valid triangle with sides 10, 20, 30") {
        Triangle triangle(10, 20, 30);
        REQUIRE(triangle.perimeter() == 60.0);
    }

    SECTION("Valid triangle with sides 5.5, 6.5, 7.5") {
        Triangle triangle(5, 6, 7);
        REQUIRE(triangle.perimeter() == 18);
    }

    SECTION("Invalid triangle throws exception") {
        REQUIRE_THROWS_AS(Triangle(10.0, 20.0, 50.0), std::invalid_argument);
    }
    SECTION("Invalid triangle parameters exception") {
        REQUIRE_THROWS_AS(Triangle(-5.0, 10, 12), std::invalid_argument);
    }
}

TEST_CASE("Check if to_string for triangle works as intended", "[Triangle]") {
    SECTION("valid string with side 10 20 30 ") {
        Triangle bomba(10 , 20 , 30);
        REQUIRE(bomba.to_string() == "triangle 10 20 30");
    }
}
TEST_CASE("Check if clone method works on triangle", "[Triangle]") {
    SECTION("Clone method succeded") {
        Triangle tri1(10, 20, 30);
        Triangle* tri2 = tri1.clone();
        REQUIRE(tri2 != nullptr);
        REQUIRE(tri2 != &tri1);
        REQUIRE(tri2->getSideOne() == tri1.getSideOne());
        REQUIRE(tri2->getSideTwo() == tri1.getSideTwo());
        REQUIRE(tri2->getSideThree() == tri1.getSideThree());

        delete tri2;
    }
}