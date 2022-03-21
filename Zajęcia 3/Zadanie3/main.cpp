#include <iostream>
#include <cmath>

//aver - jest wskaźnikiem
const double* aver(const double* arr,size_t size, double& average) {

    //inicjujemy zmienną, do której będzie zapisywana suma
    double sum = 0;

    //wyliczenie średniej
    //tak długo, jak i jest mniejsze od długości tablicy
    for (int i = 0; i < size; ++i) {
        //zwiększaj sumę dodając do niej kolejne elementy tablicy
        sum +=arr[i];
    }

    //średnia to suma na ilość
    average = sum/size;

    //inicjujemy wskaźnik najbliższej liczby w tabeli do średniej — jako index 0 tablicy
    const double *close = &arr[0];

    //tak długo, jak i jest mniejsze od długości tablicy
    for (int i = 1; i < size; ++i) {
        //jeżeli (aktualna wartość wskaźnika liczby najbliżej średniej minus średnia) podniesiona do potęgi 2, jest większa od (wartości liczby na indeksie i minus średnia) podniesionej do potęgi 2
        if(pow(*close - average,2) > pow(arr[i]- average,2))
            //zmień, że wartość na indeksie i zostanie nową najbliższą liczbą średniej
            close = &arr[i];
    }
    //zwróć wartość z tablicy najbliższą średniej
    return close;
}


// ta funkcja poniżej została podana w poleceniu zadania
int main () {
 using std::cout; using std::endl;
 double arr[] = {1, 2, -1.5 , 3.25, 5.5, 7.75, -0.25, 5.75};
 size_t size = std::size(arr);
 double average = 0;
 const double* p = aver(arr, size, average);
 cout << *p << " " << average << endl;
}