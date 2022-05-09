#include "Fraction.h"
#include <iostream>

int main(){

    Fraction a(1,2);
    Fraction b(3,10);
    std::cout << "a = " <<  a.getZaehler() << " / " << a.getNenner() << std::endl; // Ausgabe: 1 / 2
    std::cout << "b = " <<  b.getZaehler() << " / " << b.getNenner() << std::endl << std::endl; // Ausgabe: 3 / 10
    a.add(b);
    std::cout << "a = " <<  a.getZaehler() << " / " << a.getNenner() << std::endl << std::endl; // Ausgabe: 16 / 20
    a.reduce();
    std::cout << "a = " <<  a.getZaehler() << " / " << a.getNenner() << std::endl; // Ausgabe: 4 / 5
    std::cout << "a = " << a.decimal() << std::endl; // Ausgabe: 0.8
    return 0;
}