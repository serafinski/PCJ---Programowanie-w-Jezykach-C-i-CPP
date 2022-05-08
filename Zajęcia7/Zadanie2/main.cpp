#include <iostream>
#include <string> // dla testów
#include <ctime> // time do losowych wartości dla main
#include <utility> // swap potrzebny do funkcji part

using std::swap;

//part ma tak poprzestawiać elementy tablicy arr by elementy, dla których jest spełniony predykat f ->
//znalazły na lewo od wszystkich elementów, dla których ten predykat nie jest spełniony
template <typename T, typename FUN>

//f jest predykatem -> cokolwiek co da się wywołać (wskaźnik funkcyjny, lambda) z argumentem typu T — zwróci bool!
size_t part(T* arr, size_t size, FUN f) {
    //idziemy z dwóch różnych stron -> więc potrzebujemy zarówno indeksu początkowego, jak i końcowego
    size_t indexBegin=0;
    size_t indexEnd=size-1;

    //tak długo, jak nie dojdzie do zrównania indeksu początkowego i końcowego i pierwszy lub pierwszy element tablicy nie spełnia predykatu
    while (indexBegin<indexEnd || f(arr[indexBegin])) {

        //jeżeli pierwszy element w tablicy NIE spełnia predykatu, a ostatni spełnia predykat
        if (!f(arr[indexBegin]) && f(arr[indexEnd]))
            // zamień je miejscami
            swap(arr[indexBegin], arr[indexEnd]);
        //jeżeli ani pierwszy i ani drugi NIE spełniają predykatu
        else if (!f(arr[indexBegin]) && !f(arr[indexEnd]))
            //zmniejsz indeks końcowy o 1, by przejść do kolejnego elementu -> bo wiemy, że ten ostatni jest na poprawnym miejscu
            indexEnd--;
        //jeżeli pierwszy element spełnia predykat, a drugi go NIE spełnia
        else if (f(arr[indexBegin]) && !f(arr[indexEnd])) {
            //zwiększ indeks pierwszego elementu
            indexBegin++;
            //zmniejsz indeks drugiego elementu
            indexEnd--;
        }
        //jeżeli oba elementy spełniają predykat
        else
            //zwiększ indeks pierwszego elementu -> bo po lewej jest zgodnie z założeniami, a po prawej nie
            //więc zwiększamy tylko indeks początkowy o 1
            indexBegin++;
    }
    //zwróć indeks pierwszego elementu, który nie spełnia predykatu
    return indexBegin;
}

//kopia z poprzednich zadań
template <typename T>
void printTab(const T* t, size_t size) {
    std::cout<<"[ ";
    for(int i=0;i<size;i++){
        std::cout<<t[i]<<" ";
    }
    std::cout<<"]\n";
}

//można napisać funkcje, zamiast pisać lambdę
//szybkie sprawdzenie, czy jest parzystę, czy nie
bool isEven(int e) {
    return e%2 == 0;
}

int main() {
    //Wynikowa tablica z funkcji part będzie miała względną kolejność elementów, które spełniają te elementy.
    //Natomiast będzie zwracać indeks pierwszego elementu, który nie spełnia predykatu (i to będzie jednocześnie liczba elementów, które ten predykat spełniają)

    size_t ind = 0;
    int a1[] = {1,2,3,4,5,6};

    //wykorzystanie funkcji zamiast lambdy
    ind = part(a1,6,isEven);

    //tak wyglądała by lambda
    //ind = part(a1, 6, [] (auto a) -> bool {return a%2 == 0;});

    std::cout << "ind = " << ind << " ";
    printTab(a1,6);

    int a2[] = {1,2,3,4,5,6};

    //lambda jako argument dla predykatu sprawdza, czy podana liczba jest nieparzysta

    //pisanie auto jest w tym przypadku dobrym pomysłem, bo nie musimy się martwić jaki typ elementu dostaniemy
    ind = part(a2, std::size(a2), [] (auto a) -> bool {return a%2!=0;});
    std::cout << "ind = " << ind << " ";
    printTab(a2,std::size(a2));

    std::string a3[] = {"Ala", "Ula", "Ela", "Ola", "Maja"};
    std::string mn = "Bea";
    std::string mx = "Sue";

    //lambda jako argument dla predykatu sprawdza, czy podane imię znajduje sie w zakresie od mn (Bea) do mx (Sue)
    ind = part(a3, std::size(a3), [mn,mx] (auto a) -> bool {return a>=mn && a<=mx;});
    std::cout << "ind = " << ind << " ";
    printTab(a3,std::size(a3));

    constexpr size_t DIM = 500000;
    int* a4 = new int[DIM];
    srand(unsigned(time(0)));
    for (size_t i = 0; i < DIM; ++i) a4[i] = rand()%21+1;

    //lambda jako argument dla predykatu sprawdza, czy podana liczba jest podzielna przez 7
    ind = part(a4, DIM, [] (auto a) -> bool {return a%7 == 0;});
    std::cout << "ind = " << ind << std::endl;
    delete [] a4;
}