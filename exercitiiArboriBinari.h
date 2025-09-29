#ifndef EXERCITIIARBORI_H
#define EXERCITIIARBORI_H
#include "arboreBinar.h"

//sa se afis frunzele unui arbore binar

void citireArbore(ArboreBinar *arbore) {
    int n;
    cout << "nr. de noduri: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arbore->addChild(arbore->root,x);
    }
}

void afisVec(int v[], int size) {
    for(int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void ex1() {
    ArboreBinar *arbore = new ArboreBinar(50);
    citireArbore(arbore);

    BinaryNode *current = arbore->root;
    Queue<BinaryNode*> *queue = new Queue<BinaryNode*>();
    queue->capacity = 100;
    queue->push(current);

    while(!queue->isEmpty()) {
        int size = queue->count;
        for(int i = 0; i < size; i++) {
            current = queue->pop()->data;
            if(current->left != nullptr) {
                queue->push(current->left);
            }
            if(current->right != nullptr) {
                queue->push(current->right);
            }

            if(current->left == nullptr && current->right == nullptr) {
                cout << current->data << " ";
            }
        }
    }
}

//sa se afis. diferenta intre suma subarborelui drept si suma subarborelui stang

int sumaArbore(BinaryNode *current) {
    if(current == nullptr) {
        return 0;
    }
    return current->data + sumaArbore(current->left) + sumaArbore(current->right);
}

void ex2() {
    ArboreBinar *arbore = new ArboreBinar(7);
    citireArbore(arbore);
    cout << sumaArbore(arbore->root->right) - sumaArbore(arbore->root->left);
}

//se dau k noduri din arbore si ce cere det. a nr. de noduri din subarborele cu radacina in acel nod

int ctNodArbore(BinaryNode *current) {
    if(current == nullptr) {
        return 0;
    }

    return 1 + ctNodArbore(current->left) + ctNodArbore(current->right);
}

void ex3() {
    ArboreBinar *arbore = new ArboreBinar(7);
    citireArbore(arbore);

    int k;
    cin >> k;
    int v[k] = {};
    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        v[i] = ctNodArbore(arbore->search(temp));
    }

    afisVec(v,k);
}

//se dau k noduri din arbore si se cere det. a nr. de noduri din subarborele cu radacina in acel nod care contin valori prime

bool isPrim(int nr) {
    if(nr < 2) {
        return false;
    }
    for(int i = 2; i * i <= nr; i++) {
        if(nr % i == 0) {
            return false;
        }
    }
    return true;
}

int ctNodPrimArbore(BinaryNode *current) {
    if(current == nullptr) {
        return 0;
    }
    if(isPrim(current->data)) {
        return 1 + ctNodPrimArbore(current->left) + ctNodPrimArbore(current->right);
    }
    return ctNodPrimArbore(current->left) + ctNodPrimArbore(current->right);
}

void ex4() {
    ArboreBinar *arbore = new ArboreBinar(7);
    citireArbore(arbore);
    int k;
    cin >> k;
    int v[k] = {};
    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        v[i] = ctNodPrimArbore(arbore->search(temp));
    }

    afisVec(v,k);
}

//sa se afis. nr. de nivele din arbore si nr. de noduri de pe fiecare nivel

void afisNoduriArbore(BinaryNode *root) {
    Queue<BinaryNode *> *queue = new Queue<BinaryNode*>();
    queue->capacity = 100;
    queue->push(root);
    while(!queue->isEmpty()) {
        int size = queue->count, ct = 0;
        for(int i = 0; i < size; i++) {
            BinaryNode *current = queue->pop()->data;
            if(current->left != nullptr) {
                queue->push(current->left);
            }
            if(current->right != nullptr) {
                queue->push(current->right);
            }
            ct++;
        }
        cout << ct << " ";
    }
}

void ex5() {
    ArboreBinar *arbore = new ArboreBinar(7);
    citireArbore(arbore);
    cout << arbore->getHeight(arbore->root) << endl;
    afisNoduriArbore(arbore->root);
}

//sa se det. val. memorate de descendentii directi ai radacinii arborelui

void ex6() {
    ArboreBinar *arbore = new ArboreBinar(7);
    citireArbore(arbore);

    cout << arbore->root->left << " " << arbore->root->right << endl;
}

//sa se afis val memorate in subarborele stang al radacinii in urma parcurgerii in preordine

void ex7() {
    ArboreBinar *arbore = new ArboreBinar(67);
    citireArbore(arbore);

    arbore->preorder(arbore->root->left);
}

//sa se afis. val. din nodurile neterminale ale arborelui in ord. descresc

void afisNodNeterminalDescrescArbore(BinaryNode *current) {
    if(current == nullptr) {
        return;
    }

    afisNodNeterminalDescrescArbore(current->right);
    if(current->left != nullptr || current->right != nullptr) {
        cout << current->data << " ";
    }
    afisNodNeterminalDescrescArbore(current->left);
}

void ex8() {
    ArboreBinar *arbore = new ArboreBinar(67);
    citireArbore(arbore);

    afisNodNeterminalDescrescArbore(arbore->root);
}

//sa se det. cate noduri din arbore au un singur copil

