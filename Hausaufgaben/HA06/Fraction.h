#include <cmath>

class Fraction{
    private: 
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator): denominator(denominator), numerator(numerator) {}
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