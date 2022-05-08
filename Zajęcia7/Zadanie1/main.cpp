#include <cmath>
#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

template <typename T, typename FunType1, typename FunType2>

//& v — wektor przesłany przez referencje
//t — funkcja transformująca
//p — predykat -> funkcja określająca czy dany element spełnia jej założenia, czy nie => zwróci bool
vector<T> transfilt(vector<T>& v, FunType1 t, FunType2 p) {
    for(int i=0;i<v.size();i++){

        //każdy element wektora jest zastąpiony wynikiem działania na ten element funkcji transformującej (t)
        v.at(i) = t(v.at(i));
    }

    //funkcja zwraca wektor tego samego typu co wektor wejściowy (v), zawierający tylko
    //te elementy przetransformowanego wektora, dla których predykat (p) zwraca true
    return filter(v,p);
}

template <typename T, typename FunType>

//funkcja z poprzednich zajęć -> potrzebna do transfilt
vector<T> filter(const vector<T>& v, FunType p) {
    //tworzymy nowy wektor, w którym będą przechowywane elementy spełniające predykat
    vector<T> res;
    for (T item:v) {
        //jeżeli spełnia założony predykat (z lambdy) => czyli jest pomiędzy mn i mx
        if(p(item))
            //dodaj do wektora
            res.push_back(item);
    }
    //zwróć utworzony wektor
    return res;
}

//kopia z poprzednich zajęć
template <typename T>
void printVec(const vector<T>& v) {
    std::cout<<"[ ";
    for (T it:v) {
        std::cout<<it<<" ";
    }
    std::cout<<"]\n";
}

int main() {
    cout << "Wektor przed transformacja" << endl;
    vector<double> w{1.5, -3.1, 4.0, -2.0, 6.3};
    printVec(w);
    double mn = -0.5, mx = 0.5;
    vector<double> d =transfilt(w,

                                // dostarczane wartości mają zostać zamienione na sin
                                [](double a)->double {return std::sin(a);},

                                //sprawdzamy, czy przekazane a jest pomiędzy mn i mx
                                [mn,mx](double a)->bool{return a>=mn&&a<=mx;});
    cout << "Wektor po transformacji" << endl;
    printVec(w);
    cout << "Wartosci wektora spelniajace predykat (znajdujace sie miedzy mn a mx)" << endl;
    printVec(d);
}