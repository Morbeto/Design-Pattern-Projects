#pragma once
#include"Label.h"

class SimpleLabel : public Label {
protected:
	std::string textInfo;
public:
	SimpleLabel(std::string info = " ") :textInfo(info) {};

	std::string getText() const override { return textInfo; }
};

