#pragma once
#include"TextDecoration.h"
#include"transformations/trans.h"
#include<memory>
#include<vector>
class RandomTextDecoration : public LabelDecoratorBase {
private:
    std::vector<std::shared_ptr<Transformation> > transformations;
    mutable size_t currentIndex = 0;
public:
    RandomTextDecoration(std::vector<std::shared_ptr<Transformation>> transforms, std::shared_ptr<Label> label);
    ~RandomTextDecoration() = default;

    std::string getText() const override;
private:
    std::shared_ptr<Transformation> getRandomTransformation() const;
};
