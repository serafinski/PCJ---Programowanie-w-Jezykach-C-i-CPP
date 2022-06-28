#include <iostream>
#include "Car.h"
#include "Cabriolet.h"

int main() {
    cout << "###SAMOCHOD###" << endl;
    Car car(200,0,10);
    cout << car << endl;
    car.addPetrol(50);
    car.drive(10,300);

    cout << "\n###KABRIOLET###" << endl;
    Cabriolet cabriolet(300,0,15, false);
    cout << cabriolet << endl;
    cabriolet.setIsRoofOpen(true);
    cabriolet.addPetrol(50);
    cabriolet.drive(150,300);
}
