#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"figure.h"
class Rectangle: public figure{
private:
	const double height, width;

public:
	Rectangle(double, double);

	Rectangle& operator=(const Rectangle&) = delete;

	double getHeight() const;
	double getWidth() const;

	std::string to_string() const override;
	double perimeter() const override;
	Rectangle* clone() const ;
}; 

#endif