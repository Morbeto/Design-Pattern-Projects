#include"labels/ProxyLabel.h"

ProxyLabel::ProxyLabel(int timeout) : timeoutLimit(timeout) {}

void ProxyLabel::setTimeout(int timeout) {
    timeoutLimit = timeout;
}

std::string ProxyLabel::getText() const {
    ++callCount;

    if (!initialized) {
        std::cout << "Enter label text: ";
        std::string input;
        std::getline(std::cin, input);
        label = std::make_unique<SimpleLabel>(input);
        initialized = true;
    }

    if (callCount >= timeoutLimit) {
        std::cout << "\n[Timeout reached] Current text: " << label->getText() << "\n";
        std::cout << "Do you want to change it? (y/n): ";
        std::string response;
        std::getline(std::cin, response);

        if (response == "y" || response == "Y") {
            std::cout << "Enter new label text: ";
            std::string newText;
            std::getline(std::cin, newText);
            label = std::make_unique<SimpleLabel>(newText);
        }
        callCount = 0; 
    }

    return label->getText();
}