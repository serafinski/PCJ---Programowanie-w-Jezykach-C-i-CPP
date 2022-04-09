#include <iostream>
using namespace std;
// small, auxiliary functions
void count_letters(int *tab, const char* s){
    //init value
    int index = 0;
    //kiedy s od indeks'a nie jest null
    while(s[index] != '\0') {
        //isalpha -> sprawdza, czy jest literą alfabetu (w tym przypadku czy s od index)

        //jeżeli wartość w tablicy char jest literą
        if (isalpha(s[index])) {
            //tolower — zamienia wszystkie litery na małe

            //zmień literę na małą oraz, weź jej wartość odjętą od litery a, i zinkrementuj tablice (???)
            tab[tolower(s[index]) - 'a']++;
        }
        //zwiększ index o 1
        index++;
    }
}

void write_results(const char* s1, const char* s2) {
    //litery w pierwszym wyrazie
    int tab1['z'-'a' + 1]{};
    //litery w drugim wyrazie
    int tab2['z'-'a' + 1]{};

    //zamieniamy litery na same małe
    count_letters(tab1,s1);
    count_letters(tab2,s2);

    //wszystkie litery, które występują w przynajmniej jednym z podanych C-napisów
    for (int i = 0; i < size(tab1); ++i) {
        //jeżeli tab1 [i] LUB tab2 [i] nie są równe zero
        if(tab1[i] != 0 || tab2[i] != 0)
            //wypisz literę
            cout<<char('A' + i)<<" ";
    }
    cout<<endl;

    //wszystkie litery, które występują zarówno w pierwszym, jak i drugim napisie
    for (int i = 0; i < size(tab1); ++i) {
        //jeżeli tab1 [i] ORAZ tab2 [i] nie są równe zero
        if(tab1[i] != 0 && tab2[i] != 0)
            //wypisz literę
            cout<<char('A' + i)<<" ";
    }
    cout<<endl;

    //wszystkie litery z pierwszego napisu, których nie ma w drugim
    for (int i = 0; i < size(tab1); ++i) {
        //jeżeli tab1 [i] nie jest równe zero oraz tab2 [i] jest równe 0
        if(tab1[i] != 0 && tab2[i] == 0)
            //wypisz literę
            cout<<char('A' + i)<<" ";
    }
    cout<<endl;
}
//main podany przez prowadzącą
int main() {
    char s1[] = "To be, or not to be, that is the question:";
    char s2[] = "Whether 'tis nobler in the mind to suffer";
    write_results(s1,s2);
}