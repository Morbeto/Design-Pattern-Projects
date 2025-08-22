#include"transformations/CompositeTrans.h"

 CompositeTransformation::CompositeTransformation( const std::string& s) {
     size_t start = 0;
     size_t tabPos;

     while ((tabPos = s.find('\t', start)) != std::string::npos) {
         std::string token = s.substr(start, tabPos - start);
         createTransformation(token);
         start = tabPos + 1;
     }

     if (start < s.length()) {
         createTransformation(s.substr(start));
     }
}

void CompositeTransformation::addTransformation(std::shared_ptr<Transformation> trans) {
	transformations.push_back(trans);
}

void CompositeTransformation::addTransformation(std::string& s) {
    createTransformation(s);
}

void CompositeTransformation::createTransformation(const std::string& s) {
    if (s == "Capitalize") {
        transformations.push_back(std::make_shared<Capitalize>());
    }
    else if (s == "LeftTrim") {
        transformations.push_back(std::make_shared<LeftTrim>());
    }
    else if (s == "RightTrim") {
        transformations.push_back(std::make_shared<RightTrim>());
    }
    else if (s == "NormalizeSpace") {
        transformations.push_back(std::make_shared<Normalize>());
    }
    else if (s == "Decorate") {
        transformations.push_back(std::make_shared<Decorate>());
    }
    else if (s.substr(0, 6) == "Censor") {
        std::string censorText = s.substr(8, s.size() - 1);
        transformations.push_back(std::make_shared<Censor>(censorText));
    }
    else if (s.substr(0, 7) == "Replace") {
        auto start = s.find("(");
        auto end = s.find(")");
        if (start == std::string::npos || end == std::string::npos || end <= start)
            throw std::invalid_argument("Invalid Replace format");

        std::string args = s.substr(start + 1, end - start - 1);
        auto comma = args.find(",");
        if (comma == std::string::npos)
            throw std::invalid_argument("Replace must contain two comma-separated arguments");

        std::string from = args.substr(0, comma);
        std::string to = args.substr(comma + 1);
        transformations.push_back(std::make_shared<Replace>(from, to)); 
    }
    else {
        throw std::invalid_argument("Invalid transformation");
    }
}

std::string CompositeTransformation::transform(const std::string& text) const {
    if (transformations.size() == 0) return text;

    std::string res = text;
    for (int i = 0; i < transformations.size(); i++) {
        res = transformations[i]->transform(res);
    }
    return res;
}

