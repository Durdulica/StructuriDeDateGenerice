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
    int lenght = 0;

    Node<U>* addHead(U data) {
        Node<U>* node = new Node<U>;
        node->data = data;
        node->next = nullptr;
        lenght++;
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

        lenght++;
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

    Node<U>* addPosition(U data, int index) {
        lenght++;
        if(index == 0) {
            addHead(data);
            return head;
        }

        Node<U> *node = new Node<U>();
        node->data = data;
        Node<U> *current = head;
        int position = 0;

        while(current != NULL) {
            if (position + 1  == index) {
                node->next = current->next;
                current->next = node;
                return node;
            }
            position++;
            current = current->next;
        }
        return node;
    }

    Node<U>* removeFirst() {
        lenght--;
        Node<U> *current = head;
        head = head->next;
        delete current;
        return current;
    }

    Node<U>* removeLast() {
        lenght--;
        Node<U> *current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        Node<U> *temp = current->next;
        current->next = NULL;
        delete temp;
        return current;
    }

    Node<U>* removePosition(int index) {
        lenght--;
        if(index == 0) {
            return removeFirst();
        }

        Node<U> *current = head;
        int position = 0;

        while(current != NULL) {
            if (position + 1 == index) {
                Node<U> *node = current->next;
                current->next = current->next->next;
                delete node;
                return current;
            }
            current = current->next;
            position++;
        }

        return current;
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
