#include <iostream>
#include "Point.h"
#include "Rect.h"
#include "Letters.h"

//main podany przez prowadzącą
int main() {
    /*
    Point p;
    Point q(1);
    Point r(1,2);
    p.transXY(5,6);
    q.transX(-1).transY(-1).transXY(2,2);
    r.setX(10).transY(-8);
    std::cout << Point::dist(p,q) << std::endl;
    std::cout << Point::dist(p,r) << std::endl;
     */

    /*
    Rect a(5);
    Rect b(4,3);
    std::cout<<"A: "<<a.getArea()<<" " <<a.getDiagonal()<<" "<<std::endl;
    a.info();
    std::cout<<"B: "<<b.getArea()<<" "<<b.getDiagonal()<<" "<<std::endl;
    b.info();
    std::cout<<a.isLargerThan(b);
     */
    const char* text =
            "To be, or not to be- that is the questiona\n:"
            "Whether 'tis nobler in the mind to suffer\n"
            "The slings and arrows of outrageous fortune\n"
            "Or to take arms against a sea of troubles,\n"
            "And by opposing end them.";
    Letters lett(text);
    std::cout << "Most frequent letter: "
              << lett.getMostFrequent() << std::endl;
    std::cout << "Number of different letters: "
              << lett.numOfDifferent() << std::endl;
    std::cout << "Frequency table of all letters:\n";
    std::cout << std::endl;
    lett.printFrequencies();
}
