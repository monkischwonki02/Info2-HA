#include <iostream>

// A1
double** allocateMatrix(int m, int n) {
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new double[n];
    }

    return matrix;
}

void freeMatrix(double** matrix, int m) {
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete matrix;
    matrix = nullptr;
}

double** readMatrix(int m, int n) {
    double** matrix = allocateMatrix(m, n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "(" << i+1 << "," << j+1 << ") : ";
            std::cin >> matrix[i][j];
        }
    }
    
    return matrix;
}

// m : rows of matrix
// n : coloumns of matrix
void printMatrix(double** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

// A2
// m : rows of matrix
// n : coloumns of matrix
double** transposeMatrix(double** matrix, int m, int n) {
    double** matrixT = allocateMatrix(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrixT[j][i] = matrix[i][j];
        }
    }
    return matrixT;
}

// m : rows of A
// n : coloumns of A
// p : coloumns of B
double** multiplyMatrices(double** A, double** B, int m, int n, int p) {
    double mul = 0;
    double** C = allocateMatrix(m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                mul += A[i][k] * B[k][j];
            }
            C[i][j] = mul;
            mul = 0;
        }
    }
    return C;
}


int main() {

    int m, n;
    std::cout << "Wie viele Zeilen soll die Matrix haben? ";
    std::cin >> m;
    std::cout << "Wie viele Spalten soll die Matrix haben? ";
    std::cin >> n;

    double** A = readMatrix(m, n);
    printMatrix(A, m, n); std::cout << std::endl;
    double** A_T = transposeMatrix(A, m, n);
    printMatrix(A_T, n, m); std::cout << std::endl;
    double** B = multiplyMatrices(A, A_T, m, n, m);
    printMatrix(B, m, m); std::cout << std::endl;
    freeMatrix(A, m);
    freeMatrix(A_T, n);
    freeMatrix(B, m);
    return 0;
}
