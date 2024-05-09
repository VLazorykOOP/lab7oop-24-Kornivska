#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T> class Node {
private:
    T value;
    Node* next;
    Node* prev;
    template <typename U> friend class List;

public:
    Node() {
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T> class List {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    List();
    void add(T item);
    void remove();
    void display();

    class iterator {
    private:
        Node<T>* pos;

    public:
        iterator(List<T> s1) { pos = s1.head; };
        void operator++() {
            if (pos->next == nullptr) {
                std::cout << "Already last element! Aborting." << std::endl;
                return;
            }
            pos = pos->next;
        };
        void operator++(int) {
            if (pos->next == nullptr) {
                std::cout << "Already last element! Aborting." << std::endl;
                return;
            }
            pos = pos->next;
        };
        T operator*() { return pos->value; }
        void operator--() {
            if (pos->prev == nullptr) {
                std::cout << "First element! Aborting." << std::endl;
                return;
            }
            else
                pos = pos->prev;
        }
        void operator--(int) {
            if (pos->prev == nullptr) {
                std::cout << "First element! Aborting." << std::endl;
                return;
            }
            else {
                pos = pos->prev;
            }
        }
        bool operator!=(List<T>::iterator& iter) {
            return !(this->pos == iter.pos);
        }
        bool operator==(List<T>::iterator& iter) { return this->pos == iter.pos; }
    };
};

#endif // LIST_H
#pragma once
