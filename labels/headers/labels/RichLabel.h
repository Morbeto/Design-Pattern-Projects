#include"SimpleLabel.h"
#include <string>

class RichLabel : public SimpleLabel {
private:
	std::string labelColor;
	std::string fontStyle;
	int fontSize;
public:
	RichLabel(std::string info = " ", std::string color = "black", std::string font = "Aerial", int size = 12) : SimpleLabel(info), labelColor(color), fontStyle(font), fontSize(size) {};

	std::string getColor() const { return labelColor;  }
	std::string getStyle() const { return fontStyle;  }
	int getSize() const { return fontSize; }

	std::string getText() const override {
		return "Text: " + SimpleLabel::getText() + '\n' +
			"Color: " + labelColor + '\n' + 
			"Style: "+ fontStyle + '\n' + 
			"Size: " + std::to_string(fontSize) + '\n';
	}

};