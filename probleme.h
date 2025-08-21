#ifndef PROBLEME_H
#define PROBLEME_H
#include "stiva.h"
///lista

//sa se elim. toate duplicatele dintr-o lista

void elimDuplicate() {
        List<int> *list = new List<int>;
        Node<int>* current = list->head;
        while(current != nullptr) {

            Node<int>* temp = current;
            while(temp->next != nullptr) {
                if(temp->next->data == current->data) {

                    Node<int>* aux = temp->next;
                    temp->next = temp->next->next;
                    delete aux;
                }
                temp = temp->next;
            }
            current = current->next;
        }
    }

//sa se gaseasca al k-lea elem. de la sf. listei intr-o singura parcurgere

Node<int>* elemKDeLaSfarsit(int k) {
        List<int> *list = new List<int>;
        Node<int>* current1 = list->head;
        Node<int>* current2 = list->head;

        for(int i = 0; i < k; i++) {
            if(current1==nullptr) return nullptr;
            current1 = current1->next;
        }

        while(current1!=nullptr) {
            current2 = current2->next;
            current1 = current1->next;
        }

        return current2;
    }

//sa se det. daca doua liste se intersecteaza si sa se gaseasca nodul comun

Node<int>* gasesteIntersectie(Node<int> *head1, Node<int> *head2) {
        if(head1==nullptr || head2==nullptr) return nullptr;
        Node<int>* temp1 = head1;
        Node<int>* temp2 = head2;

        /*int length1 = 0, length2 = 0;

        while(temp1!=nullptr) {
            length1++;
            temp1 = temp1->next;
        }

        while(temp2!=nullptr) {
            length2++;
            temp2 = temp2->next;
        }

        temp1 = head1;
        temp2 = head2;*/

        while(temp1!=nullptr && temp2!=nullptr) {
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nullptr;
    }

//sa se sorteze o lista care contine doar 0,1,2 intr-o singura parcurgere

void sort() {
        List<int> *list = new List<int>;
        if(list->head==nullptr) return;

        Node<int>* current = list->head;
        int count[3] = {0,0,0}, ct = 0;

        while(current!=nullptr) {
            ++count[current->data];
            ct++;
            current = current->next;
        }

        current = list->head;

        while(current!=nullptr) {
            if(count[ct] == 0) {
                ct++;
            }
            else {
                current->data = ct;
                count[ct]--;
                current = current->next;
            }
        }
    }

//doua nr. sunt repr. ca liste inalntuite. Calc. suma lor

int oglindit(int nr) {
        int o = 0;
        while(nr!=0) {
            o = nr % 10 + o * 10;
            nr /= 10;
        }
        return o;
    }

int sumList(Node<int>* head1, Node<int>* head2) {
        if(head1==nullptr || head2==nullptr) return 0;

        Node<int>* current1 = head1;
        Node<int>* current2 = head2;
        int rez = 0, len1 = 0, len2 = 0;

        while(current1!=nullptr) {
            current1 = current1->next;
            len1++;
        }

        while(current2!=nullptr) {
            current2 = current2->next;
            len2++;
        }

        current1 = head1;
        current2 = head2;

        int ct = 0;
        for(int i = 0; i < len1 && i < len2; i++) {
            int sum = current1->data + current2->data;
            cout << sum << " = " << current1->data << " + " << current2->data << endl;
            if(sum > 9) {
                rez += sum % 10;
                sum /= 10;
                rez *= 10;
                rez += sum;
                ct = 1;
            }
            else {
                rez += sum;
                rez *= 10;
                ct = 0;
            }

            current1 = current1->next;
            current2 = current2->next;
        }

        if(ct == 0) rez /= 10;
        return oglindit(rez);
    }

///stiva

//sa se verifice daca o expr. este corect parantezata {[()]}

bool esteValidaExpr() {
    Stiva<char>* stiva= new Stiva<char>();

    char x[10]="{[(])}";

    if (x[0] == '\0') return false;

    for (int i = 0; x[i] != '\0'; i++) {
        char c = x[i];
        if(c == '{' || c == '[' || c == '(') {
            stiva->push(c);
        }
        else if(c == '}' || c == ']' || c == ')') {
            char temp = stiva->pop()->data;
            if(temp == '{' && x[i] != '}' || temp == '[' && x[i] != ']' || temp == '(' && x[i] != ')') return false;
        }
    }

    return true;
}

//pentru fiecare elem. din array gaseste primul elem. mai mare din dr.

void afisVec(int v[], int dim) {
    for(int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void urmatorulMaiMare(int v[], int n) {
    Stiva<int>* stiva= new Stiva<int>();
    int *rez = new int[n];

    for(int i = n - 1; i >= 0; i--) {
        while(!stiva->isEmpty() && stiva->top->data <= v[i])
            stiva->pop();

        if(stiva->isEmpty()) {
            rez[i] = -1;
        }
        else {
            rez[i] = stiva->peek()->data;
        }

        stiva->push(v[i]);
    }

    afisVec(rez, n);
    stiva->deleteStack();
    delete []rez;
}

//todo: sa se calc. aria max. a unui dreptunghi intr-o histograma

//creeaza o stiva care suporta push, pop si getMin in O(1)
struct NodeMin {
    int data;
    NodeMin* next = nullptr;
    int minSoFar;
};

struct StivaMin {
    NodeMin* top = nullptr;

    NodeMin* push(int nr) {
        NodeMin* node = new NodeMin();
        node->data = nr;

        if(top==nullptr) {
            top = node;
            top->minSoFar = node->data;
            return node;
        }

        if(node->data < top->minSoFar) {
            node->minSoFar = node->data;
        }else {
            node->minSoFar = top->minSoFar;
        }
        node->next = top;
        top = node;
        return top;
    }

    NodeMin* pop() {
        if(top==nullptr) return nullptr;

        NodeMin* temp = top;
        top = top->next;
        return temp;
    }

    int getMin() {
        return top->minSoFar;
    }
};

//sorteaza o  stiva folosind doar operatii de stiva

Stiva<int>* sortStack(Stiva<int> stiva) {
    Stiva<int>* tempStiva = new Stiva<int>();

    while(!stiva.isEmpty()) {
        int temp = stiva.pop()->data;

        while(!tempStiva->isEmpty() && tempStiva->peek()->data < temp) {
            stiva.push(tempStiva->pop()->data);
        }
        tempStiva->push(temp);
    }

    return tempStiva;
}

///coada

//gaseste primul caracter care nu se repeta intr-un sir de caractere

char neRepetat(char sir[]) {
    Queue<char>* queue = new Queue<char>();
    queue->capacity = strlen(sir);

    int counter[256]{};

    for(int i = 0; i < strlen(sir); i++) {
        if(counter[sir[i]] == 0) {
            queue->push(sir[i]);
        }
        counter[sir[i]]++;
    }

    while(!queue->isEmpty() && counter[queue->peek()->data] > 1) {
        queue->pop();
    }

    if(queue->isEmpty()) {
        return '*';
    }

    return queue->peek()->data;
}

//roteste o coada cu k pozitii la dreapta

Queue<int>* rotesteCuK(Queue<int>* queue, int k) {
    for(int i = 0; i < k; i++) {
        Node<int>* temp  = queue->pop();
        queue->push(temp->data);
    }
    return queue;
}

//interschimba prima jumatate a cozii cu a doua

void interschimbaJumatati(Queue<int>* queue) {
    if(queue->count % 2 != 0) return;
    rotesteCuK(queue, queue->count/2);
}

//gaseste maximul in fiecare fereastra de dim k dintr-un array

void maximFereastraK(int v[], int dim, int k) {
    Queue<int>* queue = new Queue<int>();
    int rez[dim] = {}, counter = 0;
    queue->capacity = k;

    for(int i = 0; i < dim; i++) {
        queue->push(v[i]);
        if(queue->count == k) {
            rez[counter++] = queue->getMax();
            queue->pop();
        }
    }

    for(int i = 0; i < counter; i++) {
        cout << rez[i] << " ";
    }
    cout << endl;
    queue->deleteQueue();
}

///probleme combinate

//verifica daca un string este palindrom folosind o stiva si o coada

bool ePalindrom(char sir[]) {
    Stiva<char>* stiva = new Stiva<char>();
    Queue<char>* queue = new Queue<char>();
    queue->capacity = strlen(sir);

    for(int i = 0; i < strlen(sir); i++) {
        stiva->push(sir[i]);
        queue->push(sir[i]);
    }

    while(!stiva->isEmpty() && !queue->isEmpty()) {

        if(stiva->pop()->data != queue->pop()->data) {
            return false;
        }
    }
    return true;
}

//verifica daca o secventa de popuri este valida pentru o secventa de pushuri

bool verificaSecventa(int v1[], int v2[], int dim) {
    Queue<int>* queue = new Queue<int>();
    queue->capacity = dim;
    for(int i = 0; i < dim; i++) {
        queue->push(v1[i]);
    }

    int counter = 0;
    for(int i = 0; i < dim; i++) {

        while(!queue->isEmpty() && counter < dim && queue->peek()->data == v2[counter]) {
            queue->pop();
            counter++;
        }
        if(queue->isEmpty()) {
            return true;
        }
        rotesteCuK(queue,1);
    }
    return false;
}

//gaseste lungimea celui mai lung subsir valid de paranteze

int lungimeMaximaParanteze(char sir[]) {
    Stiva<int>* stiva = new Stiva<int>();
    stiva->push(-1);

    if(sir[0] == '\0') return -1;
    int counter = 0;
    for(int i = 0; i < strlen(sir); i++) {
        if(sir[i] == '(') {
            stiva->push(i);
        }
        else {
            stiva->pop();

            if(stiva->isEmpty()) {
                stiva->push(i);
            }
            else {
                int temp = i - stiva->peek()->data;
                if(temp > counter) {
                    counter = temp;
                }
            }
        }
    }
    return counter;
}

//simuleaza un sistem de ticketing cu prioritati folosind cozi multiple


#endif //PROBLEME_H