#pragma once
#include <memory>
#include <string>
#include <vector>
#include "../headers/transformations/capitalize.h"
#include "../headers/transformations/leftTrim.h"
#include "../headers/transformations/rightTrim.h"
#include "../headers/transformations/normalizeSpace.h"
#include "../headers/transformations/decorate.h"
#include "../headers/transformations/censor.h"
#include "../headers/transformations/replace.h"
#include"../headers/transformations/CompositeTrans.h"

class TransformationFactory {
public:
    TransformationFactory() = default;
    ~TransformationFactory() = default;

    static std::shared_ptr<Transformation> createCapitalize();
    static std::shared_ptr<Transformation> createLeftTrim();
    static std::shared_ptr<Transformation> createRightTrim();
    static std::shared_ptr<Transformation> createCensor(const std::string& wordToCensor);
    static std::shared_ptr<Transformation> createDecorate();
    static std::shared_ptr<Transformation> createNormalizeSpace();
    static std::shared_ptr<Transformation> createReplace(const std::string& target, const std::string& replacement);
    static std::shared_ptr<Transformation> createComposite(const std::string& transformations);
};