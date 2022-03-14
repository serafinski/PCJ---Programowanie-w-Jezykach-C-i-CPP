#include <iostream>
#include <cmath>
#define GETMAX
#define GETMIN

#define bok 16

double PoleKwadratu() {
    return pow(bok,2);
}
double PolePowierzchniGraniastoslupaPieciokatnego(double wysokosc){
    return (sqrt(25 + 10 * sqrt(5))/4)*pow(bok,2)*2 + 5 * bok * wysokosc;
}
double ObjetoscOstroslupaTrojkatnego(double wysokosc) {
    return (pow(bok,2)*sqrt(3))/(3*4);
}
#undef bok

int Najwieksza(int a, int b, int c){
    if(a > b && a > c) return a;
    if(b > c)return b;
    return c;
}
int Najmniejsza(int a, int b, int c){
    if(a < b && a < c) return a;
    if(b < c)return b;
    return c;
}

int main() {
    //Zadanie 1
    std::cout<< __LINE__ <<" "<< __FILE__ <<std::endl;
    std::cout<< __LINE__ <<" "<< __DATE__ <<" "<< __TIME__ <<std::endl;

    //Zadanie 2

    std::cout<<"Podaj trzy liczby"<<std::endl;
    double a,b,c;
    std::cin>>a>>b>>c;

#if defined(GETMAX) && defined(GETMIN)
    std::cout<<Najwieksza(a,b,c)<<std::endl;
    std::cout<<Najmniejsza(a,b,c)<<std::endl;
#elif defined(GETMAX)
    std::cout<<Najwieksza(a,b,c)<<std::endl;
#elif defined(GETMIN)
    std::cout<<Najmniejsza(a,b,c)<<std::endl;
#else
#error Musisz zdefiniowac przynajmniej jedną wartosc
#endif
    //Zadanie 3
    std::cout<<PoleKwadratu()<<std::endl;
    std::cout<<PolePowierzchniGraniastoslupaPieciokatnego(5)<<std::endl;
    std::cout<<ObjetoscOstroslupaTrojkatnego(4)<<std::endl;

    int odp = 1;
    do {
        char op;
        float num1, num2;

        std::cout << "Enter operator: +, -, *, /: ";
        std::cin >> op;

        std::cout << "Podaj dwie liczby ";
        std::cin >> num1 >> num2;

        switch(op) {
            case '+':
                std::cout << num1 << " + " << num2 << " = " << num1 + num2;
                break;
            case '-':
                std::cout << num1 << " - " << num2 << " = " << num1 - num2;
                break;
            case '*':
                std::cout << num1 << " * " << num2 << " = " << num1 * num2;
                break;
            case '/':
                if(num2 == 0){
                    std::cout<<"dzielenie przez 0!"<<std::endl;
                    break;
                }
                std::cout << num1 << " / " << num2 << " = " << num1 / num2;
                break;
            default:
                std::cout << "Error";
                break;
        }
        std::cout<<"Jezeli chcesz zakonczyc prace podaj 1"<<std::endl;
        std::cin>>odp;

    }while(odp != 1);
    return 0;
}
