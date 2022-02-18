// Name: Adrian Hammermeister
// Studiengang: Physik
// Matrikelnr.: 221200260
#include <iostream>
int main(){

    // NOT
    std::cout << "x \t\tNOT x" << std::endl;
    for (int x = 0; x <= 1; x++){
        std::cout << x << "\t\t  " << !x << std::endl;
    }
    std::cout << "\nx  y\t\tx XOR y" << std::endl;
    for (int x = 0; x <= 1; x++){
        for (int y = 0; y <= 1; y++){
            if (x == y){
                std::cout << x << "  " << y << "\t\t   " << 0 << std::endl;
            } else {
                std::cout << x << "  " << y << "\t\t   " << 1 << std::endl;
            }
        }
    }
    std::cout << "\nx  y  z\t\t(x NAND y) NAND z" << std::endl;
    for (int x = 0; x <= 1; x++){
        for (int y = 0; y <= 1; y++){
            for (int z = 0; z <= 1; z++){
                std::cout << x << "  " << y << "  " << z << "\t\t       " << (!(!(x && y) && z)) << std::endl;
            }
        }
    }
    return 0;
}