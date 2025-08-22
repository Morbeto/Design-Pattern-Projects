#pragma once
#include"trans.h"

class Normalize : public Transformation {
public:

    std::string transform(const std::string& og) const override {
        std::string result;
        bool lastWasSpace = false;

        for (char ch : og) {
            if (ch == ' ') {
                if (!lastWasSpace) {
                    result += ch;
                    lastWasSpace = true;
                }
            }
            else {
                result += ch;
                lastWasSpace = false;
            }
        }

        return result;
    }
};