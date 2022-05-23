#include <iostream>

class Vector{
    private:
        int dim;
        double* elems;
    public:
        Vector(int dim): dim(dim){};
        ~Vector(){};
        void setElem(int pos, double elem);
        double getElem(int pos);
        int getDim();
        void add(Vector& vec);
        double innerProd(Vector& vec);
        void mult(double s);
        double calcNorm();

};