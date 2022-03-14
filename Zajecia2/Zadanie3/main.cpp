#include <iostream>
//pamiętamy o pakiecie cmath, by móc używać funkcji matematycznych — pierwiastkowania i potęgowania
#include <cmath>

//pod zmienną bok będzie rozumiana wartość 16
#define bok 16

double PoleKwadratu(){
    std::cout <<"Pole Kwadratu to: "<< bok * bok <<"cm2"<<std::endl;
    return 0;
}

double PolePowierzchniGraniastoslupaPieciokatnego(double wysokosc){
    std::cout <<"Pole powieszchni Graniastoslupa Pieciokatnego to: "<< 2*(sqrt(25+ 10*sqrt(5)))/4* pow(bok,2)+5*(bok*wysokosc) <<"cm2"<<std::endl;
    return 0;
}

double ObjetoscOstroslupaTrojkatnego(double wysokosc){
    std::cout <<"Objętośc Ostroslupa Trojkatnego to: "<< (pow(bok,2)*wysokosc* sqrt(3))/12 <<"cm3"<< std::endl;
    return 0;
}
int main() {
    PoleKwadratu();
    PolePowierzchniGraniastoslupaPieciokatnego(16);
    ObjetoscOstroslupaTrojkatnego(16);
}
