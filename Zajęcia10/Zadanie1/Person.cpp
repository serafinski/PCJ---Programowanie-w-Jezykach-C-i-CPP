//
// Created by tsera on 12.06.2022.
//

#include "Person.h"
#include <iostream>
//domyślnie na początku ustawiamy wartość ID statycznego na 1
size_t Person::ID{1};

//konstruktor
//przypisujemy wartość name przekazanej jako parametr name
Person::Person(const std::string &name) : name(name) {
    //Przypisujemy wartość zmiennej statycznej ID i zmieniamy jej wartość, by dla kolejnej utworzonej osoby był kolejny numer ID.
    //Oczywiście trzeba nadać wartość początkową ID na 1 (patrz wyżej)
    id = ID++;
}

//zaprzyjaźnia tę osobę z osobą p, czyli każda z nich dodaje wskaźnik do drugiej do swojego wektora przyjaciół,
//ale tylko wtedy, gdy jeszcze nie są przyjaciółmi;

//sprawdzamy, czy mamy w liście znajomych konkretnego znajomego
void Person::makeFriends(Person& p){
    for (int i = 0; i < friends.size(); ++i) {
        //porównujemy osoby za pomocą adresu (ponieważ mamy tablice wskaźników to nie pobieramy wartości tego wskaźnika, a adres

        //jeżeli mamy ten sam adres
        if(friends.at(i) == &p)
            //zwracamy return — bo nie chcemy dołączyć tej osoby do listy znajomych
            return;
    }
    //w przeciwnym wypadku

    //tworzymy wskaźnik do osoby
    const Person *tmp = &p;

    //umieszczamy wskaźnik w wektorze friends za pomocą metody pushback
    friends.push_back(tmp);
}

//wypisuje przyjaciół tej osoby;
void Person::listOfFriends() const{
    std::cout<< Person::name <<"'s friends -> ";

    //przechodzimy po liście znajomych
    for (int i = 0; i < friends.size(); ++i) {
        //wypisujemy ich info

        //używamy -> bo jest to tablica wskaźników
        std::cout<<friends.at(i)->info();
    }
    std::cout<<std::endl;
}

//zwraca napis opisujący tę osobę, podobnie do toString w Java (może się przydać funkcja std::to_string z nagłówka string);
std::string Person::info() const{
    //zapisuje imie i w nawiasach id osoby

    //by mieć to ID -> trzeba skorzystać z metody to_string (konwersja int na string)
    return name + "(" + std::to_string(id) + ") ";
}

//zwraca wektor wskaźników do osób będących przyjaciółmi przyjaciół tej osoby, ale nie jej przyjaciółmi;
std::vector<const Person*> Person::friendsOfFriends() const{
    //tablica Person response
    std::vector<const Person*> response;
    //przechodzimy po znajomych głównej postaci
    for (int i = 0; i < friends.size(); ++i) {
        //przechodzimy po każdej osobie z listy znajomych tej osoby
        for (int j = 0; j < friends.at(i)->friends.size(); ++j) {
            //patrzymy czy chcemy dodać tego znajomego do naszej odpowiedzi, czy nie
            bool add = true;
            //ponowne przejście po liście znajomych głównej osoby, by sprawdzić, czy osoba, którą chcemy dodać
            //nie pojawia się w tej liście
            for (int k = 0; k < friends.size(); ++k) {
                //adres tej osoby nie jest równy głównemu adresowi lub
                //sprawdzamy, czy ta osoba, którą sprawdzamy nie jest równa znajomemu z listy głównej osoby (znajoma głównej osoby)

                //this bez gwiazdki — po prostu adres
                //porównywanie adresów
                if(friends.at(i)->friends.at(j) == this || friends.at(k) == friends.at(i)->friends.at(j))
                    //jeżeli spełnione zmiana na false — nie chcemy dodawać tej osoby do listy
                    add = false;
            }
            //w przeciwnym wypadku -> jeżeli true
            if(add)
                //dodajemy za pomocą push back wskaźnik do koljnej osoby
                response.push_back(friends.at(i)->friends.at(j));
        }
    }
    return response;
}
