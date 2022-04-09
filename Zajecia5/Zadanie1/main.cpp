#include <iostream>
#include <vector>

bool sumOfTwo(const std::vector<int>& v,int val, int& i, int& j){
    //wyszukujemy od startowego i końcowego indeksu
    int indexS = 0, indexK = v.size()-1;

    //do momentu aż się nie zrównamy indeksami od lewej i od prawej strony
    while(indexS != indexK){
        //jeżeli bazowo suma (czyli suma wartość dla indeksu startowego i końcowego) będzie równa val
        if(v[indexS] + v[indexK] == val){
            //to za indeks startowy — indexS oraz indeks końcowy — indexK -> ustawimy jako wartości i oraz j
            i = indexS;
            j = indexK;

            //i zwrócimy prawdę
            return true;
        }
            //w przeciwnym wypadku

            //jeżeli bazowa suma (wartość dla index'u startowego + końcowego) będzie mniejsza od val
        else if(v[indexS] + v[indexK] < val){
            //zwiększymy indeks startowy
            indexS++;
        }
            //jeżeli to nie pomoże
        else{
            //zwiększymy index końcowy
            indexK--;
        }
    }
    //jeżeli nie znajdziemy odpowiadającej pary

    //to ustawiamy pod i oraz j -> -1
    i = -1;
    j = -1;
    //i zwracamy fałsz
    return false;
}

int main() {
    //przykładowy wektor dostarczony przez prowadząca
    std::vector<int> a{ 2, 4, 5, 8, 9, 11, 13, 15 };
    //val również dostarczone przez prowadzącą
    int val = 21;

    int i;
    int j;
    bool tmp = sumOfTwo(a,val,i,j);

    std::cout << "Suma: " << a[i] + a[j] << std::endl;
    std::cout << "\nJezeli pojawi sie wartosc -1 dla indeksow -> nie ma takich indeksow ktorych suma wartosci byla by rowna val!\n" << std::endl;
    std::cout << "Pierwszy index: " << i << std::endl;
    std::cout << "Drugi index: " << j << " " << std::endl;
    std::cout << std::endl;
    std::cout << "Czy jest rowne czy nie:" << std::endl;
    std::cout << "1 - dla True" << std::endl;
    std::cout << "0 - dla False" << std::endl;
    std::cout<< "Wartosc koncowa: " <<tmp << std::endl;
}