#include <catch2/catch_test_macros.hpp>
#include"../headers/labels/RichLabel.h"
#include"../headers/decorators/TextDecoration.h"
#include"../headers/labels/ProxyLabel"
TEST_CASE("Basic SimpleLabel tests") {
	SimpleLabel label1("neshto neshto");
	SimpleLabel label2;

	REQUIRE(label1.getText() == "neshto neshto");
	REQUIRE(label2.getText() == " ");
}

TEST_CASE("Basic RichLabel tests") {
    RichLabel label("obicham banani", "yellow", "Calibri", 24);

	REQUIRE(label.getText() == "Text: obicham banani\nColor: yellow\nStyle: Calibri\nSize: " + std::to_string(label.getSize()) + '\n');
}

TEST_CASE("ProxyLabel reads input once and then reuses it") {
    std::streambuf* origCin = std::cin.rdbuf();
    std::istringstream input("hello world\n");
    std::cin.rdbuf(input.rdbuf());

    ProxyLabel proxy;

    REQUIRE(proxy.getText() == "hello world");

    REQUIRE(proxy.getText() == "hello world");

    std::cin.rdbuf(origCin);
}

TEST_CASE("ProxyLabel updates text after timeout") {
    std::streambuf* origCin = std::cin.rdbuf();
    std::istringstream input("first text\nsecond text\ny\nupdated text\n");
    std::cin.rdbuf(input.rdbuf());

    ProxyLabel proxy;
    proxy.setTimeout(2);

    REQUIRE(proxy.getText() == "first text");
    REQUIRE(proxy.getText() == "first text");

    REQUIRE(proxy.getText() == "updated text");

    std::cin.rdbuf(origCin);
}