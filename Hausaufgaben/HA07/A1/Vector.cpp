#include "Vector.h"
#include <cmath>

Vector::Vector(int dim){
    this->elems = new double[dim];
}
Vector::~Vector(){
    delete this->elems;
    this->elems = nullptr;
}
void Vector::setElem(int pos, double elem){
    this->elems[pos] = elem;
}
double Vector::getElem(int pos){
    return this->elems[pos];
}
int Vector::getDim(){
    return this->dim;
}
void Vector::add(Vector& vec){
    for (int i = 0; i < this->getDim(); i++){
        this->setElem(i, this->getElem(i) + vec.getElem(i));
    }
}
double Vector::innerProd(Vector& vec){
    double res = 0;
    for(int i = 0; i < this->getDim(); i++){
        res += this->getElem(i)*vec.getElem(i);
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