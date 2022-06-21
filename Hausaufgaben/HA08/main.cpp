#include "HorizontalLine.h"
#include "VerticalLine.h"
#include "Rectangle.h"

int main() {

	Shape* shapes[]{ new VerticalLine(5), new HorizontalLine(3), new Rectangle(5,3), new HorizontalLine(1), new Rectangle(10,3)};

	for (int i = 0; i < 5; i++) {
		shapes[i]->draw();
		std::cout << std::endl;
		delete shapes[i];
	}

	return 0;
}