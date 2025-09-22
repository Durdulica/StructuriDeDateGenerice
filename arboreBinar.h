#ifndef ARBOREBINAR_H
#define ARBOREBINAR_H
#include "stiva.h"

struct BinaryNode {
    int data;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct ArboreBinar {
    BinaryNode *root = nullptr;
    ArboreBinar(int value) {
        root = new BinaryNode(value);
    }

    BinaryNode *addChild(BinaryNode *node,int value) {
        if (node == nullptr) {
            return new BinaryNode(value);
        }
        if(value > node->data) {
            node->right = addChild(node->right, value);
        }
        else if (value < node->data) {
            node->left = addChild(node->left, value);
        }
        return node;
    }

    int getHeight(BinaryNode *node) {
        if(!node) {
            return -1;
        }

        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    //todo: change node typo to int value
    int getDepth(int nr) {
        int index = 0;
        BinaryNode *current = root;
        while (current != nullptr) {
            if(nr > current->data) {
                current = current->right;
                index++;
            }
            else if (nr < current->data) {
                current = current->left;
                index++;
            }
            else {
                return index;
            }
        }
        return -1;
    }

    bool search(int value) {
        BinaryNode *current = root;

        while(current != nullptr) {
            if(current->data == value) {
                return true;
            }
            if(value < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        return false;
    }

    void queueUp(Queue<BinaryNode *> *queue, BinaryNode *node) {
        cout << node->data << " ";
        if(node->left != nullptr) {
            queue->push(node->left);
        }
        if(node->right != nullptr) {
            queue->push(node->right);
        }
    }

    void afisare() {
        BinaryNode *current = nullptr;

        Queue<BinaryNode *> *queue = new Queue<BinaryNode *>();
        queue->capacity = 100;
        queue->push(root);

        while(!queue->isEmpty()) {
            int size = queue->count;
            for(int i = 0; i < size; i++) {
                current = queue->pop()->data;
                cout << current->data << " ";
                if(current->left != nullptr) {
                    queue->push(current->left);
                }
                if(current->right != nullptr) {
                    queue->push(current->right);
                }
            }
            cout << endl;
        }
    }
};
#endif //ARBOREBINAR_H