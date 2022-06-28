#include <iostream>
#include <string>
#include "Person.h"


int main() {
    Person john{"John"}, mary{"Mary"}, kitty{"Kitty"},
            jill{"Jill"}, bob{"Bob"}, eve{"Eve"};
    john.makeFriends(mary);
    john.makeFriends(bob);
    john.makeFriends(eve);
    bob.makeFriends(john);
    bob.makeFriends(jill);
    bob.makeFriends(eve);
    eve.makeFriends(mary);
    eve.makeFriends(kitty);
    john.listOfFriends();
    std::cout << "Friends of John's friends -> ";
    for (const Person *p: john.friendsOfFriends())
        std::cout << p->info() << " ";
    std::cout << std::endl;
}