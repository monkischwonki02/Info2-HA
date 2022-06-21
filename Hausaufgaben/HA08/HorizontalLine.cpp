#include "HorizontalLine.h"

void HorizontalLine::draw() const {
	for (int i = 0; i < this->length; i++) {
		std::cout << "*";
	}
}