#ifndef LIST_H
#define LIST_H

// #include <iostream>

template <typename T>
class List {

public:
    List();
    ~List();

public:
    bool is_empty() const;
    void print() const;
    void push_front(const T& value);
    void pop_front();
    void print();
    void clear();

private:
    struct Node
    {
        T data;
        Node* next;

        Node(const T& obj);
    };
    
    Node* m_head;
};

#include "list.tpp"


#endif //LIST_H