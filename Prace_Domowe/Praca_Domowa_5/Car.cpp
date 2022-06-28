//
// Created by tsera on 24.06.2022.
//

#include "Car.h"

Car::Car(double maxSpeed, double petrol, double fuelCon) : maxSpeed(maxSpeed), petrol(petrol), fuelCon(fuelCon) {}

void Car::drive(double speed, double distance) {
    if(speed > maxSpeed){
        speed=maxSpeed;
    }

    double nailepozwala = 100*petrol/fuelCon;

    double nailepozwalapredkosc = 100*petrol/(1.2*fuelCon);

    double faktycznapredkosc = speed/maxSpeed;

    if((faktycznapredkosc>0.8) || faktycznapredkosc<0.3){
        cout << endl;
        cout << "Jedzie z predkoscia: " << speed <<"km/h" << endl;
        cout << "Ile kilometrow pozwala przejechac obecny stan: " << nailepozwala  << "km"<< endl;

        if(distance>nailepozwalapredkosc){
            cout << "\nPrzejechal: " << nailepozwalapredkosc << "km!"<< endl;
            cout << "Spalil: " << petrol << " litrow paliwa!" << endl;
            cout << "Pozostalo: " << petrol-petrol << " litrow paliwa!" << endl;
        }
        else{
            cout << "\nPrzejechal calosc - " << distance << "km!" << endl;
            cout << "Spalil: " << distance*(1.2*fuelCon)/100 << " litrow paliwa!" << endl;
            cout << "Pozostalo: " << petrol-(distance*(1.2*fuelCon)/100) << " litrow paliwa!" << endl;
        }
    }
    else{
        cout << endl;
        cout << "Jedzie z predkoscia: " << speed <<"km/h" << endl;
        cout << "Ile kilometrow pozwala przejechac obecny stan: " << nailepozwala  << "km"<< endl;

        if(distance > nailepozwala){
            cout << "\nPrzejechal: " << nailepozwala << "km!"<< endl;
            cout << "Spalil: " << petrol << " litrow paliwa!" << endl;
            cout << "Pozostalo: " << petrol-petrol << " litrow paliwa!" << endl;
        }
        else{
            cout << "\nPrzejechal calosc - " << distance << "km!" << endl;
            cout << "Spalil: " << distance*fuelCon/100 << " litrow paliwa!" << endl;
            cout << "Pozostalo: " << petrol - (distance*fuelCon/100) << " litrow paliwa!" << endl;
        }
    }
}

void Car::addPetrol(double petrol) {
    this->petrol+=petrol;
    cout << "\nWlano " << petrol << "l paliwa" <<endl;
}

ostream &operator<<(ostream &str, const Car &c) {
    cout << "Maksymalna predkosc: " << c.maxSpeed <<"km/h; \nIlosc paliwa: " << c.petrol << "l; \nSrednie spalanie: " << c.fuelCon << "l/100km";
    return str;
}
