//
// Created by tsera on 30.05.2022.
//

#include "Letters.h"
#include <iostream>

//Jeden konstruktor klasy pobiera tekst w postaci C-napisu (wskaźnika typu const char*)
Letters::Letters(const char *words) {
    size_t index = 0;
    //do momentu aż nie trafimy na koniec tekstu
    while (words[index] != '\0'){
        //zamieniamy literki na małe — bo litery duże i odpowiadające im małe są uważane za takie same

        //sprawdzamy, jaka jest litera i inkrementujemy ilość tej litery
        letters[tolower(words[index] - 'a')]++;
        index++;
    }
}

//getMostFrequent zwracającą znak, który występuje najczęściej
char Letters::getMostFrequent() {
    int tmp = 0;
    int tmpSize = 0;
    for (int i = 0; i < std::size(letters); i++) {
        if(tmpSize < letters[i]){
            tmp = i;
            tmpSize = letters[i];
        }
    }
    return 'A'+tmp;
}

//numOfDifferent zwracającą liczbę różnych liter
int Letters::numOfDifferent() {
    int tmp = 0;
    for (int i = 0; i < std::size(letters); ++i) {
        if( letters[i] > 0){
            tmp ++;
        }
    }
    return tmp;
}

//printFrequencies drukującą „histogram” opisujący liczby wystąpień poszczególnych liter:
// wyrównany od dołu, z kolumnami złożonymi z tylu gwiazdek, ile wynosiła liczba wystąpień odpowiedniej litery
void Letters::printFrequencies() {
    size_t size = letters[getMostFrequent() -'A'];
    while (size > 0){
        for (int i = 0; i < std::size(letters); ++i) {
            if(letters[i] == size){
                std::cout<<"*";
                letters[i]--;
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
        size--;
    }
    std::cout<<"ABCDEFGHIJKLMNOPQRSTUVWXYZ"<<std::endl;
}
