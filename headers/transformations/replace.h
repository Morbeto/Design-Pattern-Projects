#pragma once
#include"trans.h"

class Replace : public Transformation {
private:
    std::string search;
    std::string replace_with;

public:
    Replace(std::string a, std::string b) : search(std::move(a)), replace_with(std::move(b)) {}

    std::string transform(const std::string& og) const override {
        std::string result = og;
        size_t pos = 0;
        while ((pos = result.find(search, pos)) != std::string::npos) {
            result.replace(pos, search.length(), replace_with);
            pos += replace_with.length();
        }
        return result;
    }
};
