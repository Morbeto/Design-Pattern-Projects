#pragma once
#include"trans.h"

class Capitalize : public Transformation {
public:

	std::string transform(const std::string& og)const  override {
		std::string temp = og;
		if (temp[0] >= 'a' && temp[0] <= 'z') {
			temp[0] -= 32;
		}
		return temp;
	}
};