// Name: Adrian Hammermeister
// Studiengang: Physik
// Matrikelnr.: 221200260
#include <iostream>
#include <cmath>


double calcNorm(double x, double y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

bool inCircle(double x, double y) {
    return calcNorm(x, y) <= 1 ? true : false;
}

int main() {

    int n;
    int k = 0;
    std::cout << "Wie viele Elemente sollen erzeugt werden? ";
    std::cin >> n;
    srand(n);
    double** points = new double*[n];
    for (int i = 0; i < n; i++) {
        points[i] = new double[2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {

            points[i][j] = (double)rand() / RAND_MAX;
        }
        if (inCircle(points[i][0], points[i][1])) {
            k++;
        }
    }



    double s = (double)k / n;
    double pi = 4 * s;
    std::cout << k << std::endl;
    std::cout << s << std::endl;
    std::cout << pi << std::endl;

    return 0;
}