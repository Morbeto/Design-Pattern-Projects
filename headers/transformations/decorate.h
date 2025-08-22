#pragma once
#include"trans.h"

class Decorate : public Transformation {
public:

	std::string transform(const std::string& og) const override {
		return "-={ " + og + " }=-";
	}
};

