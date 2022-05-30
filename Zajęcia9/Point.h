//
// Created by tsera on 30.05.2022.
//

#ifndef ZAJCIA9_POINT_H
#define ZAJCIA9_POINT_H


#include <iostream>
#include <cmath>
class Point {
    double x, y;
public:
    //KONSTRUKTORY
    Point();
    Point(double z);
    Point(double x, double y);

    //GETTERY - bez zmian
    double getX() const;
    double getY() const;


    //SETTERY — należy wprowadzić zmiany, ponieważ zwracamy przez referencje
    Point& setX(double d);
    Point& setY(double e);

    //METODY
    //Te metody wyglądają tak, bo zwracamy przez referencje
    Point& transX(double a);
    Point& transY(double b);

    Point& transXY(double a, double b);

    //statyczna
    static double dist(const Point& p,const Point& q);
};
#endif //ZAJCIA9_POINT_H
