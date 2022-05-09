#include <cmath>

class Fraction{
    private: 
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator) {
            if (denomitor != 0){
                this->numerator = numerator;
                this->denominator = denominator;
            } else {
                this->numerator = numerator;
                this->denominator = 1;
            }
        }
        Fraction(): numerator(0), denominator(1){};

        // Setter - Getter
        const int getDenominator();
        void setDenominator(int n);
        const int getNumerator();
        void setNumerator(int z);

        // calculations
        void add(Fraction& b);
        void reduce();
        double decimal();


};