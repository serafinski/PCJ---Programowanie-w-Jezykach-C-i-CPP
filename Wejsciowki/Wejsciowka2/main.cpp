#include <iostream>
#include <ctime>
#include <algorithm>

void RandNumbers(int* tab, size_t size, int& min){
    srand(time(NULL));

    tab[0] = rand()%(45 - 20 + 1) + 20;
    min = tab[0];

    for(int i=1; i<size; i++){
        tab[i] = rand()%(45 - 20 + 1) + 20;
    }

    for (int i=0; i< size; i++){
        if(tab[i]<min){
            min = tab[i];
        }
    }

    for (int i=0; i<size; i++){
        std::cout<< tab[i] << ",";
    }

    std::cout << std::endl;
}


int main() {
    const int wielkosc = 9;
    int tab[wielkosc];
    int min = tab[0];

    RandNumbers(tab, wielkosc, min);
    std::cout << "Najmniejsza wartosc to: " << min << std::endl;
}