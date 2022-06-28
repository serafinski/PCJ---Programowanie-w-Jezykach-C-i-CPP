//
// Created by tsera on 12.06.2022.
//

#ifndef ZADANIE1_PERSON_H
#define ZADANIE1_PERSON_H
#include <string>
#include <vector>

class Person {
    static size_t ID;
    std::string name;
    size_t id;
    std::vector<const Person*> friends;
public:
    Person(const std::string &name);

    //zaprzyjaźnia tę osobę z osobą p, czyli każda z nich dodaje wskaźnik do drugiej do swojego wektora przyjaciół,
    //ale tylko wtedy, gdy jeszcze nie są przyjaciółmi;
    void makeFriends(Person& p);

    //wypisuje przyjaciół tej osoby;
    void listOfFriends() const;

    //zwraca wektor wskaźników do osób będących przyjaciółmi przyjaciół tej osoby, ale nie jej przyjaciółmi;
    std::vector<const Person*> friendsOfFriends() const;

    //zwraca napis opisujący tę osobę, podobnie do toString w Java (może się przydać funkcja std::to_string z nagłówka string);
    std::string info() const;



};


#endif //ZADANIE1_PERSON_H
