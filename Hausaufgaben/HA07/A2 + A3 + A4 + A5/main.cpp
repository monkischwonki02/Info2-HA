#include "Vector.h"
#include <iostream>

int main() {

	Vector u(3); u[0] = 3; u[1] = 4; u[2] = 6;
	Vector v(3); v[0] = 2; v[1] = 1; v[2] = 3;
	Vector w(3); w[0] = 0; w[1] = 0; w[2] = 0;
	
	// Vektoraddition

	w = u + v;
	std::cout << w << std::endl;
	w += u;
	std::cout << w << std::endl;
	w = u * 2.0;
	std::cout << w << std::endl;

	// Skalarprodukt
	double f = u * w;
	std::cout << f << std::endl;
	return 0;
}
