#pragma once
#include <string>

class HelpTextBridge {
public:
	virtual ~HelpTextBridge() = default;

	virtual std::string getHelpText() const = 0;
};


class HelpText:public HelpTextBridge {
private:
	std::string helper;
public:
	HelpText(std::string base = "") : helper(base) {};

	std::string getHelpText() const override {
		return helper;
	}


};