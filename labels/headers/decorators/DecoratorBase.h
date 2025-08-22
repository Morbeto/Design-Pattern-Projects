#pragma once
#include"../labels/Label.h"
#include <memory>
class Transformation;

class LabelDecoratorBase : public Label {
protected:
    mutable std::shared_ptr<Label> label;

public:
    explicit LabelDecoratorBase(std::shared_ptr<Label> label)
        : label(std::move(label)) {}

    std::string getText() const override {
        return label->getText();
    }

    Label* getLabel() const {
        return label.get();
    }

    static std::shared_ptr<Label> removeDecorator(std::shared_ptr<Label> label, std::shared_ptr<LabelDecoratorBase> toRemove) {
        if (!label) {
            return nullptr;
        }
        std::shared_ptr<LabelDecoratorBase> current = std::dynamic_pointer_cast<LabelDecoratorBase>(label);
        std::shared_ptr<LabelDecoratorBase> previous = nullptr;
        while (current) {
            if (current == toRemove) {
                if (previous) {
                    previous->label = current->label;
                }
                else {
                    label = current->label;
                }
                break;
            }
            previous = current;
            current = std::dynamic_pointer_cast<LabelDecoratorBase>(current->label);
        }
        return label;
    }

    virtual Transformation* getTransformation() const { return nullptr; }
};
