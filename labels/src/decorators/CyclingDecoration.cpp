#include"decorators/CyclingDecoration.h"

CyclingTransformationsDecorator::CyclingTransformationsDecorator(
    std::vector<std::shared_ptr<Transformation>> trans,
    std::shared_ptr<Label> label
) : LabelDecoratorBase(label), transformations(std::move(trans)), currIndex(0) {}

std::string CyclingTransformationsDecorator::getText() const {
    if (transformations.empty()) {
        return label->getText();
    }

    std::string originalText = label->getText();
    std::string transformed = transformations[currIndex]->transform(originalText);

    const_cast<CyclingTransformationsDecorator*>(this)->getNext();//питах чата за съвет

    return transformed;
}

void CyclingTransformationsDecorator::getNext() const{
    if (currIndex == transformations.size() - 1) {
        currIndex = 0;
    }
    else {
        currIndex++;
    }
}