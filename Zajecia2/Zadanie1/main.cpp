#include <iostream>

int main() {
    //używając makr preprocesora wypisujemy nr linii
    //i ścieżkę pliku
    std::cout << "Linia: "<<__LINE__ << "| Nazwa Pliku: " <<__FILE__ << std::endl;
    //oraz date i godzinę
    std::cout << "Linia: " << __LINE__ << "| Data: "<<__DATE__ << "| Godzina: " << __TIME__ << std::endl;
}
