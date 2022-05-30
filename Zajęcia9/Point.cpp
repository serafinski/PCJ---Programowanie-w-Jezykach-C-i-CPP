//
// Created by tsera on 30.05.2022.
//

#include "Point.h"

//KONSTRUKTORY

//konstruktor domyślny tworzący punkt (0, 0)
Point::Point():x(0),y(0) {}

//jednoparametrowy konstruktor tworzący punkt o obu współrzędnych równych przekazanej do konstruktora wartości;
Point::Point(double z):x(z),y(z) {}

//konstruktor dwuparametrowy (dwie współrzędne);
Point::Point(double x, double y) : x(x), y(y) {}

//GETTERY - bez zmian
//metody getX() i getY() zwracające wartości odpowiednich współrzędnych
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

//SETTERY — należy wprowadzić zmiany, ponieważ zwracamy przez referencje
//metody setX(double) i setY(double) zmieniające wartości odpowiednich współrzędnych
Point &Point::setX(double d) {
    x = d;
    return *this;
}

Point &Point::setY(double e) {
    y = e;
    return *this;
}
//METODY

//metody transX(double) i transY(double) dodające przekazaną wartość do odpowiednich współrzędnych punktu (translacja)
//Te metody wyglądają tak, bo zwracamy przez referencje
Point &Point::transX(double a) {
    x+=a;
    return *this;
}

Point &Point::transY(double b) {
    y+=b;
    return *this;
}

//metodę transXY(double,double) dokonującą translacji punktu o podane wartości;
Point &Point::transXY(double a, double b) {
    transX(a);
    transY(b);
    return *this;
}
//statyczną funkcję składową dist zwracającą odległość pomiędzy dwoma punktami przekazanymi przez referencje
double Point::dist(const Point &p, const Point &q) {
    //z pitagorasa
    return sqrt(pow(p.getX() - q.getX(),2)+ pow(q.getY()-p.getY(),2));
}


