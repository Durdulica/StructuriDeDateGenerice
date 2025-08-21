#ifndef EXERCITIIBAC_H
#define EXERCITIIBAC_H
#include "stiva.h"

//Varianta 1: se considera o coada. Sa se afis nr. nodurilor dupa AD, EL, EL, AD, EL, AD

void ex1() {
    Queue<int> *queue = new Queue<int>();
    queue->capacity = 100;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        queue->push(aux);
    }

    queue->push(4);
    queue->pop();
    queue->pop();
    queue->push(5);
    queue->pop();
    queue->push(3);

    cout << queue->count << endl;
    queue->deleteQueue();
}

//Varianta 2: se considera o stiva. Sa se afiseze val. din vf. stivei si suma elem. aflate in stiva in urma executarii:
//AD(4), EL, AD(5), EL, AD(6), EL, EL

void ex2() {
    Stiva<int> *stiva = new Stiva<int>();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        stiva->push(aux);
    }

    stiva->push(4);
    stiva->pop();
    stiva->push(5);
    stiva->pop();
    stiva->push(6);
    stiva->pop();
    stiva->pop();

    Stiva<int> *temp = stiva;
    int suma = 0;
    while(temp->peek() != nullptr) {
        suma += temp->peek()->data;
        temp->pop();
    }

    cout << suma << endl;
    cout << stiva->peek()->data << endl;

    stiva->deleteStack();
    temp->deleteStack();
}

//Varianta 6: se considera o lista liniara simplu inlantuita. Sa se elim. ultimul nod al listei

void ex3() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;

    while(current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

//Varianta 7: se considera o lista simplu inlantuita. Sa se afis cea mai mare dintre valorile memorate de elem. din lista

void ex4() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;

    while(current->next != nullptr) {
        if(current->next->data < current->data) {
            current->next->data = current->data;
        }
        current = current->next;
    }

    cout << current->data << endl;
    list->deleteList();
}

//Varianta 8: se considera o lista liniara simplu inlantuita. Sa se afis. suma tuturor valorilor elem. listei

void ex5() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;
    int suma = current->data;
    while(current != nullptr) {
        suma += current->data;
        current = current->next;
    }
    cout << suma << endl;
}

//Varianta 9:se considera o lista simpu inlantuita. Ce se va afisa in urma executarii secventei

void ex6() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;

    while(current != nullptr && current->next != nullptr) {
        cout << current->data << " ";
        current->next = current->next->next;
        current = current->next;
    }
}

//Varianta 10: se considera o lista simplu inlantuita. Ce se va afisa in urma executarii secventei

void ex7() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;
    while(current != nullptr && current->next != nullptr) {
        current->next = current->next->next;
        current = current->next;
        cout << current->data << " ";
    }
}

//Varianta 11: se considera o lista inlantuita cu c. p. 3 noduri. Sa se scrie o expresie a carei valoare este egala cu suma val. reale reinute
//in primele trei noduri ale listei

void ex8() {
    List<float> *list = new List<float>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        float aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<float> *current = list->head;
    float s = 0;
    int ct = 0;
    while(current != nullptr && ct < 3) {
        s = s + current->data;
        current = current->next;
        ct++;
    }
    cout << s << endl;
}

//Varianta 12: se considera o lista inlantuita cu 4 noduri. Care va fi continutul listei in urma executarii secventei

void ex9() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;
    list->head = current->next;
    current->next = nullptr;
    list->head->next->next->next = current;
}

//Varianta 13: se considera o lista inlantuita cu min. 5 noduri. Adresa carui nod va fi memoratea in variabila b?

void ex10() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;
    Node<int> *a = current;
    Node<int> *b = new Node<int>();

    while(a->next != nullptr) {
        b = a;
        a = a->next;
    }

    cout << b->data;
}
//in variabila b se va memora penultimul nod al listei

//Varianta 14: se considera o lista inlantuita.  Ce se va afisa in urma executarii secventei

void ex11() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;
    int s = 0;
    while(current->next != nullptr) {
        if(current->data % 5 == 0)
            s = s + current->data;
        current = current->next;
    }

    cout << s << endl;
}

//Varianta 15: se considera o lista simplu inlantuita. Ce se va afisa in urma executarii secventei

void ex12() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    Node<int> *current = list->head;

    while(current != nullptr && current->data % 2 == 0)
        current = current->next;
    if(current != nullptr)
        cout << current->data;
    else
        cout << -1;
}

//Varianta 16: se considera o lista simplu inlantuita. Sa se scrie o secventa in care sa se afis. adevarat daca m. a.
//dintre val. primelor 2 elem. din lista este mai mica sau c. p. egala cu 4.75 respectiv fals

void ex13() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    if((float)(list->head->data + list->head->next->data) / 2 <= 4.75)
        cout << "adevarat";
    else
        cout << "fals";
}

//Varianta 19: se considera o lista simplu inlantuita. Sa se scrie o secventa care copiaza in al doilea nod al listei continutul primului nod din lista

void ex14() {
    List<int> *list = new List<int>();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        list->addTail(aux);
    }

    list->head->next->data = list->head->data;

}
#endif //EXERCITIIBAC_H
