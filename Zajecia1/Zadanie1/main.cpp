#include <iostream>
#include <math.h>

double bmi(double waga, double wzrost){
    return waga/ pow(wzrost,2);
}
int main(){
    std::cout << "Podaj wage (w kg) i wzrost (w m)" << std::endl;

    double waga, wzrost;

    std::cin >> waga >> wzrost;

    std::cout<<"Twoje BMI to: " << bmi(waga,wzrost)<<std::endl;
}