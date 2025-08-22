#include "labels/LabelBuilder.h"


std::shared_ptr<Label> LabelBuilder::build(std::istream& in) {
    std::cout << "Would you like to have a helper text?\n1 - Yes\n2 - No\n> ";
    int choice;
    in >> choice;
    in.ignore();

    if (choice == 1) {
        std::cout << "Enter the helper text: ";
        std::string helpText;
        std::getline(in, helpText);
        helper = createHelper(helpText);
    }

    std::cout << "Enter the type of label (simple/rich/proxy): ";
    std::string type;
    do { in >> type; } while (type != "simple" && type != "rich" && type != "proxy");
    label = createLabel(type, in);

    std::cout << "Enter number of decorators you want to use: ";
    int numDecorators;
    in >> numDecorators;

    for (int i = 0; i < numDecorators; i++) {
        std::cout << "\nPick a decorator:\n1 - Basic\n2 - Cycling\n3 - Random\n> ";
        int decoratorChoice;
        in >> decoratorChoice;

        if (decoratorChoice == 1) {
            std::cout << "Enter transformation type (e.g., Capitalize, LeftTrim, etc.): ";
            std::string transName;
            in >> transName;
            auto transformation = createTransformation(transName);
            label = std::make_shared<TextTransformationDecorator>(label, transformation);
        }
        else if (decoratorChoice == 2) {
            std::cout << "Enter number of transformations for cycling: ";
            int count;
            in >> count;
            std::vector<std::shared_ptr<Transformation>> transforms;
            for (int j = 0; j < count; j++) {
                std::cout << "Enter transformation " << j + 1 << ": ";
                std::string transName;
                in >> transName;
                transforms.push_back(createTransformation(transName));
            }
            label = std::make_shared<CyclingTransformationsDecorator>(transforms, label);
        }
        else if (decoratorChoice == 3) {
            std::cout << "Enter number of transformations for random: ";
            int count;
            in >> count;
            std::vector<std::shared_ptr<Transformation>> transforms;
            for (int j = 0; j < count; j++) {
                std::cout << "Enter transformation " << j + 1 << ": ";
                std::string transName;
                in >> transName;
                transforms.push_back(createTransformation(transName));
            }
            label = std::make_shared<RandomTextDecoration>(transforms, label);
        }
        else {
            std::cout << "Invalid decorator type. Skipping.\n";
        }
    }

    if (helper && label) {
        label->setHelper(std::move(helper));
    }

    return label;
}



std::unique_ptr<HelpTextBridge> LabelBuilder::createHelper(const std::string& text) {
    return std::make_unique<HelpText>(text);
}

std::shared_ptr<Label> LabelBuilder::createLabel(const std::string& type, std::istream& in) {
    std::string basicText;
    std::cout << "Enter the text for the label: ";
    in.ignore();
    std::getline(in, basicText);

    if (type == "simple") {
        return std::make_shared<SimpleLabel>(basicText);
    }
    else if (type == "rich") {
        std::string color, font;
        int fontSize;
        std::cout << "Enter the color: ";
        in >> color;
        std::cout << "Enter the font style: ";
        in >> font;
        std::cout << "Enter the font size: ";
        in >> fontSize;
        return std::make_shared<RichLabel>(basicText, color, font, fontSize);
    }
    else if (type == "proxy") {
        int timeout;
        std::cout << "Pick a timeout number: ";
        in >> timeout;
        return std::make_shared<ProxyLabel>(timeout);
    }

    throw std::invalid_argument("Unknown label type");
}

std::shared_ptr<Transformation> LabelBuilder::createTransformation(const std::string& s) {
    if (s == "Capitalize") return TransformationFactory::createCapitalize();
    if (s == "LeftTrim") return TransformationFactory::createLeftTrim();
    if (s == "RightTrim") return TransformationFactory::createRightTrim();
    if (s == "NormalizeSpace") return TransformationFactory::createNormalizeSpace();
    if (s == "Decorate") return TransformationFactory::createDecorate();

    if (s.starts_with("Censor:")) {
        std::string word = s.substr(7);  // after "Censor:"
        return TransformationFactory::createCensor(word);
    }

    if (s.starts_with("Replace:")) {
        std::string args = s.substr(8);  // after "Replace:"
        size_t comma = args.find(',');
        if (comma == std::string::npos) throw std::invalid_argument("Replace must use comma: Replace:old,new");

        std::string from = args.substr(0, comma);
        std::string to = args.substr(comma + 1);
        return TransformationFactory::createReplace(from, to);
    }

    if (s.starts_with("Composite:")) {
        std::string compositeInput = s.substr(10);  // after "Composite:"
        return TransformationFactory::createComposite(compositeInput);
    }

    throw std::invalid_argument("Unknown transformation: " + s);
}