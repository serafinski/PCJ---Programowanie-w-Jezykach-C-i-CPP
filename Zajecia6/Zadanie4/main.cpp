#include <iostream>
#include <functional>
#include <vector>

using std::vector; using std::function;

template <typename T, typename FunType>
//pobiera wektor i funkcje pobierającą dane typu, jakiego są elementy wektora (funkcja ta będzie zwracała bool)
//ta funkcja będzie coś w sobie robić, że zwróci nam albo true, albo false -> patrz dalej lambdy w main()
vector<T> filter(const vector<T>& v, FunType p) {
    std::vector<T> res;
    //badamy dla każdego elementu v — czy poszczególne elementy spełniają założenia tej funkcji, czy nie
    //jeżeli tak -> piszemy je do nowej funkcji
    for (int i = 0; i < v.size() ; i++)
    {
        //jeżeli warunek z lambdy zostanie spełniony na elemencie danego wektora (dowolna funkcja z lambdy będzie pod nazwą p)
        if(p(v.at(i)))
            //do wektora res wrzucamy oczekiwane wartości spełniające równanie z lambda -> czyli dla tych, dla których zwróciło true
            res.push_back(v.at(i));
    }
    //zwróć wektor res
    return res;
}

template <typename T>
//elementy wektora mają być dowolnego typu
//drukowanie elementów wektora
void printVec(const vector<T>& v) {
    std::cout<<"[ ";
    for (int i = 0; i < v.size(); i++) {
        std::cout<<v.at(i)<<" ";
    }
    std::cout<<"]\n";
}


int main() {
    vector<int> v{1, -3, 4, -2, 6, -8, 5};
    printVec(v);
    //lambda mająca zwracać true dla liczb parzystych
    //nie piszemy przy równaniach nawiasów () -> bo chcemy wykorzystać funkcje w naszym kodzie

    //prezentacja, że nie trzeba pisać typu zwracanego — kompilator sam się domyśli
    vector<int> r = filter(v, [](int a){return a%2==0 && a!=0;});
    printVec(r);
    //lambda mająca zwracać true dla liczb dodatnich
    //nie piszemy przy równaniach nawiasów () -> bo chcemy wykorzystać funkcje w naszym kodzie
    vector<int> s = filter(v, [](int a)->bool{return a>0;});
    printVec(s);
}