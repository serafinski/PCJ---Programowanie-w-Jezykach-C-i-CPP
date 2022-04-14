#include <iostream>

void fun(double& a, double& b, double& c){
    double approx = (a+b+c)/3;
    double *pointer = &approx;
    a = a - *pointer;
    b = b - *pointer;
    c = c - *pointer;
}

void fun(double* a, double* b, double* c){
    double approx = (*a+*b+*c)/3;
    *a = *a - approx;
    *b = *b - approx;
    *c = *c - approx;
}

int main() {

    double a = 5, b = 10, c = 15;

    double *pa, *pb, *pc;

    pa = &a;
    pb = &b;
    pc = &c;


    std::cout << a << " " << b << " " << c << std::endl;

    //nwm, czy tu nie powinno być bez &... -> na podstawie odpowiedzi prowadzącej
    fun(&a,&b,&c);
    std::cout << a << " " << b << " " << c << std::endl;

    //nwm, czy tu nie powinno być &pa itd... -> na podstawie odpowiedzi prowadzącej
    fun(pa,pb,pc);
    std::cout << a << " " << b << " " << c << std::endl;
}