int ctNod1CopilArbore(BinaryNode *current) {
    if(current == nullptr) {
        return 0;
    }

    if(current->left != nullptr && current->right != nullptr) {
        return ctNod1CopilArbore(current->left) + ctNod1CopilArbore(current->right);
    }
    if(current->right == nullptr && current->left != nullptr) {
        return 1 + ctNod1CopilArbore(current->left);
    }

    if(current->left == nullptr && current->right != nullptr) {
        return 1 + ctNod1CopilArbore(current->right);
    }

    return 0;
}

void ex9() {
    ArboreBinar *arbore = new ArboreBinar(67);
    citireArbore(arbore);

    cout << ctNod1CopilArbore(arbore->root) << endl;
}

//sa se det val. max. din subarborii stang si drept ai radacinii

int maxArbore(BinaryNode *current, int maxim = INT_MIN) {
    if(current == nullptr) {
        return maxim;
    }

    if(current->data > maxim) {
        return max(maxArbore(current->left, current->data), maxArbore(current->right, current->data));
    }

    return max(maxArbore(current->left, maxim), maxArbore(current->right, maxim));
}

void ex10() {
    ArboreBinar *arbore = new ArboreBinar(67);
    citireArbore(arbore);

    cout << maxArbore(arbore->root->left) << " " << maxArbore(arbore->root->right) << endl;
}

//sa se det cele mai mici valori nr. prim din subarborii stang si drept ai radacinii

int minPrimArbore(BinaryNode *current, int minim = INT_MAX) {
    if(current == nullptr) {
        return minim;
    }

    if(isPrim(current->data) && current->data < minim) {
        return min(minPrimArbore(current->left, current->data), minPrimArbore(current->right, current->data));
    }

    return min(minPrimArbore(current->left, minim), minPrimArbore(current->right, minim));
}

void ex11() {
    ArboreBinar *arbore = new ArboreBinar(70);
    citireArbore(arbore);

    cout << minPrimArbore(arbore->root) << endl;
}

//sa se afis suma tuturor nodurilor de pe nivelul k

int sumaNodNivelArbore(BinaryNode *current, int k) {
    if(current == nullptr) {
        return 0;
    }

    Queue<BinaryNode *> *queue = new Queue<BinaryNode *>;
    queue->capacity = 100;
    queue->push(current);
    int ct = 0;
    while(!queue->isEmpty()) {
        int size = queue->count, sum = 0;
        for(int i = 0; i < size; i++) {
            current = queue->pop()->data;
            if(current->left != nullptr) {
                queue->push(current->left);
            }
            if(current->right != nullptr) {
                queue->push(current->right);
            }

            if(ct == k) {
                sum += current->data;
            }
        }
        if(ct == k) {
            return sum;
        }
        ct++;
    }

    return 0;
}

void ex12() {
    ArboreBinar *arbore = new ArboreBinar(70);
    citireArbore(arbore);

    cout << sumaNodNivelArbore(arbore->root,2);
}

//sa se elim. toate frunzele din arbore

void elimFrunzeArbore(BinaryNode *current) {
    if(current == nullptr) {
        return;
    }

    Queue<BinaryNode *> *queue = new Queue<BinaryNode *>;
    queue->capacity = 100;
    queue->push(current);

    while(!queue->isEmpty()) {
        int size = queue->count;
        for(int i = 0; i < size; i++) {
            current = queue->pop()->data;
            if(current->left != nullptr) {
                if(current->left->left == nullptr && current->left->right == nullptr) {
                    delete current->left;
                    current->left = nullptr;
                }else {
                    queue->push(current->left);
                }
            }
            if(current->right != nullptr) {
                if(current->right->right == nullptr && current->right->left == nullptr) {
                    delete current->right;
                    current->right = nullptr;
                }else {
                    queue->push(current->right);
                }
            }
        }
    }
}

void ex13() {
    ArboreBinar *arbore = new ArboreBinar(70);
    citireArbore(arbore);

    elimFrunzeArbore(arbore->root);
    arbore->afisare();
}

//sa se verif. daca arborele este plin(fiecare nivel este complet, contine 2 la puterea k-1 vf.)

int pow2(int x) {
    int result = 2;
    if(x < 1) {
        return 1;
    }
    for(int i = 1; i < x; i++) {
        result *= 2;
    }
    return result;
}

bool isFull(BinaryNode *current, int height) {
    if(current == nullptr) {
        return false;
    }

    Queue<BinaryNode *> *queue = new Queue<BinaryNode *>;
    queue->capacity = 100;
    queue->push(current);

    int lvl = 1;
    while(!queue->isEmpty()) {
        int size = queue->count, ct = 0;
        for(int i = 0; i < size; i++) {
            current = queue->pop()->data;
            if(current->left != nullptr) {
                queue->push(current->left);
                ct++;
            }
            if(current->right != nullptr) {
                queue->push(current->right);
                ct++;
            }
        }
        cout << ct << " " << pow2(lvl) << endl;
        if(ct != pow2(lvl)) {
            return false;
        }
        if(lvl == height - 1) {
            break;
        }
        lvl++;
    }
    return true;
}

void ex14() {
    ArboreBinar *arbore = new ArboreBinar(30);
    citireArbore(arbore);

    cout << isFull(arbore->root, arbore->getHeight(arbore->root)) << endl;
}

//sa se det. nr. de frunze situate pe un nivel k


void ex15() {
    ArboreBinar *arbore = new ArboreBinar(30);
    citireArbore(arbore);


}
#endif //EXERCITIIARBORI_H