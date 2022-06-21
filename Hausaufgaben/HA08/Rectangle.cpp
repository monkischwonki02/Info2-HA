#include "Rectangle.h"
#include "HorizontalLine.h"
void Rectangle::draw() const {
	HorizontalLine hl(this->width);
	hl.draw(); std::cout << std::endl;
	for (int i = 0; i < this->height-2; i++) {
		std::cout << "*";
		for (int i = 0; i < this->width - 2; i++) {
			std::cout << " ";
		}
		std::cout << "*" << std::endl;
	}
	hl.draw();
}