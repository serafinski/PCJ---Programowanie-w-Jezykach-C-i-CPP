#include <iostream>

int main() {
    double pierwsza;
    double druga;
    char znak;
    char kontynuacja;

std::cout << "===================="<< std::endl;
std::cout << "Jestem Kalkulatorem!"<< std::endl;
std::cout << "===================="<< std::endl;


//wykonuj tak długo aż użytkownik nie wpisze 'n' na wyborze co do kontynuacji
do{

std::cout << "Wprowadz pierwsza liczbe:";

//input użytkownika — pierwsza liczba
std::cin >> pierwsza;

std::cout << "Wybierz operacje artymetyczna:"<<std::endl;
std::cout << "+ dla dodawania" << std::endl;
std::cout << "- dla odejmowania" << std::endl;
std::cout << "* dla mnozenia" << std::endl;
std::cout << "/ dla dzielenia" << std::endl;
std::cout << "Znak: ";

//input użytkownika — znak działania
std::cin >> znak;

//jeżeli użytkownik wprowadzi coś innego niż dozwolone znaki
while (znak != '+' && znak!= '-'&& znak!='*' && znak!='/'){
    std::cout << "Prosze wprowadzic poprawny znak: +,-,*,/" <<std::endl;
    std::cout << "Znak: ";
    std::cin>>znak;
}

std::cout << "Wprowadz druga liczbe:";

//input użytkownika — druga liczba
std::cin >> druga;

//jeżeli użytkownik chce dzielić przez 0

//NIEZBYT ŁADNE ROZWIĄZANIE - ALE NA OBECNY CZAS NIE MIAŁEM CZASU IMPLEMENTOWAĆ INNEGO
while (znak=='/' && pierwsza==0||druga==0){
    std::cout << "NIE WOLNO DZIELIC PRZEZ 0! Wprowadź prawidłowe parametry!" << std::endl;
    std::cout << "Wprowadz pierwsza liczbe:";
    std::cin >> pierwsza;

    std::cout << "Wybierz operacje artymetyczna:"<<std::endl;
    std::cout << "+ dla dodawania" << std::endl;
    std::cout << "- dla odejmowania" << std::endl;
    std::cout << "* dla mnozenia" << std::endl;
    std::cout << "/ dla dzielenia" << std::endl;
    std::cout << "Znak: ";
    std::cin >> znak;

    while (znak != '+' && znak!= '-'&& znak!='*' && znak!='/'){
        std::cout << "Prosze wprowadzic poprawny znak: +,-,*,/" <<std::endl;
        std::cout << "Znak: ";
        std::cin>>znak;
    }

    std::cout << "Wprowadz druga liczbe:";
    std::cin >> druga;
    }

//switch co do znaków operacji
    switch (znak) {
        case '+':
            std::cout << "Wynik to: " << pierwsza + druga << std::endl;
            break;
        case '-':
            std::cout << "Wynik to: " << pierwsza - druga << std::endl;
            break;
        case '*':
            std::cout << "Wynik to: " << pierwsza * druga << std::endl;
            break;
        case '/':
            std::cout << "Wynik to: " << pierwsza / druga << std::endl;
            break;
    }
//kwestia kontynuacji
    std::cout << "Czy chcesz kontynuowac? -> t dla TAK; n dla NIE";
    std::cin>>kontynuacja;
    //patrz wyżej -> tak długo, jak nie jest to 'n'
} while (kontynuacja !='n');
}
