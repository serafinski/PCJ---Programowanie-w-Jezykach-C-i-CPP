//
// Created by tsera on 11.06.2022.
//

#ifndef PRACA_DOMOWA_4_RECT_CLASS_H
#define PRACA_DOMOWA_4_RECT_CLASS_H
#include "Point_Class.h"

class Rect_Class {
public:
    struct Rect {
        Rect(const Point_Class::Point &ll, const Point_Class::Point &ur);

        Point_Class::Point LL, UR;
    };
};

void printRect(const Rect_Class::Rect& r);

bool doIntersect(const Rect_Class::Rect* r1, const Rect_Class::Rect* r2);

Rect_Class::Rect intersection(const Rect_Class::Rect& r1, const Rect_Class::Rect& r2);

#endif //PRACA_DOMOWA_4_RECT_CLASS_H
