//
// Created by tsera on 24.06.2022.
//

#include "Cabriolet.h"

Cabriolet::Cabriolet(double maxSpeed, double petrol, double fuelCon, bool isRoofOpen) : Car(maxSpeed, petrol, fuelCon),
                                                                                        IsRoofOpen(isRoofOpen) {}

void Cabriolet::setIsRoofOpen(bool isRoofOpen) {
    IsRoofOpen = isRoofOpen;
}

void Cabriolet::drive(double speed, double distance) {
    if(IsRoofOpen){
        Car::drive(speed*0.9,distance);
    }
    else
        Car::drive(speed,distance);
}

ostream &operator<<(ostream &str, const Cabriolet &c) {
    cout << static_cast<const Car&>(c) << "\nCzy ma otwarty dach: " << c.IsRoofOpen << endl;
    return str;
}
