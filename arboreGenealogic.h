#ifndef ARBOREGENEALOGIC_H
#define ARBOREGENEALOGIC_H
#include "stiva.h"

/*struct NodeGen {
    NodeGen *mother = nullptr;
    NodeGen *father = nullptr;
    NodeGen *mate = nullptr;
    List<NodeGen*> *children = new List<NodeGen*>();
    char name[100] = {};
    bool isAlive = true;
    int age = 0;
};
//todo: mate function not making correct connections; afisare is now working
struct ArboreGenealogic {
    NodeGen *root =  new NodeGen();
    NodeGen *currentRelative = new NodeGen();

    NodeGen *findRelative(NodeGen *current, char *cautat) {
        if(current == nullptr) {
            return nullptr;
        }

        if(strcmp(current->name,cautat) == 0) {
            return current;
        }

        NodeGen *node = findRelative(current->father, cautat);
        if(node != nullptr) {
            return node;
        }

        return findRelative(current->mother, cautat);
    }

    NodeGen *addMother(NodeGen *child, char *name) {
        if(findRelative(root,name) == nullptr) {
            NodeGen *mother = new NodeGen();
            strcpy(mother->name,name);
            child->mother = mother;
            mother->children->addTail(child);

            return mother;
        }

        NodeGen *mother = findRelative(root,name);

        mother->children->addTail(child);
        child->mother = mother;

        return mother;
    }

    NodeGen *addFather(NodeGen *child, char *name) {
        if(findRelative(root,name) == nullptr) {
            NodeGen *father = new NodeGen();
            strcpy(father->name,name);
            child->father = father;
            father->children->addTail(child);

            return father;
        }

        NodeGen *father = findRelative(root,name);

        father->children->addTail(child);
        child->father = father;

        return father;
    }

    NodeGen *addMate(NodeGen *person, char *name) {
        if(findRelative(root,name) == nullptr) {
            NodeGen *mate = new NodeGen();
            strcpy(mate->name,name);
            person->mate = mate;
            mate->mate = person;

            return mate;
        }

        NodeGen *mate = findRelative(root,name);

        mate->mate = person;
        person->mate = mate;

        return mate;
    }

    void sortChildren() {
        Node<NodeGen*> *current = currentRelative->children->head;

        if(current == nullptr) {
            return;
        }

        for(int i = 0; i < currentRelative->children->lenght - 1 && current != nullptr; i++) {
            Node<NodeGen*> *aux = current->next;

            for(int j = i + 1; j < currentRelative->children->lenght && aux != nullptr; j++) {
                if(aux->data->age < current->data->age) {
                    NodeGen *aux2 = current->data;
                    currentRelative->children->removePosition(i);
                    currentRelative->children->addPosition(aux2,j);
                }

                aux = aux->next;
            }

            current = current->next;
        }

        currentRelative->children->lenght++;
    }

    NodeGen *createRelative() {
        NodeGen *node = new NodeGen();

        cout << "Name of the relative: ";
        cin >> node->name;

        cout << "Age of the relative: ";
        cin >> node->age;

        cout << "Is the relative alive?(1 or 0) ";
        cin >> node->isAlive;

        if(node->isAlive == true) {
            cout << "Is " << node->name << " married?(1 or 0) ";
        }
        else {
            cout << "Was " << node->name << " married?(1 or 0) ";
        }

        bool temp = false;
        cin >> temp;
        if(temp == true) {
            cout << "Name of the mate: ";
            char str[100] = {};
            cin >> str;
            if(strcmp(str,"mate") != 0) {
                addMate(node,str);
            }
        }

        cout << "Mother's name: ";
        char sir[100]{};
        cin >> sir;
        if(strcmp(sir,"-") != 0) {
            addMother(node,sir);
        }

        strcpy(sir, "");

        cout << "Father's name: ";
        cin >> sir;
        if(strcmp(sir,"-") != 0) {
            addFather(node,sir);
        }

        if(strcmp(root->name,"") == 0) root = node;
        currentRelative = node;

        return node;
    }

    void queueUp(Queue<NodeGen*> *queue, Node<NodeGen*> *current) {
        while(current != nullptr) {
            cout << current->data->name << " ";
            if(current->data->children->lenght != 0) {
                queue->push(current->data);
            }
            current = current->next;
        }
    }

    void afisare() {
        if(root == nullptr) return;
        cout << root->name << endl;

        Queue<NodeGen*> *queue = new Queue<NodeGen*>();
        queue->capacity = 100;
        Node<NodeGen*> *current = root->children->head;

        queueUp(queue,current);

        while(queue->peek() != nullptr) {
            current = queue->pop();

            queueUp(queue,current);
        }
    }
};*/
#endif //ARBOREGENEALOGIC_H