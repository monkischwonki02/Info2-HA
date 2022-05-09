#include "Fraction.h"
#include <cmath>

// Euklid
int ggt(int z, int n){
    int r;
    do{
        if (z < n){
            r = z;
            z = n; 
            n = r;
        }
        r = z % n;
        if (r != 0){
            z = n;
            n = r;
        }
    }while(r!=0);

    return n;
}

// Getter + Setter
const int Fraction::getDenominator(){
    return this->denominator;
}
void Fraction::setDenominator(int n){
    this->denominator = n;
}

const int Fraction::getNumerator(){
    return this->numerator;
}
void Fraction::setNumerator(int z){
    this->numerator = z;
}

// Calculations
void Fraction::add(Fraction& b){  
    this->setNumerator((this->getNumerator()*b.getDenominator()) + (this->getDenominator()*b.getNumerator()));
    this->setDenominator(this->getDenominator() * b.getDenominator());
}

void Fraction::reduce(){
    int t;
    if (this->getNumerator() % this->getDenominator() == 0){
        this->setDenominator(1);
        this->setNumerator(this->getNumerator() / this->getDenominator());
    } else {
        while(ggt(abs(this->getNumerator()), abs(this->getDenominator())) != 1){
            t = ggt(abs(this->getNumerator()), abs(this->getDenominator()));
            this->setNumerator(this->getNumerator() / t);
            this->setDenominator(this->getDenominator() / t);
        }
    }

}

double Fraction::decimal(){
   return (double) this->getNumerator() / this->getDenominator();
}