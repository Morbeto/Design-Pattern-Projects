#include<catch2/catch_test_macros.hpp>
#include "string_to_figure.h"

TEST_CASE("Check valid inputs to the factory", "[string_to_figure]") {

    string_to_figure factory;

    SECTION("Valid triangle") {
        figure* f = factory.create_from("triangle 3 4 5");
        REQUIRE(f != nullptr);
        REQUIRE(f->perimeter() == 12);
        delete f;
    }

    SECTION("Valid rectangle") {
        figure* f = factory.create_from("rectangle 10 20");
        REQUIRE(f != nullptr);
        REQUIRE(f->perimeter() == 60);
        delete f;
    }

    SECTION("Valid circle") {
        figure* f = factory.create_from("circle 5");
        REQUIRE(f != nullptr);
        delete f;
    }
}

TEST_CASE("Check invalid inputs to the factory", "[string_to_figure]") {

    string_to_figure factory;

    SECTION("Empty string") {
        REQUIRE_THROWS_AS(factory.create_from(""), std::invalid_argument);
    }

    SECTION("Missing parameters for triangle") {
        REQUIRE_THROWS_AS(factory.create_from("triangle 10 20"), std::invalid_argument);
    }

    SECTION("Ill-formed parameters for triangle") {
        REQUIRE_THROWS_AS(factory.create_from("triangle 10 abc -30"), std::invalid_argument);
    }

    SECTION("Negative parameter for triangle") {
        REQUIRE_THROWS_AS(factory.create_from("triangle -10 20 30"), std::invalid_argument);
    }

    SECTION("Unknown figure type") {
        REQUIRE_THROWS_AS(factory.create_from("unknown 10 20 30"), std::invalid_argument);
    }

    SECTION("Missing parameters for rectangle") {
        REQUIRE_THROWS_AS(factory.create_from("rectangle"), std::invalid_argument);
    }

    SECTION("Ill-formed parameters for rectangle") {
        REQUIRE_THROWS_AS(factory.create_from("rectangle 10 abc"), std::invalid_argument);
    }

    SECTION("Negative parameter for rectangle") {
        REQUIRE_THROWS_AS(factory.create_from("rectangle 10 -20"), std::invalid_argument);
    }

    SECTION("Missing parameters for circle") {
        REQUIRE_THROWS_AS(factory.create_from("circle"), std::invalid_argument);
    }

    SECTION("Ill-formed parameters for circle") {
        REQUIRE_THROWS_AS(factory.create_from("circle abc"), std::invalid_argument);
    }

    SECTION("Negative parameter for circle") {
        REQUIRE_THROWS_AS(factory.create_from("circle -10"), std::invalid_argument);
    }
}