#include"Label.h"

class LabelPrinter {
	static void print(std::shared_ptr<Label> label) {
		std::cout << "Label text: " << label->getText() << '\n';
	}

	static void printWithHelper(std::shared_ptr<Label> label) {
		print(label);

		std::cout << "Help information: " << label->getHelper() << '\n';

	}
};