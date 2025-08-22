#include"decorators/RandomDecoration.h"

RandomTextDecoration::RandomTextDecoration(
    std::vector<std::shared_ptr<Transformation>> trans,
    std::shared_ptr<Label> label
) : LabelDecoratorBase(std::move(label)), transformations(std::move(trans)) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

std::string RandomTextDecoration::getText() const {
    if (transformations.empty()) {
        return label->getText();
    }

    auto randomTransform = getRandomTransformation();
    std::string text = label->getText();
    return randomTransform->transform(text);
}

std::shared_ptr<Transformation> RandomTextDecoration::getRandomTransformation() const {
    size_t index = std::rand() % transformations.size();
    return transformations[index];
}