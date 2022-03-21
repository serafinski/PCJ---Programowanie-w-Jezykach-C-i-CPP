#include <iostream>
void minMaxRep(const int a[], size_t size,
               int& mn, size_t& in, int&mx, size_t& ix) {
    //in -> ilość wystąpień najmniejszej
    //ix -> ilość wystąpień największej

    //każda wartość (zarówno maksymalna, jak i minimalna) pojawi się przynajmniej raz -> dlatego in oraz ix jest = 1
    in=1;
    ix=1;

    //mx i mn -> pierwsza wartość index 0 - z automatu dajemy, że największa oraz najmniejsza wartość jest na indeksie 0.
    mn = a[0];
    mx = a[0];

    //dalej sprawdzamy, czy faktycznie jest na indeksie 0

    //1 loop -> bo takie było założenie w zadaniu
    for(int i=1;i< sizeof(a);i++){
        //jeżeli to, co jest na indeksie i w tabeli a jest większe od wartości maksymalnej (mx)
        if(a[i]>mx){
            //to spraw, że to będzie nowa największa wartość
            mx=a[i];
            //zresetuj licznik wystąpień do 1
            ix=1;
        }
        //jeżeli największa wartość już wystąpiła i mamy kolejne powtórzenie
        else if(a[i]==mx){
            //zwiększ licznik ilości wystąpień największej wartości
            ix++;
        }

        //jeżeli to, co jest na indeksie i w tabeli a jest mniejsze od wartości minimalnej (mn)
        if(a[i]<mn){
            //to spraw, że to będzie nowa najmniejsza wartość
            mn=a[i];
            //zresetuj licznik wystąpień do 1
            in=1;
        }
        //jeżeli najmniejsza wartość już wystąpiła i mamy kolejne powtórzenie
        else if(a[i]==mn){
            //zwiększ licznik ilości wystąpień najmniejszej wartości
            in++;
        }
    }

}

// ta funkcja poniżej została podana w poleceniu zadania
int main() {
    using std::cout;
    int a[]{2,3,4,2,7,4,7,2};
    size_t size = std::size(a);
    int mn, mx;
    size_t in, ix;
    minMaxRep(a,size,mn,in,mx,ix);
    cout << "Array: [ ";
    for (size_t i = 0; i < size; ++i)
        cout << a[i] << " ";
    cout << "]\n";
    cout << "Min = " << mn << " " << in << " times\n";
    cout << "Max = " << mx << " " << ix << " times\n";
}