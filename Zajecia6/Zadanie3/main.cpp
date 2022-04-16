#include <iostream>
#include <string>

template<typename T>
//tablica jest przekazywana jako wartość stała (const) -> nie możemy sortować ani zamieniać wartości!
T getMaxRecur(const T* arr, size_t size) {
    //jeżeli tablica ma więcej niż 1 element
    if(size != 1){

        //PORÓWNYWANIE WARTOŚCI KRAŃCOWYCH! = MANIPULOWANIE WIELKOŚCIĄ TABELI!

        //jeżeli pierwszy element tablicy jest mniejszy od ostatniego elementu tablicy
        if(arr[0] < arr[size-1])
            //rekurencja ze zwiększonym adresem o 1 i zmniejszoną tablicą o 1
            return getMaxRecur(arr+1,size-1);
        //jeżeli element, który mamy pod indeksem 0 jest większy od ostatniego elementu tablicy
        else
            //rekurencja z tym samym adresem i zmniejszoną o 1 tablicą
            //w tym przypadku również należy pamiętać o odcięciu!
            return getMaxRecur(arr,size-1);
    }
    //jako że usuwamy ostatni element i przesuwamy adres -> jak dostaniemy tablice 1 elementową — to tym elementem będzie wartość największa
    return arr[0];
}

//main podany przez prowadzącą
int main() {
    using std::cout; using std::endl; using std::string;

    double ad[]{2.5, 9.1, 4.5, -1.0};
    cout << "ad: " << getMaxRecur(ad,4) << "; ";

    int ai[]{2, 11, 5, 1, 9};
    cout << "ai: " << getMaxRecur(ai,5) << "; ";

    string as[]{"Ala", "Ela", "Ula", "Ola"};
    cout << "as: " << getMaxRecur(as,4) << endl;
}