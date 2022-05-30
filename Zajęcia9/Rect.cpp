//
// Created by tsera on 30.05.2022.
//

#include "Rect.h"
#include <iostream>
#include <cmath>

using std::cout; using std::endl; using std::sqrt;

//konstruktor domyślny, tworzący kwadrat o boku 1;
Rect::Rect() {}

//konstruktor jednoparametrowy, tworzący kwadrat o podanym boku;
Rect::Rect(double s):a(s),b(s) {}

//konstruktor dwuparametrowy (dwa boki);
Rect::Rect(double a, double b) : a(a), b(b) {}

//metody getA() i getB() zwracające odpowiednie boki prostokąta;
double Rect::getA() const {
    return a;
}

double Rect::getB() const {
    return b;
}

//metodę getDiagonal() zwracającą długość przekątnej prostokąta;
double Rect::getDiagonal() {
    return sqrt(pow(a,2)+ pow(b,2));
}

//metodę getArea() zwracającą pole powierzchni prostokąta;
double Rect::getArea() {
    return a*b;
}

//metodę isLargerThan(const Rect&), która zwraca true gdy ten prostokąt ma większe pole
// od tego przekazanego w argumencie, a false w przeciwnym przypadku;
bool Rect::isLargerThan(const Rect& x) {
    return (getA()>x.getA()*x.getB());
}

//metodę info(), która wypisuje informację o prostokącie,
// na przykład w formie [Rect[2,3]] (słowo ’Rect’ i w nawiasach kwadratowych długości boków).
void Rect::info() {
    cout<<"Rect["<<a<<","<<b<<"]"<<endl;
}
