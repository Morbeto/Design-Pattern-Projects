#include "labels/SimpleLabel.h"
#include<ctime>
#include<iostream>
#include <string>

class ProxyLabel : public Label {
private:
	mutable std::unique_ptr<Label> label;
	mutable bool initialized = false;
	mutable int callCount = 0;
	int timeoutLimit;
public:
	ProxyLabel(int timeout);
	
	std::string getText() const override;
private:
	void setTimeout(int);
};
