#ifndef LIST_T
#define LIST_T

#include "SinglyLinkedList.hpp"

#include <iostream>

template <typename T>
List<T>::Node::Node(const T& obj) : data(obj), next(nullptr) {}

template <typename T>
List<T>::List() : m_head(nullptr) {}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::push_front(const T& val) {
    Node* tmp = new Node(val);
    if (m_head == nullptr) {
        m_head = tmp;
        return;
    }
    tmp->next = m_head;
    m_head = tmp;
}


template <typename T>
void List<T>::pop_front() {
    if (m_head == nullptr) {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    m_head = m_head->next;
}

template <typename T>
void List<T>::print() {
    Node* current = m_head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}



template <typename T>
bool List<T>::is_empty() const {
    return m_head == nullptr;  
}

template <typename T>
void List<T>::clear() {
    while (!is_empty())
    {
        pop_front();
    }
    
}




#endif //LIST-T