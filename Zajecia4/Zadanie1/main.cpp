#include <iostream>

//do tej funkcji musieliśmy dopisać ciało
void merge(const int* a, size_t dima,
           const int* b, size_t dimb, int* c) {

    //zmienne pomocnicze — pierwotnie zdefiniowane z wartością 0
    size_t indexA = 0, indexB = 0;

    //tak długo, jak i jest mniejsze od dima+dimb -> czyli wymiaru tablicy c
    for(int i=0; i< dima+dimb; i++){
        //jeżeli wielkość indexA jest mniejsze od wymiaru dima oraz jeżeli wielkość indexB jest mniejsze od wymiaru dimb
        if(indexA < dima && indexB < dimb){

            //wtedy wartość od indeksu i tablicy c -> c[i] jest równa:
            //a ze zwiększonym indeksem o 1 -> a[indexA++], jeżeli a od indeksA jest mniejsze od b od indeksB
            //w przeciwnym wypadku — b ze zwiększonym indeksem o 1 -> b[indexB++], jeżeli b od indeksB jest większe od a od indeksA
            c[i] = a[indexA] < b[indexB] ? a[indexA++] : b[indexB++];
        }
        //indexA i indexB nie są mniejsze od wymiarów tablicy a oraz tablicy b
        //to, jeżeli indexA jest mniejszy od wymiaru tablicy a
        else if(indexA < dima){
            //to c od i jest równe a ze zwiększonym indeksem o 1 -> a[indexA++]
            c[i]=a[indexA++];
        }
        //w przeciwnym wypadku
        else{
            //to c od i jest równe b ze zwiększonym indeksem o 1 -> b[indexB++]
            c[i] = b[indexB++];
        }
    }
}

//to było dostarczone przez prowadzącą
void printArr(const int* a, size_t dim, const char* m){
    std::cout << m << " [ ";
    for (size_t i = 0; i < dim; ++i)
        std::cout << a[i] << " ";
    std::cout << "]\n";
}

//to było dostarczone przez prowadzącą
int main() {
    int a[] = {1,4,4,5,8};
    int b[] = {1,2,2,4,6,6,9};
    constexpr size_t dima = std::size(a);
    constexpr size_t dimb = std::size(b);
    constexpr size_t dimc = dima + dimb;
    int c[dimc];

    merge(a,dima,b,dimb,c);

    printArr(a,dima,"a");
    printArr(b,dimb,"b");
    printArr(c,dimc,"c");
}