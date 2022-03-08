#include <iostream>

double bmi(double waga, double wzost) {
    return waga/ pow(wzost,2);
}

int najwieksza(int a, int b, int c){
    if(a > b && a > c) return a;
    if(b > c)return b;
    return c;
}

int main() {
    //Zadanie 1
    std::cout << "Podaj wage i wzrost"<< std::endl;
    double waga, wzrost;
    std::cin>>waga>>wzrost;
    std::cout<<bmi(waga,wzrost)<<std::endl;

    //Zadanie 2
    int a, b, c;
    std::cout<<"podaj trzy liczby"<<std::endl;
    std::cin>>a>>b>>c;
    std::cout<<"a: "<<a<<"\nb: "<<b<<"\nc: "<<c<<std::endl;

    for (int i = najwieksza(a,b,c); i > 0 ; --i) {
        std::cout<<((i<=a)?"*":" ");
        std::cout<<((i<=b)?"*":" ");
        std::cout<<((i<=c)?"*":" ")<<std::endl;
    }
//   int a, b;
//   double c;
//
//    std::cin>>a>>c>>b;
//    std::cout<<"a: "<<a<<"\nb: "<<b<<"\nc: "<<c<<std::endl;
bool t = 5;

if(-1) std::cout<<t<<std::endl;//5
else std::cout<<"Nie"<<std::endl;
    return 0;
}
