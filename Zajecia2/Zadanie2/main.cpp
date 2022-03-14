#include <iostream>
//definiujemy makro GETMAX
#define GETMAX
//definiujemy makro GETMIN
#define GETMIN

//jeżeli oba makra są zdefiniowane to nic się nie dzieje
#if defined(GETMAX) && defined(GETMIN)

//pamiętamy o zakończeniu makra!!!
#endif

// jeżeli żadne z makr nie jest zdefiniowane to wywala błąd
#if !(defined(GETMAX) || defined(GETMIN))
#error "Prosze zdefiniowac GETMAX lub GETMIN"

//pamiętamy o zakończeniu makra!!!
#endif

int main() {
    //inicjujemy zmienne, które wpisze użytkownik
    int a,b,c;

    std::cout << "Wpisz 3 cyfry" << std::endl;
    //input ze strony użytkownika
    std::cin >> a >> b >> c;

// jeżeli GETMAX jest zdefiniowane
#if defined(GETMAX)
    std::cout << "Największa liczba to: ";

    //porównanie wartości i wypisanie odpowiedniej w zależności od sytuacji
    if(a>b && b>c)
        std::cout << a << std::endl;
    else if (a<b && b>c)
        std::cout << b << std::endl;
    else
        std::cout << c << std::endl;
//pamiętamy o zakończeniu makra!!!
#endif


#if defined(GETMIN)
    std::cout << "Najmniejsza liczba to: ";

    //porównanie wartości i wypisanie odpowiedniej w zależności od sytuacji
    if(a>b && b>c)
        std::cout << c << std::endl;
    else if (a<b && a<c)
        std::cout << a << std::endl;
    else
        return b;
//pamiętamy o zakończeniu makra!!!
#endif
}
