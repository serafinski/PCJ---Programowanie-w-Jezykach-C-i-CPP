//
// Created by tsera on 11.06.2022.
//

#include <iostream>
#include "Point_Class.h"
using namespace std;

Point_Class::Point::Point(int x, int y) : x(x), y(y) {}

void printPoint(const Point_Class::Point *p) {
    cout << "(" << p->x << "," << p->y << ")";
}
