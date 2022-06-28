//
// Created by tsera on 24.06.2022.
//

#ifndef PRACA_DOMOWA_5_CABRIOLET_H
#define PRACA_DOMOWA_5_CABRIOLET_H

#include "Car.h"

class Cabriolet : public Car {
private:
    bool IsRoofOpen;
public:
    Cabriolet(double maxSpeed, double petrol, double fuelCon, bool isRoofOpen);

    void setIsRoofOpen(bool isRoofOpen);

    void drive(double speed, double distance) override;

    friend ostream& operator<<(ostream &str, const Cabriolet &c);
};


#endif //PRACA_DOMOWA_5_CABRIOLET_H
