#ifndef LIST_H
#define LIST_H
#include "que.h"
struct Persoana {
    int greutate;
    int varsta;
    int inaltime;
    char nume[20];
    char prenume[20];
};

struct Masina {
    int greutate;
    int anFabricatie;
    int kilometraj;
    char culoare[20];
    char producator[20];
};

template <typename U>
struct List {

    Node<U>* head=nullptr;

    Node<U>* addHead(U data) {
        Node<U>* node = new Node<U>;
        node->data = data;
        node->next = nullptr;

        if(head==nullptr) {
            head = node;
            return node;
        }

        node->next = head;
        head = node;
        return head;
    }

    Node<U>* addTail(U data) {
        if(head==nullptr) {
            addHead(data);
            return head;
        }

        Node<U>* node = new Node<U>;
        node->data = data;
        Node<U>* current = head;

        while(current->next!=nullptr) {
            current = current->next;
        }
        current->next = node;
        return current;
    }

    void display() {
        Node<U>* current = head;
        while(current!=nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteList() {
        while(head!=nullptr) {
            Node<U>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


#endif //LIST_H
