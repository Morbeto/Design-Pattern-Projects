#include<catch2/catch_test_macros.hpp>
#include"circle.h"
TEST_CASE("perimeter of the circle is correct","[Circle]") {
    SECTION("Valid radius values") {
        Circle c1(5);

        double actual = c1.perimeter();
        double expected = 31.4;
        double tolerance = 0.01; 

        REQUIRE(actual >= expected - tolerance);
        REQUIRE(actual <= expected + tolerance);
    }

    SECTION("Invalid radius values") {
        REQUIRE_THROWS_AS(Circle(-10), std::invalid_argument);
        REQUIRE_THROWS_AS(Circle(-0.1), std::invalid_argument);
    }

    SECTION("Edge case: zero radius") {
        REQUIRE_THROWS_AS(Circle(0), std::invalid_argument);
    }
}

TEST_CASE("Check if to_string for circle works as intended", "[Circle]") {
    SECTION("valid string with radius = 15 ") {
        Circle bomba(15);
        REQUIRE(bomba.to_string() == "circle 15");
    }
}

TEST_CASE("Check if clone method for circle works", "[Circle]") {
    SECTION("Clone method succeeded for Circle") {
        Circle circle1(5);  
        Circle* circle2 = circle1.clone();  

        REQUIRE(circle2 != nullptr);  

        REQUIRE(circle2->getRadius() == circle1.getRadius());  
        REQUIRE(circle2 != &circle1);  

        delete circle2; 
    }

}