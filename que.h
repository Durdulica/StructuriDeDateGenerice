#ifndef QUE_H
#define QUE_H
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T> *next = nullptr;
};

template<typename U>
struct Queue {
    Node<U> *front = NULL;
    Node<U> *rear = NULL;
    int capacity = 0;
    int count = 0;

    bool isEmpty() {
        return rear == nullptr;
    }

    bool isFull() {
        return count == capacity;
    }

    Node<U> *push(U data) {
        if(isFull()) {
            cout << "Queue is full" << endl;
            return nullptr;
        }

        Node<U> *newNode = new Node<U>;
        newNode->data = data;

        if(isEmpty()) {
            rear = newNode;
            front = newNode;
            count = 1;
            return newNode;
        }

        newNode->next = rear;
        rear = newNode;
        count++;
        return rear;
    }

    Node<U> *pop() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return nullptr;
        }

        if(front == rear) {
            Node<U> *temp = front;
            front = rear = NULL;
            return temp;
        }

        Node<U> *current = rear;
        while(current->next != front) {
            current = current->next;
        }
        front = current;
        current = current->next;
        front->next = NULL;
        count--;
        return current;
    }

    Node<U> *peek() {
        if(!isEmpty()) {
            return front;
        }
        return nullptr;
    }

    void deleteQueue() {
        while(rear != nullptr) {
            Node<U> *temp = rear;
            rear = rear->next;
            delete temp;
        }
    }

    int getMax() {
        int max = INT_MIN;
        Node<U> *current = rear;

        while(current != nullptr) {
            if(current->data > max) {
                max = current->data;
            }
            current = current->next;
        }

        return max;
    }
};
#endif //QUE_H
