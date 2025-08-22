#pragma once
#include"trans.h"

class Censor : public Transformation {
private:
    std::string word_to_censor;
public:
    Censor(std::string word) : word_to_censor(word) {}

    std::string transform(const std::string& text) const override {
        std::string result = text;
        size_t pos = 0;
        while ((pos = result.find(word_to_censor, pos)) != std::string::npos) {
            result.replace(pos, word_to_censor.length(), std::string(word_to_censor.length(), '*'));
            pos += word_to_censor.length();
        }
        return result;
    }
};
