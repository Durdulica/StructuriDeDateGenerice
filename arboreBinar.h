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

    BinaryNode *addChild(BinaryNode *node, int value) {
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
        if(!node) return -1;

        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int getDepth(int value) {
        int index = 0;
        BinaryNode *current = root;
        while (current != nullptr) {
            if(value > current->data) {
                current = current->right;
                index++;
            }
            else if (value < current->data) {
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

    ///D L R
    void preorder(BinaryNode *current) {
        if(current == nullptr) return;

        cout << current->data << " ";
        preorder(current->left);
        preorder(current->right);
    }

    ///L D R
    void inorder(BinaryNode *current) {
        if(current == nullptr) return;

        inorder(current->left);
        cout << current->data << " ";
        inorder(current->right);
    }

    ///L R D
    void postorder(BinaryNode *current) {
        if(current == nullptr) return;

        postorder(current->left);
        postorder(current->right);
        cout << current->data << " ";
    }

    BinaryNode *succesor(BinaryNode *node) {
        node = node->right;
        while(node && node->left) {
            node = node->left;
        }
        return node;
    }

    BinaryNode *remove(BinaryNode *node, int value) {
        if(!node) return nullptr;

        if(value < node->data) {
            node->left = remove(node->left, value);
        }
        else if(value > node->data) {
            node->right = remove(node->right, value);
        }
        else {
            if(!node->left && !node->right) {
                delete node;
                return nullptr;
            }

            if(!node->left) {
                BinaryNode *temp = node->right;
                delete node;
                return temp;
            }

            if(!node->right) {
                BinaryNode *temp = node->left;
                delete node;
                return temp;
            }

            BinaryNode *succ = succesor(node);
            node->data = succ->data;
            node->right = remove(succ, succ->data);
        }
        return node;
    }
};
#endif //ARBOREBINAR_H