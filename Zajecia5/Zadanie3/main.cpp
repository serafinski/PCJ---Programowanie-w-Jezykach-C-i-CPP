#include <iostream>
#include <vector>

using namespace std;

//wypisz wektor
void showVec(std::vector<double> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i]<<" ";
    }
    cout << endl;
}


void calc (std::vector<double>& v) {
    //zmienna składująca ile razy uruchomiliśmy funkcje
    static int count;
    //zwiększamy go za każdym uruchomieniem funkcji, bo jest static
    count++;

    //jeżeli funkcja została uruchomiona parzystą liczbę razy
    if (count % 2 == 0) {
        //pierwsza wartość wektora zostanie zwiększona o wartość ostatniego elementu wektora
        v[0] += v[v.size() - 1];//v.back()
    }

    //jeżeli funkcja została uruchomiona nieparzystą liczbę razy
    else {
        //pierwsza wartość wektora zostanie zmniejszona o wartość ostatniego elementu wektora
        v[0] -= v[v.size() - 1];
    }

    //usunięcie ostatniego elementu wektora
    v.pop_back();
}

int main() {
    std::vector<double> v3;
    double s;
    for (int i = 1; i <= 10; ++i) {
        cout<<"Podaj liczbe " << i << ":"<<endl;
        std::cin>>s;
        //wstaw wartość s ZA KAŻDYM RAZEM na samym początku (załatwienie odwrotnej kolejności!!!)
        v3.insert(v3.begin(),s);
    }
    //wypisanie wektora po raz pierwszy
    showVec(v3);

    //nieparzyście
    calc(v3);
    showVec(v3);

    //parzyście
    calc(v3);
    showVec(v3);

    //nieparzyście
    calc(v3);
    showVec(v3);

    //parzyście
    calc(v3);
    showVec(v3);
}