#include <iostream>

struct Node {
    int   data;

    //wskaźnik na kolejny element w tej liście
    //(bo jest to lista jednokierunkowa (w naszym obiekcie mamy informacje o kolejnym obiekcie — który jest kolejny w tej liście))
    Node* next;
};

//dodawanie do listy węzła zawierającego dane typu int
bool add(Node*& head, int data){

    //Pomocniczy wskaźnik na węzeł act -> aktualny

    //Gdzie wskazujemy sobie na -> głowę (ang. head)
    Node *act = head;

    //sprawdzamy, czy act nie jest równy null pointer

    //wykonujemy while tak długo, aż aktualny nie jest równy null pointer
    while(act != nullptr){

        //jeżeli na liście jest już węzeł z daną o takiej samej wartości
        if(act->data == data)
            //to nowy węzeł nie zostanie dodany — funkcja zwraca false
            return false;

        //w przeciwnym przypadku przechodzimy dalej -> null pointer musi wskazać kolejny element
        act = act->next;
    }
    //jeżeli na liście nie ma węzła z podaną daną -> czytaj: żaden z elementów nie zwróci false

    //tworzymy nowy węzeł i dodajemy na początek listy -> jego następnym elementem będzie aktualna głowa (head)
    //użycie nowo poznanego operatora new -> by stworzyć nowe elementy funkcji
    Node *tmp = new Node {data,head};

    //jako że dodaliśmy ten element na początku — to ten element staje się głową
    head = tmp;

    //nie było to napisane więc dodałem sam
    return true;
}

//znajdowanie aktualnego rozmiaru (ilości węzłów) listy
size_t size(const Node* head){

    //pierwotnie wielkość jest 0
    size_t size = 0;

    //zmienna pomocnicza
    auto act = head;

    //przechodzimy po kolejnych elementach aż nie trafimy na null pointer
    while(act != nullptr){
        //za każdym razem jak jest jakiś element -> zwiększamy size
        size++;

        //przechodzimy do następnego elementu
        act = act->next;
    }
    //zwracamy wielkość
    return size;
}

//drukowanie zawartości listy

//to można ładniej napisać!!!
void printList(const Node* head){
    //zmienna pomocnicza
    Node tmp = *head;

    //wypisanie informacji ze zmiennej pomocniczej
    std::cout<<tmp.data<<" ";

    //sprawdzamy, czy istnieje kolejny element
    while(tmp.next != nullptr){
        //jeżeli istnieje -> przyporządkowujemy kolejny element
        tmp = *tmp.next;
        //i wypisujemy jego dane
        std::cout<<tmp.data<<" ";
    }
    std::cout<<std::endl;
}

//usuwanie wszystkich węzłów z listy
void clear(Node*& head){
    //jest ciekawsza -> bo musimy sprawdzać, czy nasz element nie jest null'em

    //przechodzimy tak, aż nie trafimy na koniec listy
    while(head != nullptr){
        //z drukowaniem informacji o usuwanych elementach
        std::cout<<"DEL: "<<head->data<<" ";

        //potrzeba pomocniczej zmiennej, by przechować informacje o kolejnym elemencie
        Node *tmp = head->next;
        //użycie nowo poznanego operatora delete -> usuwanie elementów funkcji

        //usuwamy aktualny element
        delete head;

        //nową głową staje się kolejny element
        head = tmp;
    }
}

//podany przez prowadzącą
int main() {
    using std::cout; using std::endl;
    int tab[] = {1,4,1,3,5};
    Node* head = 0;
    for (size_t i = 0, e = std::size(tab); i != e; ++i) {
        bool b = add(head,tab[i]);
        cout << tab[i] << (b ? "     " : " NOT ")
             << "added" << endl;
    }
    cout << "Size of the list: " << size(head) << endl;
    printList(head);
    clear(head);
}