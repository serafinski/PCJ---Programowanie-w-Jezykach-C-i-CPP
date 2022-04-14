#include <iostream>
#include <vector>
#include <ctime>

void fun1(std::vector<int>& v){
    srand(time(NULL));
    static int count;
    count++;

    int a;
    if(count %2 ==0){
        int poczatek = v.front();
        int koniec = v.back();
        int wynik = poczatek*koniec;
        v.push_back(wynik);
    }
    else{
        std::cout << "Wprowadz wartosc: " << std::endl;
        std::cin >> a;
        int i = (rand()%((v.size()-0+1)+0));
        v.insert((v.begin() + i),a);
    }
}

void fun2(std::vector<int>& v){
    std::cout << "Ostatnia wartosc wektora: " <<  v.back();
    std::cout << std::endl;
    v.pop_back();
}

int main() {
std::vector a{1,2,3,4,5,6,7,8,9};

fun1(a);
for (auto i = a.begin(); i<a.end(); i++) {
    std::cout << *i << ",";
}

std::cout << std::endl;

fun2(a);
for (auto i = a.begin(); i<a.end(); i++) {
    std::cout << *i << ",";
}
}
