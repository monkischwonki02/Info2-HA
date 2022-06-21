#include "VerticalLine.h"

void VerticalLine::draw() const{
	for (int i = 0; i < this->length; i++) {
		std::cout << "*" << std::endl;
	}
}