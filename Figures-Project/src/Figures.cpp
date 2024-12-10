#include <iostream>
#include <vector>
#include<fstream>
#include "abstract_factory.h"
#include <memory>


class Application {
private:
    std::vector<std::unique_ptr<figure>> figures;
    std::unique_ptr<figure_factory> factory;

public:
    Application() = default;
    void listFigures() const {
        for (const auto& fig : figures) {
            std::cout << fig->to_string() << std::endl;
        }
    }

    void cloneFigures() const {
        for (const auto& fig : figures) {
            auto clonedFig = std::unique_ptr<figure>(fig->clone());
            std::cout << clonedFig->to_string() << std::endl;
        }
    }

    void serializeFigures() const {
        std::ofstream file("figures.txt");
        if (!file) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        for (const auto& fig : figures) {
            file << fig->to_string() << std::endl;
        }
    }
    void run() {
        std::string inputMethod;
        std::cout << "Enter input method (stream or random): ";
        std::cin >> inputMethod;

        if (inputMethod == "stream") {
            std::cin.ignore();
            factory = std::make_unique<StreamFigureFactory>(std::cin);
        }
        else if (inputMethod == "random") {
            factory = std::make_unique<RandomFigureFactory>();
        }
        else {
            std::cerr << "Invalid input method.\n";
            return;
        }

        int count;
        std::cout << "Enter the number of figures to create: ";
        std::cin >> count;

        for (int i = 0; i < count; ++i) {
            auto newFigure = std::unique_ptr<figure>(factory->create());
            if (newFigure) {
                figures.push_back(std::move(newFigure));
            }
            else {
                std::cerr << "Invalid figure input.\n";
            }
        }

        std::cout << "\nFigures created:\n";
        listFigures();

        std::cout << "\nCloned figures:\n";
        cloneFigures();

        std::string serializeChoice;
        std::cout << "\nDo you want to serialize the figures to a file? (yes/no): ";
        std::cin >> serializeChoice;
        if (serializeChoice == "yes") {
            serializeFigures();
        }
    }
};

int main() {
    Application app;
    app.run();
    return 0;
}