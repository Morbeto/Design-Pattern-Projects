#pragma once
#include"TextDecoration.h"
#include"transformations/trans.h"
#include<memory>
#include<vector>


class CyclingTransformationsDecorator : public LabelDecoratorBase {
private:
	std::vector<std::shared_ptr<Transformation>> transformations;
	mutable size_t currIndex;

	void getNext() const ;
public:
	CyclingTransformationsDecorator(std::vector<std::shared_ptr<Transformation> > transformations, std::shared_ptr<Label> label);
	~CyclingTransformationsDecorator() = default;
	std::string getText() const override;
};




