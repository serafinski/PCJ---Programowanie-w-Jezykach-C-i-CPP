//
// Created by tsera on 30.05.2022.
//

#ifndef ZAJCIA9_RECT_H
#define ZAJCIA9_RECT_H


class Rect {
    double a=1;
    double b;
public:
    Rect();

    Rect(double s);

    Rect(double a, double b);

    double getA() const;

    double getB() const;

    double getDiagonal();

    double getArea();

    bool isLargerThan(const Rect&);

    void info();
};


#endif //ZAJCIA9_RECT_H
