#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

using std::vector; using std::function; using std::cout; using std::endl; using std::size;

//funkcja wyświetlająca zawartość wektora
void show(vector<double> v){
    for (int i = 0; i < v.size(); ++i) {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

//definicja struktury Point
struct Point{
    double x;
    double y;
};

//definicja struktury Rect
struct Rect{
    //lewy-górny wierzchołek prostokąta
    Point lg;
    //prawy-dolny wierzchołek prostokąta
    Point pd;
};

//const Rect* rects -> tablica prostokątów
//size_t sz -> wymiar tablicy prostokątów
//function<double(Rect)> f -> funkcja typu Rect -> double
vector<double>process(const Rect* rects, size_t sz,function<double(Rect)> f){

    //wektor, do którego będą zapisane wyniki przekształceń kolejnych prostokątów z tablicy za pomocą dostarczonej funkcji
    vector<double> res;
    for (int i = 0; i < sz; i++) {
        //dodawaj do wektora res
        res.push_back(f(rects[i]));
    }
    //zwróć res
    return res;
}

double pole(Rect r){
    return double (-1*((r.pd.x-r.lg.x)* (r.pd.y - r.lg.y)));
}

int main() {
    //prostokąt A o pkt [(0,4),(4,1)] -> zgodnie z poleceniem
    Point A = {0,4}, B = {4,1};
    //tablica prostokątów -> dodano dodatkowe 2 - [(-6,3),(6,-2)],[(-7,4),(8,-4)] -> zgodnie z poleceniem
    Rect rects[] = { Rect{ A, B},
                     Rect{ Point{-6,3}, Point{6,-2}},
                     Rect{ Point{-7,4}, Point{8,-4}}};

    cout << "Dlugosc przekatnych: ";
    //przekątne liczymy z prostokąta, który uzyskamy - (Rect r)
    //chcemy zwrócić dla niego double -> pierwiastek z boku a do kwadratu (bok a liczymy w taki sposób, że prawego-dolnego x odejmujemy lewy-górny x) dodanego do kwadratu z boku b (prawego-dolnego y odejmujemy lewy-górny y)
    //w skrócie można to zapisać jako -> sqrt(a^2+b^2) => liczymy z twierdzenia Pitagorasa

    //ten typ odwoływania powinien się nam kojarzyć z klasami z Java
    show(process(rects, size(rects),[](Rect r)-> double {return sqrt(pow(r.pd.x - r.lg.x,2)+pow(r.pd.y - r.lg.y,2));}));
    cout<<"\nPole prostokatow: ";
    //wywołanie za pomocą własnej funkcji
    show(process(rects, size(rects), pole));
}