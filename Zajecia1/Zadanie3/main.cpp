#include <iostream>

int main() {
    //inicjujemy a 1, bo nie może być 0 z powodu poniższego while
    int a=1, b;

    //do tej zmiennej będą sumowane cyfry liczby
    int sumaCyfr;

    //te wypiszemy
    int maxSumaCyfr=0, maxLiczba;

    //tak długo aż wprowadzana liczba nie jest 0
    while (a != 0){
        std::cout<<"wpisz liczbe naturalna (0 jezeli koniec): ";
        std::cin >> a;

        //sprawdzanie cyfry
        b=a;
        //do momentu aż nie zostanie żadna cyfra z liczby
        while (b>0){

            //policz ile jest cyfr po modulo i dodaj do sumyCyfr
            sumaCyfr += b%10;
            //zmniejsz cyfrę o 10
            b/=10;
        }

        // jeżeli suma cyfr > od poprzedniej maxSumyCyfr
        if (sumaCyfr > maxSumaCyfr){
            //to nadpisz maxSumaCyfr tą cyfrą
            maxSumaCyfr = sumaCyfr;
            //nadpisz maxLiczbę tą liczbą
            maxLiczba = a;
        }
        //reset sumy cyfr
        sumaCyfr = 0;
    }
    std::cout<<"Maksymalna suma cyfr liczby to " << maxSumaCyfr << ". Wystapila dla liczby " <<maxLiczba <<std::endl;
}
