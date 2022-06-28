#include <algorithm> // min
#include <iostream>
#include <fstream>

int main() {
    constexpr size_t N = 5;
    int greatest[N];

    //podany plik musi znajdować się w cmake-build-debug
    std::ifstream inpfile("NGreatest.dat");
    size_t count{}; // ile liczb zostalo wczytanych
    int n{}; // 'n' to ostatnio wczytana liczba
    size_t ile{}; // ile liczb zostalo umieszczonych
    // w tablicy 'greatest'
    // byc moze pomocnicze zmienne, ale
    // nie tablice ani zadne inne kolekcje!
    // ...


    //sprawdzamy, czy nasz nowy element nie jest w tej tablicy — bo nie chcemy mieć powtórek
    while (inpfile >> n) {
        ++count;

        //zmienna pomocnicza
        bool isInArray = false;

        //sprawdzenie, czy nie występuje już w greatest

        //przechodzimy do wartości ile — by dojść tylko do ostatniego elementu tej tablicy
        for (int i = 0; i < ile; ++i) {

            //informacja czy mamy taki element w tablicy, czy nie
            if(n == greatest[i])
                isInArray = true;
        }

        //jeżeli element nie jest dodany do tablicy
        if(!isInArray){
            //sprawdzenie, czy tablica została zapełniona
            if(ile < N){
                //jeżeli została zapełniona to chcemy się do tego odnieść jako kolejny element tablicy greatest
                greatest[ile++]=n;
            }
            //w przeciwnym wypadku -> mamy zapełnioną tablice (na każdym miejscu mamy co najmniej 1 wartość)
            else{
                //patrzymy czy jest jakiś element mniejszy,
                //jeżeli jest jakiś mniejszy od tego, który mamy aktualnie — to chcemy wprowadzić go do tablicy
                //na miejsce najmniejszego elementu tej tablicy

                //w tym przypadku -1 oznacza, że nie chcemy umieścić tego elementu w tablicy
                int newIndex = -1;
                //dodanie na odpowiednie miejsce
                for(int i = 0; i < N; ++i) {
                    //czy n jest większy od największego sprawdzanego
                    if(n > greatest[i]) {
                        //jeżeli tak to musimy sprawdzić, czy indeks = -1 - jeżeli jest — to jest to pierwszy element,
                        //który spełnia nasze założenia to chcemy umieścić jego indeks jako newIndex
                        if(newIndex == -1 || greatest[newIndex] > greatest[i])newIndex = i;
                    }
                }
                //jeżeli nie jest to pierwszy element, ale kolejny — to trzeba sprawdzić, czy ten, który jest zapisany
                //jest większy niż ten aktualnie porównywalny
                if(newIndex != -1) greatest[newIndex] = n;
            }
        }
    }
    // numData - liczba uzyskanych elementow
    // w 'greatest', moze byc mniejsza od N
    size_t numData = std::min(ile, N);
    std::cout << count << " numbers read. Greatest "
              << numData << " different are: ";
    for (size_t i = 0; i < numData; ++i)
        std::cout << greatest[i] << " ";
    std::cout << "\n";
}