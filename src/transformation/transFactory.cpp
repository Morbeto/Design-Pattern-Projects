#include "transformations/transFactory.h"

std::shared_ptr<Transformation> TransformationFactory::createCapitalize() {
    return std::make_shared<Capitalize>();
}

std::shared_ptr<Transformation> TransformationFactory::createLeftTrim() {
    return std::make_shared<LeftTrim>();
}

std::shared_ptr<Transformation> TransformationFactory::createRightTrim() {
    return std::make_shared<RightTrim>();
}

std::shared_ptr<Transformation> TransformationFactory::createCensor(
    const std::string& wordToCensor) {
    return std::make_shared<Censor>(wordToCensor);
}

std::shared_ptr<Transformation> TransformationFactory::createDecorate() {
    return std::make_shared<Decorate>();
}

std::shared_ptr<Transformation> TransformationFactory::createNormalizeSpace() {
    return std::make_shared<Normalize>();
}

std::shared_ptr<Transformation> TransformationFactory::createReplace(
    const std::string& target, const std::string& replacement) {
    return std::make_shared<Replace>(target, replacement);
}

std::shared_ptr<Transformation> TransformationFactory::createComposite(const std::string& transformations) {
    return std::make_shared<CompositeTransformation>(transformations);
}