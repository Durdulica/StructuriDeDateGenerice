#ifndef ARBOREFISIER_H
#define ARBOREFISIER_H
#include "stiva.h"

//. mkdir - Creează directoare
//. touch - Creează fișiere goale
//. cd - Navighează între directoare (inclusiv ".." și "/")
//. ls - Listează conținutul directorului curent
//. pwd - Afișează calea curentă
//. tree - Afișează întreaga structură
//. writeFile/readFile - Scrie/citește conținutul fișierelor
//. rm - Șterge fișiere și directoare
//. find - Caută fișiere în întregul sistem

struct NodeFile {
    char fileName[100] = {};
    char data[100] = {};
};

struct NodeDir {
    char dirName[100] = {};
    List<NodeDir*> *dirList = new List<NodeDir*>;
    List<NodeFile*> *fileList = new List<NodeFile*>;
    NodeDir *parent = nullptr;
};

struct FileManager {
    NodeDir *root = new NodeDir();
    NodeDir *currentDir = new NodeDir();

    FileManager(char *nume) {
        strcpy(this->root->dirName,nume);
        this->currentDir = this->root;
    }

    void mkdir(char *nume) {
        NodeDir *newNode = new NodeDir();
        strcpy(newNode->dirName,nume);
        newNode->parent = this->currentDir;

        if(currentDir->dirList->lenght == 0) {
            currentDir->dirList->addHead(newNode);
        }
        else {
            currentDir->dirList->addTail(newNode);
        }
    }

    void touch(char *nume) {
        NodeFile *newNode = new NodeFile();
        strcpy(newNode->fileName,nume);

        currentDir->fileList->addTail(newNode);
    }

    NodeDir *findDir(char *nume) {
        Node<NodeDir*> *current = currentDir->dirList->head;

        while(current != nullptr) {
            if(strcmp(current->data->dirName, nume) == 0) {
                return current->data;
            }
            current = current->next;
        }

        return nullptr;
    }

    void cd(char *input) {
        if(strcmp(input,"..") == 0) {
            currentDir = currentDir->parent;
            return;
        }
        if(strcmp(input,"/") == 0) {
            char nume[100] = {};
            cin.getline(nume,100);

            if(findDir(nume)) {
                currentDir = findDir(nume);
            }
            else {
                cout << "Directory not found" << endl;
            }
        }
    }

    void ls() {
        Node<NodeDir*> *current = currentDir->dirList->head;

        while(current != nullptr) {
            cout << current->data->dirName << endl;
            current = current->next;
        }

        delete []current;

        Node<NodeFile*> *temp = currentDir->fileList->head;

        while(temp != nullptr) {
            cout << temp->data->fileName << endl;
            temp = temp->next;
        }

        delete []temp;
    }

    void pwd() {
        cout << root->dirName << " -> ";
        if(currentDir == root) {
            return;
        }

        Stiva<NodeDir*> *path = new Stiva<NodeDir*>();

        NodeDir *temp = currentDir;

        while(temp->parent != nullptr) {
            path->push(temp);
            temp = temp->parent;
        }

        while(path->peek() != nullptr) {
            cout << path->pop()->data->dirName << " -> ";
        }
    }

    NodeFile *findFile(char *nume) {
        Node<NodeFile*> *current = currentDir->fileList->head;

        while(current != nullptr) {
            if(strcmp(current->data->fileName, nume) == 0) {
                return current->data;
            }
        }

        return nullptr;
    }

    void writeFile(char *nume) {
        NodeFile *file = findFile(nume);

        if(file == nullptr) {
            cout << "File not found" << endl;
        }
        else {
            cin.getline(file->data,100);
        }
    }

    char *readFile(char *nume) {
        NodeFile *file = findFile(nume);

        if(file == nullptr) {
            cout << "File not found" << endl;
        }
        else {
            return file->data;
        }
    }
    ///todo: functie recursiva de stergere a unui director
    void rm() {
        currentDir->fileList->deleteList();
        currentDir->dirList->deleteList();
        delete currentDir;
    }

    NodeDir *find(NodeDir *current, char *nume) {
        if(current == nullptr) {
            return nullptr;
        }

        if(strcmp(current->dirName, nume) == 0) {
            return current;
        }

        if(current->dirList->lenght > 0) {
            if(findFile(nume) != nullptr) {
                currentDir = current;
                return currentDir;
            }

            Node<NodeDir*> *temp = current->dirList->head;
            while(temp != nullptr) {
                NodeDir *node = find(temp->data,nume);
                if(node != nullptr) {
                    currentDir = node;
                    return node;
                }
                temp = temp->next;
            }
        }

        return nullptr;
    }

    void spacing(int nr, int exception) {
        while(nr - exception > 3) {
            cout << " ";
            nr--;
        }
        cout << "-> ";
    }

    void next(Node<NodeDir*> *current, int counter) {
        Node<NodeFile*> *temp = current->data->parent->fileList->head;
        int exception = strlen(current->data->parent->dirName);

        while(temp != nullptr) {
            spacing(counter, exception);
            cout << temp->data->fileName << endl;
            temp = temp->next;
            exception = 0;
        }

        if(exception > 0) {
            exception += 4 + strlen(current->data->parent->dirName);
        }
        while(current != nullptr) {
            spacing(counter, exception);
            cout << current->data->dirName;
            if(current == current->data->parent->dirList->head) {
                counter += strlen(current->data->dirName) + 3;
            }

            if(current->data->dirList->lenght > 0) {
                counter += strlen(current->data->dirName);
                next(current->data->dirList->head, counter);
            }
            cout << endl;
            current = current->next;
        }
    }

    void tree() {
        if(currentDir == nullptr) {
            return;
        }
        cout << currentDir->dirName;

        if(currentDir->dirList->lenght == 0 && currentDir->dirList->lenght == 0) {
            return;
        }
        int counter = (int)strlen(currentDir->dirName) + 4;
        Node<NodeDir*> *current = currentDir->dirList->head;

        next(current,counter);
    }
};

#endif //ARBOREFISIER_H