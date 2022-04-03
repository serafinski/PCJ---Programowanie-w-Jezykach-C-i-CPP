#include <iostream>
// you can (but not have to) use std::swap
#include <utility>

//przeciążona funkcja

//& -> referencja do zmiennej a,b,c itd...
//*& -> referencja do wskaźnika
void getMinMax(const double &a, const double& b,
               const double& c,const double*& pMin, const double*& pMax) {
    //jeżeli a jest większe od b i a jest większe od c
    if (a > b && a > c)
        //to do pMax zapisujemy adres a
        pMax = &a;

// RESZTA PRZYPADKÓW ANALOGICZNIE!
    else if (b > c)
        pMax = &b;

    else
        pMax = &c;

    if (a < b && a < c)
        pMin = &a;

    else if (b < c)
        pMin = &b;

    else
        pMin = &c;

}

//przeciążona funkcja

//zmienna* -> zmienna przystosowana do przechowywania adresu danego typu zmiennej
//** -> referencja wskaźnika do wskaźnika
void getMinMax(const double *a, const double* b,
               const double* c,const double** pMin, const double** pMax) {
    //jeżeli zmienna przechowująca adres jakiejś wartość a będzie większa od zmiennej przechowującej jakiś adres wartości b i jednocześnie większa od wartości przechowującej adres jakiejś wartości c
    if(*a > *b && *a > *c)
        //wtedy wskaźnik pMax będzie pokazywał na wartość a
        *pMax = a;


// RESZTA PRZYPADKÓW ANALOGICZNIE!
    else if(*b > *c)
        *pMax = b;

    else
        *pMax = c;

    if(*a < *b && *a < *c)
        *pMin = a;

    else if(*b < *c)
        *pMin = b;

    else
        *pMin = c;
}

//przeciążona funkcja

//& -> referencja do zmiennej a, b, c
void ord3(double& a, double& b, double& c) {
    double tmp;
    //jeżeli a jest większe od b
    if(a > b ) {
        //wartość a jest równe tmp
        tmp = a;
        //wartość b jest równa a
        a=b;
        //wartość tmp jest równa b
        b=tmp;
    }
// RESZTA PRZYPADKÓW ANALOGICZNIE!
    if(a > c ) {
        tmp = a;
        a=c;
        c=tmp;
    }

    if( b > c) {
        tmp = b;
        b=c;
        c=tmp;
    }
}

//przeciążona funkcja

//zmienna* -> zmienna przystosowana do przechowywania adresu danego typu zmiennej
void ord3(double* a, double* b, double* c) {
    double tmp;
    //jeżeli zmienna przechowująca adres jakiejś wartość a będzie większa od zmiennej przechowującej jakiś adres wartości b
    if(*a > *b ) {
        //to zmienna przechowująca adres jakiejś wartości a, jest równa tmp
        tmp = *a;
        //zmienna przechowująca jakiś adres wartości b będzie równa zmiennej przechowującej adres jakiejś wartości a
        *a=*b;
        //tmp będzie równe zmiennej przechowującej jakiś adres wartości b
        *b=tmp;
    }
// RESZTA PRZYPADKÓW ANALOGICZNIE!
    if(*a > *c ) {
        tmp = *a;
        *a=*c;
        *c=tmp;
    }

    if( *b > *c) {
        tmp = *b;
        *b=*c;
        *c=tmp;
    }
}

//TA CZĘŚĆ BYŁA PODANA W ZADANIU!
void printOrd(const double* a, const double* b,
              const double* c) {
    using std::cout; using std::endl;
    //używając * -> odnosimy się do wartości, do której odnosi się wskaźnik
    cout << *a << " " << *b << " " << *c << endl;
}

void printMinMax(const double* pmn, const double* pmx) {
    using std::cout; using std::endl;
    std:: cout << "Min = " << *pmn << "; "
               << "Max = " << *pmx << std::endl;
}

int main() {
    double a, b, c;
    const double *pMin, *pMax;

    a = 2; b = 1; c = 3;
    ord3(a,b,c);
    printOrd(&a, &b, &c);

    a = 3; b = 2; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);

    a = -1; b = -1; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);

    a = 2; b = 3; c = 1;
    getMinMax(a,b,c,pMin,pMax);
    printMinMax(pMin, pMax);

    a = 3; b = 1; c = 2;
    getMinMax(&a,&b,&c,&pMin,&pMax);
    printMinMax(pMin, pMax);

    a = 3; b = 3; c = -1;
    getMinMax(&a,&b,&c,&pMin,&pMax);
    printMinMax(pMin, pMax);
}