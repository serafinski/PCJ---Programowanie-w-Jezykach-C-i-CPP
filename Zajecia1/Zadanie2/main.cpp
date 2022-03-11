#include <iostream>

//musimy sprawdzić, od jakiej wartości histogram będzie szedł w dół
int najwieksza(int a, int b, int c){
    if(a > b && a > c)
        return a;

    if(b > c)
        return b;

    return c;
}

int main(){
    int a, b, c;
    std::cout << "Wprowadz 3 liczby calkowite nieujemne:"<<std::endl;
    std::cin >> a >> b >> c;

    //fragment wypisujący jaka liczba jest podporządkowana do danej zmiennej
    //std::cout<<"a: "<<a<<"\nb: "<<b<<"\nc: "<<c<<std::endl;

    //pod i największa wprowadzona wartość - i>0, bo nieujemne!
    for (int i = najwieksza(a,b,c); i > 0 ; --i) {
        //jeżeli i<=a wypisz gwiazdkę
        std::cout<<((i<=a)?"*":" ");
        //jeżeli i<=b wypisz gwiazdkę
        std::cout<<((i<=b)?"*":" ");
        //jeżeli i<=c wypisz gwiazdkę
        std::cout<<((i<=c)?"*":" ")<<std::endl;
    }

}