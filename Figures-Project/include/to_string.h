#ifndef TO_STRING_H
#define TO_STRING_H
#include<iostream>
#include<cstring>
class string_convertible {
public:
	virtual std::string to_string() const = 0;
	virtual ~string_convertible() = default;
};
#endif // !TO_STRING_H
