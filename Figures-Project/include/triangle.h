#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"figure.h"
class Triangle : public figure {
private:
	const double sideOne, sideTwo, sideThree;
public:
	Triangle(double, double, double);
	Triangle& operator=(const Triangle&) = delete;

	double getSideOne() const;
	double getSideTwo() const;
	double getSideThree() const;

	std::string to_string() const override;
	double perimeter() const override;
	Triangle* clone() const ;

};
#endif // TRIANGLE_H