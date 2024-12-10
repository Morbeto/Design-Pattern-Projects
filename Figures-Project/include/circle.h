#ifndef CIRCLE_H
#define CIRCLE_H
#include"figure.h"
class Circle : public figure{
private:
	const double radius;

public:
	Circle(double);
	Circle& operator=(const Circle&) = delete;

	double getRadius() const;

	double perimeter() const override;
	std::string to_string() const override;
	Circle* clone() const ;
};


#endif // !CIRCLE_H
