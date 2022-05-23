#pragma once
#include <iostream>

class Vector {
private:
    int dim;
    double* elems;
public:
    Vector(int dim);
    // Copy-Constructor
    Vector(const Vector& vec); // A2
    ~Vector(); // A2
    void setElem(int pos, double elem);
    double getElem(int pos) const;
    int getDim()const;
    void add(Vector& vec);
    double innerProd(Vector& vec);
    double calcNorm();
    Vector& operator = (Vector vec); // A2

    // A3
    double& operator [] (int pos);

    friend std::ostream& operator << (std::ostream& o, Vector& a); // A4

    // A5
    Vector operator *(double num);
    Vector operator + (Vector& vec);
    Vector& operator += (Vector vec);
    double operator * (Vector& vec);
};
