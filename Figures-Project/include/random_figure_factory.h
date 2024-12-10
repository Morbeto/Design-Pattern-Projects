#ifndef RANDOM_FIGURE_FACTORY_H
#define RANDOM_FIGURE_FACTORY_H
#include"figure_factory.h"
class RandomFigureFactory : public figure_factory {
public:
	RandomFigureFactory();

	figure* create() override;
};
#endif // !RANDOM_FIGURE_FACTORY_H
