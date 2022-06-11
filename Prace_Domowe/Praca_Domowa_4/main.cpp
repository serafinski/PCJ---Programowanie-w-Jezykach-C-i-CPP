#include <iostream>
#include "Rect_Class.h"

using std::cout;

int main() {
    using std::cout;
    Rect_Class::Rect ra{{-1,-2},{ 1, 1}};
    Rect_Class::Rect rb{{ 0, 0},{ 5, 1}};
    Rect_Class::Rect rc{{ 2,-1},{ 4, 2}};
    Rect_Class::Rect rd{{ 1,-3},{ 4, 3}};
    cout << std::boolalpha << "Do intersect:\n";
    cout << "ra rb ? " << doIntersect(&ra,&rb) << '\n';
    cout << "ra rc ? " << doIntersect(&ra,&rc) << '\n';
    cout << "rb rd ? " << doIntersect(&rb,&rd) << '\n';
    cout << "Intersections:\n";
    cout << "ra & rb: ";
    printRect(intersection(ra,rb));
    cout << "rb & rc: ";
    printRect(intersection(rb,rc));
    cout << "rc& rd: ";
    printRect(intersection(rc,rd));
    cout << "ra & rd: ";
    printRect(intersection(ra,rd));
}