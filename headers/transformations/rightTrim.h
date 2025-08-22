#pragma once
#include"trans.h"

class RightTrim : public Transformation {
public:

	std::string transform(const std::string& og) const override {
		std::string res = og;
		if (!res.empty() && res[res.size() - 1] == ' ') {
			res.erase(res.size() - 1);
		}
		return res;
	}
};