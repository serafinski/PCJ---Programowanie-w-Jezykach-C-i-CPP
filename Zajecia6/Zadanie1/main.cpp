#include <iostream>
#include <vector>
#include <string>

//tworzenie szablonu
template <typename T, typename K>
// gdzie T jest zmienną tablicową, a K jest zmienną typu tablicy
K max (T tab[], K size){
    //init index na 0
    K maxIndex = 0;
    //pętla przechodząca po tablicy
    for(int i =0; i< size; i++){
        //jeżeli wartość dla indeksu i była większa niż dla indeksu maxIndex
        if (tab[i] > tab[maxIndex])
            //zamień wartość maxIndex na i
            maxIndex = i;
    }
    //zwróć maxIndex
    return maxIndex;
}

int main() {
    using std::vector; using std::string; using std::cout; using std::endl; using std::size;

    //na wektorach to też będzie działać -> bo są to funkcje tablicowe!!!
    vector<int> intvector = {1,2,3,4,5,6,7,8,9};
    vector<double> doublevector = {1,2.5,5,7.5,10};
    vector<string> stringvector = {"Ala","ma","kota"};

    //na zwykłych tablicach
    int tabI[] = {9,8,7,6,5,4,3,2,1};
    double tabD[] = {10,7.5,5,2.5,1};
    string tabS[] = {"Kota","ma","Ala"};


    //trzeba dodać data -> zwraca bezpośredni wskaźnik do tablicy pamięci
    //używanej przez wektor do przechowywania posiadanych elementów
    cout << "WEKTOR INT => Indeks na ktorym znajduje sie najwieksza wartosc to: " << max(intvector.data(),intvector.size()) << endl;
    cout << "WEKTOR DOUBLE => Indeks na ktorym znajduje sie najwieksza wartosc to: " << max(doublevector.data(),doublevector.size()) << endl;
    cout << "WEKTOR STRING => Indeks na ktorym znajduje sie najwieksza wartosc to: " << max(stringvector.data(), stringvector.size()) << endl;
    cout << "INT => Indeks na ktorym znajduje sie najwieksza wartosc to: " << max(tabI, size(tabI)) << endl;
    cout << "DOUBLE => Indeks na ktorym znajduje sie najwieksza wartosc to: " << max(tabD, size(tabD)) << endl;
    cout << "STRING => Indeks na ktorym znajduje sie najwieksza wartosc to: " << max(tabS, size(tabS)) << endl;
}
