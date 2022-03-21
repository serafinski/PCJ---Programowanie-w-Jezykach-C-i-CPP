#include <iostream>

//by sortowanie zadziałało musimy umieścić pakiet sort
#include <algorithm>

//by generowało nam losowe liczby ZA KAŻDYM RAZEM — musimy umieścić ctime — który dostarczy nam czas w ms, który posłuży nam jako ziarno do generowania liczb losowych
#include <ctime>

int main() {
    //dzięki temu mamy za każdym razem inne losowe liczby
    srand(time(NULL));

    // musi być const -> bo jest zmienną, która podstawimy za rozmiar tabeli
    const int wielkosc = 9;
    int tab[wielkosc];

    //tak długo aż i jest mniejsze od wielkości tabeli
    for(int i=0; i<wielkosc;i++){
        //losujmy liczby z zakresu od 50 do 100

        //korzystamy z tego, że ilość liczb w przedziale to:
        // maksymalna wartość przedziału - minimalna wartość przedziału + 1

        //+ na końcu należy dodać liczbę startową


        //dla potomności 100% poprawna wersja
        tab[i] = rand()%(100 - 50 + 1) + 50;

        // tak zrobiłem -> tab[i]=(rand()%51)+50;
    }

    //używamy funkcji sort, która posortuje nam rosnąco liczby
    std::sort(std::begin(tab),std::end(tab));

    //wypiszemy posortowane liczby po kolei
    for(int i=0;i<wielkosc;i++){
        std::cout<<tab[i]<<std::endl;
    }

}
