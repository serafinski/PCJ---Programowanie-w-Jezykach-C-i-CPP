//TOMASZ SERAFIŃSKI — Grupa 45c - Informatyka Stacjonarnie - Rok I, Semestr II
#include <iostream>
#include <ctime>
#include <algorithm>
using std::cout, std::endl;


void RandNumbers(int* tab, size_t size){
    srand(time(NULL));

    for(int i =0;i<size;i++)
        tab[i] = rand()%(30-1+1)+1;
}

void swap(int* tab, int indexA, int indexB){
    int tmp = tab[indexA];
    tab[indexA] = tab[indexB];
    tab[indexB] = tmp;
}

void show(int* tab, size_t size){
    for(int i=0; i<size; i++)
        cout << tab[i] << ",";
    cout<< endl;
}

const int* fun (const int* arr, size_t size, int& min){
    min = arr[0];
    for(int i =0; i< size; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    cout <<"Najmniejsza wartosc to: "<< min << endl;


    int tmp = min;
    int *wielokrotnosc = &tmp;

    for(int i = 0; i< size; i++){
        if((arr[i]% min == 0) && (*wielokrotnosc<arr[i])){
            *wielokrotnosc = arr[i];
        }
    }

    cout <<"Najwieksza wielokrotnosc " << min << " to: " << *wielokrotnosc << endl;
    return wielokrotnosc;
}

int main() {
    const int wielkosc = 20;
    int tab[wielkosc];


    cout << "Tablica wypelniona 0-mi:" << endl;
    for(int i = 0; i<std::size(tab);i++)
        tab[i] = 0;
    show(tab,std::size(tab));

    cout<<endl;

    cout << "Tablica wypelniona losowymi wartosciami - od 1 do 30:" << endl;
    RandNumbers(tab,std::size(tab));
    show(tab,std::size(tab));

    cout<<endl;

    cout << "Tablica w ktorej zamieniono indeksy za pomoca funkcji:" << endl;
    swap(tab,0,19);
    show(tab,std::size(tab));

    cout<<endl;

    //używając poprzedniej tablicy
    int min;
    fun(tab,std::size(tab),min);
}
//TOMASZ SERAFIŃSKI — Grupa 45c - Informatyka Stacjonarnie - Rok I, Semestr II