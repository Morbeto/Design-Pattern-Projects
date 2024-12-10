#ifndef STREAM_FACTORY_H
#define STREAM_FACTORY_H
#include"figure_factory.h"
#include"string_to_figure.h"
#include <istream>
class StreamFigureFactory : public figure_factory {
private:
	string_to_figure creator;
	std::istream& stream;
public:
	StreamFigureFactory(std::istream& inputStream)
		: stream(inputStream), creator() {};

	figure* create() override;

	StreamFigureFactory(const StreamFigureFactory&) = delete;
	StreamFigureFactory& operator=(const StreamFigureFactory&) = delete;
};

#endif
