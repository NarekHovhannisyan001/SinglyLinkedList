#include "SinglyLinkedList.hpp"



int main() {
    List<int> myList;

    myList.push_front(3);
    myList.push_front(2);
    myList.push_front(1);

    myList.print();

    myList.pop_front();

    myList.print();

    myList.clear();    
    myList.print();

    return 0;
}