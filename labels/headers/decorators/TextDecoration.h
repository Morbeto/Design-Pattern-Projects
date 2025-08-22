#pragma once
#include"DecoratorBase.h"
#include"../transformations/trans.h"
class TextTransformationDecorator : public LabelDecoratorBase {
protected:
    std::shared_ptr<Transformation> trans;
public:
    TextTransformationDecorator(std::shared_ptr<Label> label, std::shared_ptr<Transformation> trans);
    ~TextTransformationDecorator() = default;
    std::string getText() const override;

    Transformation* getTransformation() const override {
        return trans.get();
    }
};