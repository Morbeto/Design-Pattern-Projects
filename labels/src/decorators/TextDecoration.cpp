#include "decorators/TextDecoration.h"
TextTransformationDecorator::TextTransformationDecorator(
    std::shared_ptr<Label> label,
    std::shared_ptr<Transformation> trans
) : LabelDecoratorBase(std::move(label)), trans(std::move(trans)) {}

std::string TextTransformationDecorator::getText() const {
    return this->trans->transform(this->label->getText());
}