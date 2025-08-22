#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../headers/transformations/capitalize.h"
#include "../headers/transformations/leftTrim.h"
#include "../headers/transformations/rightTrim.h"
#include "../headers/transformations/normalizeSpace.h"
#include "../headers/transformations/decorate.h"
#include "../headers/transformations/censor.h"
#include "../headers/transformations/replace.h"
#include"../headers/transformations/CompositeTrans.h"
#include"../headers/decorators/TextDecoration.h"
#include"../headers/labels/SimpleLabel.h"
#include"../headers/decorators/CyclingDecoration.h"
#include"../headers/decorators/RandomDecoration.h"
#include"../headers/labels/LabelBuilder.h"

TEST_CASE("Capitalize Transformation") {
    Capitalize capitalize;

    std::string test1 = "some text";
    std::string test2 = "SOMe text";
    std::string test3 = "some";
    std::string test4 = "";

    REQUIRE(capitalize.transform(test1) == "Some text");
    REQUIRE(capitalize.transform(test2) == "SOMe text");
    REQUIRE(capitalize.transform(test3) == "Some");
    REQUIRE(capitalize.transform(test4) == "");
}

TEST_CASE("LeftTrim Transformation") {
    LeftTrim leftTrim;

    std::string test1 = "some text";
    std::string test2 = " some";
    std::string test3 = "";

    REQUIRE(leftTrim.transform(test1) == "some text");
    REQUIRE(leftTrim.transform(test2) == "some");
    REQUIRE(leftTrim.transform(test3) == "");
}

TEST_CASE("RightTrim Transformation") {
    RightTrim rightTrim;

    std::string test1 = "some text ";
    std::string test2 = "some ";
    std::string test3 = " ";

    REQUIRE(rightTrim.transform(test1) == "some text");
    REQUIRE(rightTrim.transform(test2) == "some");
    REQUIRE(rightTrim.transform(test3) == "");
}

TEST_CASE("NormalizeSpace Transformation") {
    Normalize normalizeSpace;

    std::string test1 = "some   text";
    std::string test2 = "some  text here  ";
    std::string test3 = "   text";
    std::string test4 = "";

    REQUIRE(normalizeSpace.transform(test1) == "some text");
    REQUIRE(normalizeSpace.transform(test2) == "some text here ");
    REQUIRE(normalizeSpace.transform(test3) == " text");
    REQUIRE(normalizeSpace.transform(test4) == "");
}

TEST_CASE("Decorate Transformation") {
    Decorate decorate;

    std::string test1 = "abc";
    std::string test2 = "text";
    std::string test3 = "  abc  ";
    std::string test4 = "";

    REQUIRE(decorate.transform(test1) == "-={ abc }=-");
    REQUIRE(decorate.transform(test2) == "-={ text }=-");
    REQUIRE(decorate.transform(test3) == "-={   abc   }=-");
    REQUIRE(decorate.transform(test4) == "-={  }=-");
}

TEST_CASE("Censor Transformation") {
    Censor censor("abc");

    std::string test1 = "abc def abc def";
    std::string test2 = "some abc some";
    std::string test3 = "";

    REQUIRE(censor.transform(test1) == "*** def *** def");
    REQUIRE(censor.transform(test2) == "some *** some");
    REQUIRE(censor.transform(test3) == "");
}

TEST_CASE("Replace Transformation") {
    Replace replace("abc", "d");

    std::string test1 = "abc abc def";

    REQUIRE(replace.transform(test1) == "d d def");
}

TEST_CASE("Different text decorations tests") {
    SECTION("Capitalize Transformation") {
        auto label = std::make_shared<SimpleLabel>("test");
        auto capitalize = std::make_shared<Capitalize>();
        TextTransformationDecorator decorator(label, capitalize);
        REQUIRE(decorator.getText() == "Test");
    }

    SECTION("LeftTrim Transformation") {
        auto label = std::make_shared<SimpleLabel>(" leading space");
        auto trimLeft = std::make_shared<LeftTrim>();
        TextTransformationDecorator decorator(label, trimLeft);
        REQUIRE(decorator.getText() == "leading space");
    }

    SECTION("RightTrim Transformation") {
        auto label = std::make_shared<SimpleLabel>("trailing space ");
        auto trimRight = std::make_shared<RightTrim>();
        TextTransformationDecorator decorator(label, trimRight);
        REQUIRE(decorator.getText() == "trailing space");
    }

    SECTION("NormalizeSpace Transformation") {
        auto label = std::make_shared<SimpleLabel>("multiple   spaces  here");
        auto normalize = std::make_shared<Normalize>();
        TextTransformationDecorator decorator(label, normalize);
        REQUIRE(decorator.getText() == "multiple spaces here");
    }

    SECTION("Decorate Transformation") {
        auto label = std::make_shared<SimpleLabel>("value");
        auto decorate = std::make_shared<Decorate>();
        TextTransformationDecorator decorator(label, decorate);
        REQUIRE(decorator.getText() == "-={ value }=-");
    }

    SECTION("Censor Transformation") {
        auto label = std::make_shared<SimpleLabel>("this is secret data and secret plan");
        auto censor = std::make_shared<Censor>("secret");
        TextTransformationDecorator decorator(label, censor);
        REQUIRE(decorator.getText() == "this is ****** data and ****** plan");
    }

    SECTION("Replace Transformation") {
        auto label = std::make_shared<SimpleLabel>("abc abc def");
        auto replace = std::make_shared<Replace>("abc", "x");
        TextTransformationDecorator decorator(label, replace);
        REQUIRE(decorator.getText() == "x x def");
    }

    SECTION("Chained Transformations: Trim + Capitalize") {
        auto label = std::make_shared<SimpleLabel>(" hello");
        auto trim = std::make_shared<LeftTrim>();
        auto capitalize = std::make_shared<Capitalize>();

        auto trimmed = std::make_shared<TextTransformationDecorator>(label, trim);
        TextTransformationDecorator finalDecorator(trimmed, capitalize);

        REQUIRE(finalDecorator.getText() == "Hello");
    }
}


