#include <iostream>

//podane przez prowadzącą
enum Banks {PKO, BGZ, BRE, BPH};

struct Account {
    Banks   bank;
    int  balance;
};

struct Person {
    char   name[20];
    Account account;
};

struct Couple {
    Person  he;
    Person she;
};

//cpls -> tablica par
//bank -> docelowo wybrany bank
const Couple* bestClient(const Couple* cpls, int size, Banks bank) {
    //założenie z polecenia -> jeżeli żadna para nie spełnia założenia to zwracamy null pointer
    const Couple* res = nullptr;

    //iteracja przez tablice par
    for (int i = 0; i < size; ++i) {

        //jeżeli on lub ona należy do wybranego banku (przynajmniej 1 z nich)
        if(cpls[i].he.account.bank == bank ||cpls[i].she.account.bank == bank){

            //jeżeli pointer wskazuje na null pointer
            if(res == nullptr)
                //nadpisz go by wskazywał na parę
                res = &cpls[i];

            //jeżeli nie wskazuje na null pointer
            else{
                //jeżeli suma pieniędzy z kont pary przypisanej do res jest mniejsza od aktualnie sprawdzanej pary spełniającej kryteria
                if(res->he.account.balance+res->she.account.balance < cpls[i].he.account.balance+cpls[i].she.account.balance ){
                    //napisz res parą, która ma większą sumę pieniędzy
                    res = &cpls[i];
                }
            }
        }
    }
    //na koniec zwróć wskaźnik
    return res;
}

int main() {
    using std::cout; using std::endl;

    //tablica par stworzona na podstawie podanych danych
    Couple cpls[] = {
            //Przykład na to, że można pisać po prostu nazwę banko -> np. PKO, albo odnieść się przez Banks::BGZ
            Couple{Person{"Johny",{PKO, 1200}},Person{" Mary",{Banks::BGZ, 1400}}},//ta nie wejdzie, bo nie spełnia kryteriów (nie jest w BRE)
            Couple{Person{"Peter",{BGZ, 1400}},Person{" Suzy",{Banks::BRE, -1500}}},//ta wejdzie => ogólny balans -100
            Couple{Person{"Kevin",{Banks::PKO, 1600}},Person{" Katy",{Banks::BPH, 1500}}}, //ta nie wejdzie, bo nie spełnia kryteriów (nie jest w BRE)
            Couple{Person{"Kenny",{Banks::BPH, 200}},Person{" Lucy",{Banks::BRE, -201}}}//ta wejdzie => ogólny balans -1
    };


    //część również podana przez prowadzącą

    //jedna osoba z pary musi być w banku BRE
    const Couple* p = bestClient(cpls, std::size(cpls), BRE);

    //jeżeli jest para spełniająca kryteria
    if (p)
        //pointer do jego imienia " and " pointer do jej imienia
        cout << p->he.name << " and " << p->she.name
        //": " pointer do ilości pieniędzy na jego koncie + pointer do ilości pieniędzy na jej koncie
             << ": " << p->he.account.balance +
                        p->she.account.balance << endl;

    //jeżeli nie ma pary spełniającej kryteria
    else
        cout << "No such couple...\n";
}