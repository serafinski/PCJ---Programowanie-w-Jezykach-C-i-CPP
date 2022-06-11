//
// Created by tsera on 11.06.2022.
//

#include <iostream>
#include "Rect_Class.h"
using namespace std;

Rect_Class::Rect::Rect(const Point_Class::Point &ll, const Point_Class::Point &ur) : LL(ll), UR(ur) {}

void printRect(const Rect_Class::Rect &r) {
    cout << "[";
    printPoint(&r.LL);
    cout << ",";
    printPoint(&r.UR);
    cout << "]" << endl;
}

bool doIntersect(const Rect_Class::Rect *r1, const Rect_Class::Rect *r2) {
    if((r2->LL.x<=r1->UR.x && r1->LL.x<=r2->UR.x) && (r1->LL.y<=r2->UR.y && r2->LL.y<=r1->UR.y)){
        return true;
    }
    else{
        return false;
    }
}

Rect_Class::Rect intersection(const Rect_Class::Rect &r1, const Rect_Class::Rect &r2) {
        Point_Class::Point LL = Point_Class::Point(0,0);
        Point_Class::Point UR = Point_Class::Point(0,0);

        if(doIntersect(&r1,&r2)){
            if(r2.LL.x>=r1.LL.x){
                LL.x=r2.LL.x;
            }
            else {
                LL.x=r1.LL.x;
            }

            if(r2.LL.y>=r1.LL.y){
                LL.y=r2.LL.y;
            }
            else {
                LL.y=r1.LL.y;
            }

            if(r2.UR.x>=r1.UR.x){
                UR.x=r1.UR.x;
            }
            else {
                UR.x=r2.UR.x;
            }

            if(r2.UR.y>=r1.UR.y){
                UR.y=r1.UR.y;
            }
            else {
                UR.y=r2.UR.y;

            }
            if(LL.x>UR.x){
                return Rect_Class::Rect(UR,LL);
            }
            else{
                return Rect_Class::Rect(LL,UR);
            }
        }
        else{
            throw "Error in 'intersection'";
        }
}
