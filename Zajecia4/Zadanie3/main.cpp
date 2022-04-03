#include <iostream>

//lista funkcji, którą mamy zdefiniować -> było podane w poleceniu
size_t length(const char* cstr);
bool isLetter(char c);
char* reverse(char* cstr);
size_t words(const char* cstr);
size_t words2(const char* cstr);
char* concat(char* t, const char* s);

//main również został podany w poleceniu
int main() {
    using std::cout; using std::endl;
    char s1[] = "Alice in Wonderland";
    cout << "reverse: " << reverse(s1) << endl;
    cout << "length : " << length(s1) << endl;

    char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
    cout << "words : " << words(s2) << endl;
    cout << "words2 : " << words2(s2) << endl;
    char s3[100] = "Hello";

    cout << "concat : "
         << concat(concat(s3, ", world"), "!") << endl;
}

//sprawdza, czy przekazany znak c jest dużą lub małą literą (nie używać znajomości kodów ASCII);
//zwraca prawda/fałsz
bool isLetter(char c) {
    //jeżeli litera jest większa równa duże A, oraz mniejsza równa duże Z
    //lub jeżeli litera jest większa równa małe a, oraz mniejsza równa małe z
    return (c >= 'A' &&  c <= 'Z') || (c >= 'a' &&  c <= 'z');
}

//zwraca długość napisu (nie licząc znaku ’\0’ na jego końcu);
size_t length(const char* cstr) {
//początkową wartość ustawiamy na 0
    size_t i = 0;
    //podczas kiedy wartość cstr[i] nie jest równa NULL -> to, co będzie na końcu
    while (cstr[i] != '\0')
    {
        //dodawaj do i
        i++;
    }
    //zwróć i -> długość ciągu
    return i;
}

//odwraca kolejność znaków w przekazanym napisie i zwraca niezmienioną wartość przekazanego wskaźnika cstr;
char* reverse(char* cstr) {

    //długość równa się to, co wyszło w cstr
    size_t size = length(cstr);

    //zmniejszamy o 1 -> by pozbyć się NULL
    size--;

    //początkową wartość ustawiamy na 0
    size_t i = 0;

    //ustala size na to, co pod zmienną size -> czyli wartość cstr
    size_t j = size;

    //podczas kiedy i jest mniejsze od połowy size
    while (i <= size / 2)
    {
        //tmp jest równe wartości i od cstr
        char tmp = cstr[i];
        //cstr od j jest równe cstr[i]
        cstr[i] = cstr[j];

        //tmp jest równe cstr[j]
        cstr[j] = tmp;
        //zwiększamy o 1 i++
        i++;
        //zmniejszamy o 1 j--
        j--;
    }
    //zwracamy cstr
    return cstr;
}
//zwraca ilość słów w przekazanym napisie, przy czym za słowo uważamy niepusty ciąg liter, dużych i małych, taki, że bezpośrednio przed nim i za nim nie ma litery;
size_t words(const char* cstr) {
    //długość równa się to, co wyszło w cstr
    size_t size = length(cstr);
    //początkową wartość ustawiamy na 0
    size_t result = 0;

    //startujemy od 0 indeksu
    size_t index = 0;

    //podczas kiedy indeks jest mniejszy od size
    while (index < size) {
        //jeżeli nie jest literą od cstr[index] oraz index+1 jest mniejszy od size
        if (!isLetter(cstr[index]) && index + 1 < size) {
            //zwiększamy index
            index++;
            //jeżeli nie jest literą od cstr[index]
            if (!isLetter(cstr[index])) {
                //nic się nie dzieje...
            }

            //w przeciwnym wypadku
            else
            {
                //zwiększ rezultat
                result++;
                //do momentu, kiedy jest literą od cstr[index] oraz index jest mniejszy od size
                while (isLetter(cstr[index]) && index < size) {
                    //zwiększ index
                    index++;
                }
            }
        }
        //w przeciwnym wypadku
        else {
            //zwiększ indeks
            index++;
        }
    }
    //zwróć rezultat
    return result;
}
//zwraca ilość słów w przekazanym napisie, ale tym razem liczymy tylko „słowa” co najmniej dwuliterowe;
size_t words2(const char* cstr) {
    //długość równa się to, co wyszło w cstr
    size_t size = length(cstr);
    //początkową wartość ustawiamy na 0
    size_t result = 0;
    //startujemy od 0 indeksu
    size_t index = 0;

    //podczas kiedy indeks jest mniejszy od size
    while (index < size) {
        //jeżeli nie jest literą od cstr[index] oraz index+1 jest mniejszy od size
        if (!isLetter(cstr[index]) && index + 1 < size) {
            //zwiększamy index
            index++;

            //jeżeli nie jest literą od cstr[index]
            if (!isLetter(cstr[index])) {
                //nic się nie dzieje...
            }
            //w przeciwnym wypadku
            else
            {
                //tworzymy counter i deklarujemy go wartością 0
                size_t counter = 0;

                //do momentu, kiedy jest literą od cstr[index] oraz index jest mniejszy od size
                while (isLetter(cstr[index]) && index < size) {
                    //zwiększ index
                    index++;
                    //zwiększ counter
                    counter++;
                }
                //jeżeli counter jest większy od 2
                if (counter >= 2) {
                    //zwiększ rezultat o 1
                    result++;
                }
            }
        }
        //w przeciwnym wypadku
        else {
            //zwiększ indeks
            index++;
        }
    }
    //zwróć rezultat
    return result;
}

//„dokleja” do napisu t (od target) napis s (od source);
// oczywiście trzeba zadbać o to, aby zarezerwowany pod adresem t obszar pamięci wystarczał na pomieszczenie obu napisów wraz z kończącym znakiem ’\0’!
// Funkcja zwraca niezmodyfikowaną wartość pierwszego argumentu.
char* concat(char* t, const char* s) {
    //ustawiamy wartość pod długość celu
    size_t sizeT = length(t);
    //ustawiamy wartość pod długość źródła
    size_t sizeS = length(s);

    //startujemy od 0 indeksu
    size_t indexT = 0;

    //podczas kiedy indexT jest mniejszy od sizeT oraz cel od indeksu indexT nie jest równy znakowi NULL
    while (indexT < sizeT && t[indexT] != '\0') {
        //zwiększaj indeks T
        indexT++;
    }

    //taki długo, jak i będzie mniejsze od długości źródła
    for (size_t i = 0; i < sizeS; i++) {
        //cel od indexT + 1 jest równy źródłowi od i
        t[indexT + i] = s[i];
    }
    //zwróć cel
    return t;
}