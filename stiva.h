#ifndef STIVA_H
#define STIVA_H
#include "list.h"

template<typename U>
struct Stiva {
    Node<U>* top = nullptr;

    Node<U>* push(U data) {
        Node<U>* node = new Node<U>;
        node->data = data;
        if (top == NULL) {
            top = node;
            return top;
        }
        node->next = top;
        top = node;
        return top;
    }

    Node<U>* pop() {
        if (top == nullptr) {
            return nullptr;
        }
        Node<U>* temp = top;
        top = top->next;
        return temp;
    }

    Node<U>* peek() {
        return top;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void deleteStack() {
        while (top != nullptr) {
            Node<U>* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
#endif //STIVA_H
