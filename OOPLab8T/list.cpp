#include "list.h"
#include <iostream>

template class List<int>;

template <typename T> List<T>::List() { head = nullptr; }

template <typename T> void List<T>::add(T item) {
    Node<T>* node = new Node<T>[1];
    node->value = item;
    if (head == nullptr) { // first element
        head = node;
        tail = node;
        head->prev = nullptr;
        return;
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

template <typename T> void List<T>::remove() {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        head = nullptr;
        return;
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
        if (temp->next->next == nullptr) {
            temp->next = nullptr;
            break;
        }
        temp = temp->next;
    }
}

template <typename T> void List<T>::display() {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
