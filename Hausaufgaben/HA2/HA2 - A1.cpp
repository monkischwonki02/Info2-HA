#include <iostream>
#include <cmath>

struct QuadEquation{
    double a;
    double b;
    double c;
    double* lsg = nullptr;
    int lsgAnzahl = 0;
};

void solveQuad(QuadEquation& q){
    double D = (double) pow(q.b, 2) - (4*q.a*q.c);
    if (D < 0){
        q.lsgAnzahl = 0;
    }
    else if (D = 0){
        q.lsgAnzahl = 1;
        q.lsg = new double(q.lsgAnzahl);
        q.lsg[0] = (double)- q.b / (2* q.a);
    }
    else {
        q.lsgAnzahl = 2;
        q.lsg = new double(q.lsgAnzahl);
        q.lsg[0] = (double)(-q.b + sqrt(pow(q.b, 2) - (4*q.a*q.c)))/ (2*q.a);
        q.lsg[1] = (double)-(q.b + sqrt(pow(q.b, 2) - (4*q.a*q.c)))/ (2*q.a);

    }

}

void printQuad(QuadEquation& q){
    for (int i = 0; i < q.lsgAnzahl; i++){
        std::cout << q.lsg[i] << std::endl;
    }
}

int main(){
    QuadEquation q = {1,1,1};
    solveQuad(q);
    printQuad(q);
    return 0;
}