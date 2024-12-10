#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H
#include"random_figure_factory.h"
#include"stream_factory.h"
class AbstractFactory {
public:
	figure_factory* getFactory(std::string);
};
#endif // !ABSTRACT_FACTORY_H

