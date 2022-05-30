//
// Created by tsera on 30.05.2022.
//

#ifndef ZAJCIA9_LETTERS_H
#define ZAJCIA9_LETTERS_H


class Letters {
    int letters[26]{0};
public:
//Jeden konstruktor klasy pobiera tekst w postaci C-napisu (wskaźnika typu const char*)
Letters(const char* words);

//drugi obiekt typu string

//Klasa udostępnia metody
char getMostFrequent();
int numOfDifferent();
void printFrequencies();
};


#endif //ZAJCIA9_LETTERS_H
