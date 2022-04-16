#include <iostream>

int fibonacci(unsigned int n){
    //dla n = 0
    if(n==0)
        return 0;
    //dla n = 1
    if(n==1)
        return 1;
    //dla n > 1
    //przykład rekurencji
    return fibonacci(n-2)+ fibonacci(n-1);
}

int main() {
    using std::cout;

    for(int i =1; i<=8;i++){
    cout << fibonacci(i) << ",";
    }
}
