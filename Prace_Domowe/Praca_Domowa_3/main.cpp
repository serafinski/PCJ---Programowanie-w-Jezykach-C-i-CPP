#include <iostream>

using std::cout; using std::endl;

template <typename T>
struct Node {
    T data;
    Node* next;
};

//funkcja wstawiająca do listy jednokierunkowej
template<typename T>
void insert(Node<T>** podstawa, int dane){
    auto* temp = new Node<T>;
    Node<T>* pointer;
    temp->data = dane;
    temp->next = nullptr;


    if (*podstawa == nullptr) {
        *podstawa = temp;
    }

    else {
        pointer = *podstawa;

        while (pointer->next != nullptr){
            pointer = pointer->next;
        }

        pointer->next = temp;
    }
}


template <typename T>
Node<T>* arrayToList(const T arr[], size_t size){
    Node<T> *podstawa = nullptr;
    for (int i = 0; i < size; i++)
        insert(&podstawa, arr[i]);
    return podstawa;
}

//funkcja wyrzucająca wartości, spełniające predykat -> czyli te, które chcemy się pozbyć
template <typename T, typename Pred>
void removeBad(Node<T>*& head, Pred p){
    //jeżeli głowa nie jest pointerem na nic
    if(head != nullptr){
        //NIE JEST TO DOBRE ROZWIĄZANIE, ALE BRAK MI POMYSŁU
        Node<T> *tmp = head;
        Node<T> *ostatni = head;
        bool koniec = false;

        //do momentu aż nie jesteśmy na końcu
        while(!koniec){
            //jeżeli dane spełniają predykat
            if(p(tmp->data)){
                //wypisz te dane i to, że je usuwamy
                cout<<"DEL "<<(T) tmp->data<<"; ";

                //jeżeli następne dane nie są niczym (null)
                if (tmp->next != nullptr){
                    if (tmp==head){
                        //głowa to następny tmp
                        head=tmp->next;
                    }
                    else{
                        //następny ostatni = tmp next
                        ostatni->next=tmp->next;
                    }
                }
                //jeżeli następne dane wskazują na null pointer
                else {
                    ostatni->next = nullptr;
                    //zakończ pętle while
                    koniec = true;
                }
            }
            //jeżeli nasza lista
            else{
                ostatni = tmp;
            }

            tmp=tmp->next;

            if (tmp == nullptr){
                koniec = true;
            }
        }
        cout<<endl;
    }
}

//funkcja wypisująca listę
template <typename T>
void showList(const Node<T>* head){
    //do momentu aż head nie jest == nullptr
    while (head != nullptr){
        //wypisz informacje
        cout << head -> data << " ";
        //zmień na następną
        head = head -> next;
    }
    cout << endl;
}

//funkcja usuwająca wszystkie węzły z listy
template <typename T>
void deleteList(Node<T>*& head) {

    //przechodzimy tak, aż nie trafimy na koniec listy
    while(head != nullptr){
        cout<<"deleting "<<head->data<<"; ";
        //potrzeba pomocniczej zmiennej, by przechować informacje o kolejnym elemencie
        Node<T> *tmp = head->next;

        //użycie nowo poznanego operatora delete -> usuwanie elementów funkcji

        //usuwamy aktualny element
        delete head;
        //nową głową staje się kolejny element
        head = tmp;
    }
    cout << endl;

    //jeżeli nie ma żadnych elementów
    if(head ==nullptr){
        cout << "Empty list" << endl;
    }
}



int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t size = std::size(arr);
    Node<int>* head = arrayToList(arr,size);
    showList(head);
    removeBad(head, [](int n) {return n%2 != 0;});
    showList(head);
    removeBad(head, [](int n) {return n < 5;});
    showList(head);
    removeBad(head, [](int n) {return n > 9;});
    showList(head);
    deleteList(head);
    showList(head);
}

