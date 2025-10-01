#ifndef ARBOREGENERIC_H
#define ARBOREGENERIC_H
#include "stiva.h"

template <typename T>
struct NodeGen {
    T data;
    NodeGen *left = nullptr;
    NodeGen *right = nullptr;
};

template <typename U>
struct ArboreGeneric {
    NodeGen<U> *root;

    NodeGen<U> *citirePre() {//nr. st. dr. ...
        NodeGen<U> *node;
        int x;
        cin >> x;
        if(x == 0) return nullptr;
        node = new NodeGen<U>;
        node->data = x;
        node->left = citirePre();
        node->right = citirePre();
        return node;
    }

    void afisPost(NodeGen<U> *current) {
        if(current == nullptr) return;
        afisPost(current->left);
        afisPost(current->right);
        cout << current->data << " ";
    }

    void afisareNivel() {
        if(root == nullptr) {
            return;
        }

        Queue<NodeGen<U> *> *queue = new Queue<NodeGen<U> *>;
        queue->capacity = 10;
        queue->push(root);

        while(!queue->isEmpty()) {
            int size = queue->count;
            for(int i = 0; i < size; i++) {
                root = queue->pop()->data;
                cout << root->data << " ";
                if(root->left != nullptr) {
                    queue->push(root->left);
                }
                if(root->right != nullptr) {
                    queue->push(root->right);
                }
            }
            cout << endl;
        }
    }
};
#endif //ARBOREGENERIC_H