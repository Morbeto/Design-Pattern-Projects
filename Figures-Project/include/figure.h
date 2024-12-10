#ifndef FIGURE_H
#define FIGURE_H
#include <memory>
#include"to_string.h"
class figure : public string_convertible {
public:
    virtual double perimeter() const = 0;
    virtual figure* clone() const = 0;
    virtual ~figure() = default;
};

#endif // FIGURE_H
