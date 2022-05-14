#include <iostream>

struct Node {
    int   data;
    Node* next;
};

void addSorted(Node*& head, int data);
void showList(const Node* head);
void deleteList(Node*& head);

//podany przez prowadzącą
int main() {
    Node* head = nullptr;
    addSorted(head,2);
    addSorted(head,1);
    addSorted(head,6);
    addSorted(head,0);
    addSorted(head,4);
    addSorted(head,3);
    addSorted(head,0);
    addSorted(head,6);
    showList(head);
    deleteList(head);

    return 0;
}

//dodaje element do listy z podaną data -> trochę jak add z zadania 2 (ale nie do końca)

//po operacji głowa (head) listy może się zmienić -> dlatego wysyłamy ją przez referencje -> jedyna znacząca różnica między zadaniem 2
void addSorted(Node*& head, int data){

    //kiedy nowy element ma być pierwszym elementem,
    //czyli jeżeli head jest null pointer lub istniejący data elementu na stercie jest większa od data podanego elementu
    if(head == nullptr || head->data >= data){
        //tworzymy nowy węzeł i dodajemy na początek listy -> jego następnym elementem będzie aktualna głowa (head)
        //użycie nowo poznanego operatora new -> by stworzyć nowe elementy funkcji
        Node* tmp = new Node{data,head};
        //jako że dodaliśmy ten element na początku — to ten element staje się głową
        head = tmp;
    }

    //kiedy nowy element ma być wewnątrz
    else{
        //Pomocniczy wskaźnik na węzeł act -> aktualny

        //Gdzie wskazujemy sobie na -> głowę (ang. head)
        Node *act = head;

        //sprawdzamy, czy act nie jest równy null pointer

        //wykonujemy while tak długo, aż aktualny nie jest równy null pointer
        while(act != nullptr){

            //jeżeli data na stercie jest mniejsze od podanego data i jeżeli następna data na stercie jest równa null pointer
            //lub następna data na stercie jest większa od data dla podanego elementu
            if(act->data < data && (act->next == nullptr || act->next->data >=data)){

                //układamy je w kolejności od najmniejszego do największego
                Node *tmp = new Node{data,act->next};
                act->next = tmp;
                break;
            }
            //w przeciwnym przypadku przechodzimy dalej -> null pointer musi wskazać kolejny element
            act  = act->next;
        }
    }
}

//Z ZADANIA 2

//drukowanie zawartości listy

//to można ładniej napisać!!!
void showList(const Node* head){
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
    std::cout << std::endl;
}

//Z ZADANIA 2

//usuwanie wszystkich węzłów z listy
void deleteList(Node*& head){
    //jest ciekawsza -> bo musimy sprawdzać, czy nasz element nie jest null'em

    //przechodzimy tak, aż nie trafimy na koniec listy
    while(head != nullptr){
        //potrzeba pomocniczej zmiennej, by przechować informacje o kolejnym elemencie
        Node *tmp = head->next;

        //użycie nowo poznanego operatora delete -> usuwanie elementów funkcji

        //usuwamy aktualny element
        delete head;
        //nową głową staje się kolejny element
        head = tmp;
    }

}