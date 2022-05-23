#include "Vector.h"
#include <cmath>
#include <cassert>

Vector::Vector(int dim) : dim(dim) {
    this->elems = new double[dim];
}
// Copy-Constructor - A2
Vector::Vector(const Vector& vec) {
    elems = new double[vec.getDim()];
    dim = vec.getDim();
    for (int i = 0; i < vec.getDim(); i++) {
        elems[i] = vec.getElem(i);
    }
}
// Destructor - A2
Vector::~Vector() {
    std::cout << "Destructor" << std::endl;
    delete this->elems;
    this->elems = nullptr;
}
void Vector::setElem(int pos, double elem) {
    this->elems[pos] = elem;
}
double Vector::getElem(int pos) const {
    return this->elems[pos];
}
int Vector::getDim() const{
    return this->dim;
}
void Vector::add(Vector& vec) {
    for (int i = 0; i < this->getDim(); i++) {
        this->setElem(i, this->getElem(i) + vec.getElem(i));
    }
}
double Vector::innerProd(Vector& vec) {
    double res = 0;
    for (int i = 0; i < this->getDim(); i++) {
        res += this->getElem(i) * vec.getElem(i);
    }
    return res;
}

// euklidean norm
double Vector::calcNorm() {
    double res = 0;
    for (int i = 0; i < this->getDim(); i++) {
        res += this->innerProd(*this);
    }
    return sqrt(res);
}

// Zuweisungsoperator - A2
Vector& Vector::operator= (Vector vec) {
    std::swap(this->dim, vec.dim);
    std::swap(this->elems, vec.elems);
    return *this;
}


// [] - Operator - A3 
double& Vector::operator [](int pos) {
    assert(pos < dim);
    return elems[pos];
}



// << - Operator - A4
std::ostream& operator << (std::ostream& o, Vector& a) {
    o << "[";
    for (int i = 0; i < a.getDim() - 1; i++) {
        o << a[i] << " , ";
    }
    return o << a[a.dim - 1] << "]";
}


// ---------------------- Aufgabe 5 ------------------------
// * (Skalare Multiplikation)
Vector Vector::operator*(double num)
{
    Vector vec = *this;
    for (int i = 0; i < vec.getDim(); i++) {
        vec[i] *= num;
    }
    return vec;
}

// innerProd
double Vector::operator * (Vector& vec) {
    return innerProd(vec);
}

// + Operator
Vector Vector::operator+(Vector& vec) {
    Vector temp = vec;
    temp.add(*this);
    return temp;
}

// += Operator
Vector& Vector::operator+= (Vector vec) {
    for (int i = 0; i < vec.getDim(); i++) {
        (* this)[i] += vec[i];
    }
    return *this;
}
