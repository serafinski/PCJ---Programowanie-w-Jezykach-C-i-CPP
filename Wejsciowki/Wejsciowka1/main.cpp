#include <iostream>
#include <cmath>

#define LICZBA 4
#define POT
#define PIE


#if !(defined(POT) && defined(PIE))
#error "PRZERWIJ KOMPILACJE"
#endif

int main() {

#if defined(POT)
    std::cout << "4 do potęgi 3 to: " << pow(LICZBA, 3) << std::endl;
#endif

#if defined(PIE)
    std::cout << "Pierwiastek 2 stopnia z 4 to:  " << sqrt(LICZBA) << std::endl;
#endif
}
