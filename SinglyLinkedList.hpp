#ifndef LIST_H
#define LIST_H

#include <iostream>

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
    void push_back(const T& val);
    void pop_back();
    bool find(const T& val) const;
    void clear();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

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
