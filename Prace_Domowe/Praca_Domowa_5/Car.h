//
// Created by tsera on 24.06.2022.
//

#ifndef PRACA_DOMOWA_5_CAR_H
#define PRACA_DOMOWA_5_CAR_H
#include <iostream>

using std::ostream; using std::cout; using std::endl;

class Car {
public:
    Car(double maxSpeed, double petrol, double fuelCon);

    void addPetrol(double petrol);

    virtual void drive(double speed, double distance);

private:
    double maxSpeed;
    double petrol;
    double fuelCon;

    friend ostream& operator<<(ostream &str, const Car &c);
};


#endif //PRACA_DOMOWA_5_CAR_H
