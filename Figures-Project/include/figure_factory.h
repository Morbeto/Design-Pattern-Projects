#ifndef FIGURE_FACTORY_H
#define FIGURE_FACTORY_H
#include"triangle.h"
#include"circle.h"
#include"rectangle.h"
class figure_factory {
public:
	virtual figure* create() = 0;
	virtual ~figure_factory() = default;
};

#endif // !FIGURE_FACTORY_H
