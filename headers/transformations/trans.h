#pragma once
#include<iostream>
#include<cstring>
#include <cctype>

class Transformation {
public:
	virtual ~Transformation() = default;

	virtual std::string transform(const  std::string&) const  = 0;

};
