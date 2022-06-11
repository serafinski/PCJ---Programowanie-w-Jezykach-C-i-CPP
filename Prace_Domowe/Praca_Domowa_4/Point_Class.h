//
// Created by tsera on 11.06.2022.
//

#ifndef PRACA_DOMOWA_4_POINT_CLASS_H
#define PRACA_DOMOWA_4_POINT_CLASS_H


class Point_Class {
public:
    struct Point {
        Point(int x, int y);
        int x, y;
    };
};
void printPoint(const Point_Class::Point* p);

#endif //PRACA_DOMOWA_4_POINT_CLASS_H
