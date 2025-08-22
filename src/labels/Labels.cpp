#include "labels/Label.h"

std::string Label::getHelper() const {
    return helper ? helper->getHelpText() : "";
}

bool Label::hasHelper() const {
    return helper != nullptr;
}

void Label::setHelper(std::unique_ptr<HelpTextBridge> text) {
    helper = std::move(text);
}
