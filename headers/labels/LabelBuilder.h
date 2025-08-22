#pragma once
#include"RichLabel.h"
#include"ProxyLabel.h"
#include"decorators/CyclingDecoration.h"
#include"decorators/RandomDecoration.h"
#include "../headers/transformations/transFactory.h"
#include"../headers/transformations/CompositeTrans.h"
#include"../headers/labels/LabelPrinter.h"

//dependancy injection ? 
class LabelBuilder {
private:
    std::shared_ptr<Label> label;
	std::unique_ptr<HelpTextBridge> helper;
	std::vector<std::shared_ptr<Transformation>> transformations;
    std::vector<std::shared_ptr<LabelDecoratorBase>> decorators;

public:
    LabelBuilder() = default;


	std::shared_ptr<Label> build(std::istream& in);

	static std::unique_ptr<HelpTextBridge> createHelper(const std::string&) ;
	static std::shared_ptr<Label> createLabel(const std::string&,std::istream&);
	static std::shared_ptr<Transformation> createTransformation(const std::string&);
};