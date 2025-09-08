#ifndef ARBORIIERARHIE_H
#define ARBORIIERARHIE_H
#include "list.h"

struct NodeIerarhie {
    char data[100] = {};
    List<NodeIerarhie*>*children=nullptr;
    NodeIerarhie*parent=nullptr;
};

struct Ierarhie {
    NodeIerarhie* root;
    Ierarhie(char* nume) {
         root= new NodeIerarhie();
         strcpy(this->root->data, nume);
        //construtctorul unei structuri este   o metoda ce are acelasi nume ca si structura nu are tip returnat si se apeleaza doar la creare
    }

    NodeIerarhie* findNode(NodeIerarhie*current,char*cautat) {
        if(current==nullptr) {
            return nullptr;
        }
        if(strcmp(current->data,cautat)==0) {
            return current;
        }
        if(current->children!=nullptr) {
             Node<NodeIerarhie*>*aux=current->children->head;
            while(aux!=nullptr) {
               NodeIerarhie *node=findNode(aux->data,cautat);
                if(node!=nullptr) {
                    return node;
                }
                aux=aux->next;
            }
        }
        return nullptr;
    }

    NodeIerarhie* addChild(NodeIerarhie*parent, char*data) {
        if(parent==nullptr) {
            return nullptr;
        }

        NodeIerarhie* node=new NodeIerarhie();
        strcpy(node->data, data);
        node->parent=parent;

        if(parent->children==nullptr) {
            parent->children = new List<NodeIerarhie*>();
            parent->children->addHead(node);
            return node;
        }

        parent->children->addTail(node);

        return node;
    }

    NodeIerarhie* removeChild(NodeIerarhie*parent,int index) {
        if(parent==nullptr || index > parent->children->lenght) {
            return nullptr;
        }

        Node<NodeIerarhie*>*current = parent->children->head;
        int counter = 0;
        while(current != nullptr && counter < index) {
            current = current->next;
            counter++;
        }

        counter = 0;
        while(current->data->children->lenght > 0) {
            parent->children->addPosition(current->data->children->head->data, index + counter);
            current->data->children->head->data->parent = parent;
            current->data->children->removeFirst();
            counter++;
        }
        parent->children->lenght--;
        parent->children->removePosition(index + counter);

        return parent;
    }

    void queUp(Queue<NodeIerarhie*> *queue, Node<NodeIerarhie*>*current) {
        while(current!=nullptr) {
            cout << current->data->data << " <- " << current->data->parent->data << " . ";
            if(current->data->children!=nullptr) {
                queue->push(current->data);
            }
            current = current->next;
        }
        cout << endl;
    }

    void afisare() {
        if(root==nullptr) {
            return;
        }

        cout << root->data << endl;
        Queue<NodeIerarhie*> *queue = new Queue<NodeIerarhie*>();
        queue->capacity = 100;
        Node<NodeIerarhie*>*current = root->children->head;

        queUp(queue, current);

        while(queue->peek()!=nullptr) {
            current = queue->pop()->data->children->head;

            queUp(queue, current);
        }
    }
};
#endif //ARBORIIERARHIE_H