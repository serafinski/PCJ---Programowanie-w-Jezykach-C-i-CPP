#include <iostream>

int main() {
    //zawsze zadamy przynajmniej 1 pytanie
    int liczbaZadanychPytan=1;
    int maxLiczba = 1000000;
    int minLiczba = 0;

    //średnia z max i min
    int podejrzanaliczba = (maxLiczba+minLiczba)/2;
    //to, co wprowadzi użytkownik
    char inputUzytkownika;

    std::cout<<"\n====================================================================================="<<std::endl;
    std::cout <<"Pomysl liczbe od 0 do 1 000 000."<<std::endl;
    std::cout<<"=====================================================================================\n"<<std::endl;

    //kiedy liczba pytań jest mniejsza od 20 i nie trafiliśmy na prawidłową liczbę
    while (liczbaZadanychPytan<=20 && inputUzytkownika!='t'){
        std::cout<<"Nr zadanego pytania " << liczbaZadanychPytan << std::endl;
        std::cout<<"Czy twoja liczba to " << podejrzanaliczba << "?"<< std::endl;
        std::cout<<"Napisz: w - jezeli wieksza; m - jezeli mniejsza; t - jezeli tak" << std::endl;
        std::cin >> inputUzytkownika;

        if(inputUzytkownika !='w'&& inputUzytkownika !='m'&&inputUzytkownika !='t'){
            std::cout<<"\n====================================================================================="<<std::endl;
            std::cout <<"Wprowadz prawidlowa wartosc - w - jezeli wieksza; m - jezeli mniejsza; t - jezeli tak"<<std::endl;
            std::cout<<"=====================================================================================\n"<<std::endl;
            liczbaZadanychPytan-=1;
        }

        //ustawiamy zawsze na środek zakresu środek -> dlatego musimy zaktualizować wartość minimalną, jeżeli pomyślana liczba jest większa — na proponowaną liczbę
        if(inputUzytkownika == 'w'){
            minLiczba = podejrzanaliczba;
        }
        //ustawiamy zawsze na środek zakresu środek -> dlatego musimy zaktualizować wartość maksymalną, jeżeli pomyślana liczba jest mniejsza — na proponowaną liczbę
        else if (inputUzytkownika == 'm'){
            maxLiczba = podejrzanaliczba;
        }

        //wyciągamy nową średnią
        podejrzanaliczba = (maxLiczba + minLiczba)/2;
        //zwiększamy liczbę zadanych pytań
        liczbaZadanychPytan+=1;
    }

    //jeżeli trafi przed 21 pytaniem
    if (liczbaZadanychPytan <=20){
        std::cout<<"Liczba to: " << podejrzanaliczba << std::endl;
    }
    //jak nie trafi
    else{
        std::cout<<"Najblizsza liczba podejrzewana przez program to: " << podejrzanaliczba << std::endl;
    }

}