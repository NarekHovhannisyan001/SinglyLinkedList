#ifndef LIST_T
#define LIST_T

#include "SinglyLinkedList.hpp"

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
    
    Node* tmp = m_head;
    m_head = m_head->next;
    delete tmp;
}


template <typename T>
void List<T>::print() const {
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

template <typename T>
void List<T>::push_back(const T& val) {
    Node* new_node = new Node(val);
    if (m_head == nullptr) {
        m_head = new_node;
    } else {
        Node* current = m_head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}

template <typename T>
bool List<T>::find(const T& val) const {
    Node* current = m_head;
    while (current != nullptr) {
        if (current->data == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
T& List<T>::operator[](size_t index) {
    Node* current = m_head;
    size_t i = 0;

    while (current != nullptr) {
        if (i == index) {
            return current->data;
        }

        current = current->next;
        ++i;
    }

    throw std::out_of_range("Index out of range");
}

template <typename T>
const T& List<T>::operator[](size_t index) const {
    Node* current = m_head;
    size_t i = 0;

    while (current != nullptr) {
        if (i == index) {
            return current->data;
        }

        current = current->next;
        ++i;
    }

    throw std::out_of_range("Index out of range");
}



template <typename T>
void List<T>::pop_back() {
    if (m_head == nullptr) {
        throw std::runtime_error("Cannot pop from an empty list");
    }

    if (m_head->next == nullptr) {
        delete m_head;
        m_head = nullptr;
        return;
    }

    Node* current = m_head;
    Node* previous = nullptr;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    delete current;
    previous->next = nullptr;
}

#endif //LIST-T