TEST_CASE("CyclingTransformationsDecorator functionality", "[CyclingTransformationsDecorator]") {
    SECTION("getText returns label text if no transformations are provided") {
        auto label = std::make_shared<SimpleLabel>("test");
        CyclingTransformationsDecorator decorator({}, label);
        REQUIRE(decorator.getText() == "test");
    }

    SECTION("getText cycles through transformations and returns transformed text") {
        auto label = std::make_shared<SimpleLabel>(" test ");
        auto capitalize = std::make_shared<Capitalize>();
        auto leftTrim = std::make_shared<LeftTrim>();
        auto rightTrim = std::make_shared<RightTrim>();
        auto decorate = std::make_shared<Decorate>();
        std::vector<std::shared_ptr<Transformation>> transformations = {
            leftTrim,
            rightTrim,
        };

        CyclingTransformationsDecorator decorator(transformations, label);

        REQUIRE(decorator.getText() == "test "); 
        REQUIRE(decorator.getText() == " test");

        std::vector<std::shared_ptr<Transformation>> transformations2 = {
            capitalize,
            decorate,
        };
        auto label2 = std::make_shared<SimpleLabel>("test");

        CyclingTransformationsDecorator decorator2(transformations2, label2);

        REQUIRE(decorator2.getText() == "Test");
        REQUIRE(decorator2.getText() == "-={ test }=-");
    }
}


TEST_CASE("RandomTransformationDecorator applies a random transformation") {
    auto label = std::make_shared<SimpleLabel>("  abc def  ");

    std::vector<std::shared_ptr<Transformation>> transList = {
        std::make_shared<Capitalize>(),
        std::make_shared<LeftTrim>(),
        std::make_shared<RightTrim>()
    };

    RandomTextDecoration randomDecorator(transList, label);

    std::string result = randomDecorator.getText();

    REQUIRE_FALSE(result.empty());
}



TEST_CASE("RemoveDecorator removes first matching transformation") {
    std::shared_ptr<Label> label = std::make_shared<SimpleLabel>("abcd efgh ijkl mnop");
    label = std::make_shared<TextTransformationDecorator>(label, std::make_shared<Censor>("abcd"));
    label = std::make_shared<TextTransformationDecorator>(label, std::make_shared<Censor>("mnop"));
    REQUIRE(label->getText() == "**** efgh ijkl ****");

    std::shared_ptr<LabelDecoratorBase> whatToRemove = std::make_shared<TextTransformationDecorator>(nullptr, std::make_shared<Censor>("abcd"));
    label = LabelDecoratorBase::removeDecorator(label, whatToRemove);
    REQUIRE(label->getText() == "**** efgh ijkl ****");
}

TEST_CASE("CompositeTransformation applies multiple transformations from string", "[CompositeTransformation]") {
    SECTION("LeftTrim, RightTrim, Capitalize, Replace") {
        std::string transformInput = "LeftTrim\tRightTrim\tReplace(test,done)\tCapitalize";
        CompositeTransformation composite(transformInput);

        std::string original = " test ";
        std::string result = composite.transform(original);

        REQUIRE(result == "Done");
    }

    SECTION("Capitalize + Decorate") {
        std::string transformInput = "Capitalize\tDecorate";
        CompositeTransformation composite(transformInput);

        std::string original = "label";
        std::string result = composite.transform(original);

        REQUIRE(result == "-={ Label }=-"); 
    }

    SECTION("Invalid transformation throws") {
        REQUIRE_THROWS_AS(CompositeTransformation("Invalid\tCapitalize"), std::invalid_argument);
    }
}

TEST_CASE("LabelBuilder builds simple label with Capitalize transformation and helper", "[LabelBuilder]") {
    std::istringstream input(
        "1\n"                  // yes to helper
        "My helper text\n"     // helper text
        "simple\n"             // label type
        "helloWorld\n"         // label text
        "1\n"                  // number of decorators
        "1\n"                  // basic decorator
        "Capitalize\n"         // transformation type
    );

    LabelBuilder builder;
    std::shared_ptr<Label> label = builder.build(input);

    REQUIRE(label != nullptr);
    REQUIRE(label->getText() == "HelloWorld");
    REQUIRE(label->hasHelper());
    REQUIRE(label->getHelper() == "My helper text");
}