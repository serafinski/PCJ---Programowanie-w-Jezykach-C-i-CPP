#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using std::vector; using std::cout; using std::endl;

//WAŻNE BY ODWOŁAĆ SIĘ PRZEZ REFERENCJE (&) -> inaczej nie zadziała!!!
void put_Numbers(vector<int> &vec){
    for(int i =0; i<vec.size(); i++){
        vec[i] = rand() % ( (50-0+1) + 0);
    }
}
//pokazywanie wektora
void showVec (vector<int> vec){
    cout << "[";
    for(int i = 0; i<vec.size();i++){
        cout << vec[i] << ",";
    }
    cout << "]" << endl;
}
//template, bo wektory przyjmują ten sam typ danych -> ale nie sprecyzowany jaki
template <typename T>

//funkcja ma zwracać double, a nie void!!!
double ile_procent(vector<T> &v1, vector<T> &v2){

    //Do pomocniczego mają zostać dodane elementy, które występują w v2 -> ale jednocześnie zależy nam na tym,
    //że jeżeli wartość powtarza się w tym wektorze (np. wystąpi w nim dwa razy liczba 1), to ta wartość nie jest ponownie rozpatrywana -> ponieważ tworzymy wektor z wartościami unikatowymi.
    vector<T> pomocniczy;
    //nested for loop
    for(int i = 0; i< v2.size();i++){
        for(int j = 0; i<v2.size();i++){
            //by zapewnić brak rozpatrywania rozpatrywanej już wartości
            if(v2[i]!= v2[j])
                pomocniczy.push_back(v2[i]);
        }
    }

    //używamy wektora pomocniczego, by nie zmieniać wektora, który dostajemy
    int counter = 0;
    for(int i = 0; i<v1.size(); i++){
        for(int j = 0; j<pomocniczy.size(); j++){
            if (pomocniczy[j] == v1[i]){
                counter++;
            }
        }
    }

    //wynik zamieniony na double -> ze specyfiki polecenia!
    double wynik = ((double)counter/(double)v1.size()) * 100;
    return wynik;
}

int main() {
    //srand() w tym miejscu, bo jeżeli umieścimy go w funkcji "wsadzającej" wartości do wektora to zrobi nam takie same wartości dla v1 jak v2 -> tylko v1 rozszerzy o dalsze wartości, bo dłuższy wektor
    srand(time(NULL));
    vector<int> v1(50);
    vector<int> v2(10);
    put_Numbers(v1);
    put_Numbers(v2);

    cout << "Wektor 1:";
    showVec(v1);
    cout << endl;
    cout << "Wektor 2:";
    showVec(v2);
    cout << endl;
    cout<< "Wynikiem jest wartosc " << ile_procent(v1,v2) << "%!" <<endl;

}
