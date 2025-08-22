#pragma once
#include"trans.h"

class LeftTrim : public Transformation {
public:
	
	std::string transform(const std::string& og) const override {
		std::string res = og;
		if (!res.empty() && res.front() == ' ') {
			res.erase(0, 1);
		}
		return res;
	}
};

