#ifndef EXERCITIIARBORI_H
#define EXERCITIIARBORI_H
#include "arboreBinar.h"
#include "arboreGeneric.h"
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

int ctFrunzeNivelArbore(BinaryNode *current, int k) {
    if(current == nullptr) {
        return 0;
    }

    Queue<BinaryNode *> *queue = new Queue<BinaryNode *>;
    queue->capacity = 100;
    queue->push(current);
    int ind = 1;
    while(!queue->isEmpty()) {
        int size = queue->count, ct = 0;
        for(int i = 0; i < size; i++) {
            current = queue->pop()->data;
            if(current->left != nullptr) {
                queue->push(current->left);
            }
            if(current->right != nullptr) {
                queue->push(current->right);
            }

            if(current->left == nullptr && current->right == nullptr) {
                ct++;
            }
        }
        if(ind == k) {
            return ct;
        }
        ind++;
    }
    return 0;
}

void ex15() {
    ArboreBinar *arbore = new ArboreBinar(30);
    citireArbore(arbore);

    cout << ctFrunzeNivelArbore(arbore->root, 2);
}

//sa se verif. daca arborele contine perechi de valori consec (x; x+1), memorate in vf aflate in relatia tata-fiu

bool perechiConsecArbore(BinaryNode *current) {
    if(current == nullptr) {
        return false;
    }
    Queue<BinaryNode *> *queue = new Queue<BinaryNode *>;
    queue->capacity = 100;
    queue->push(current);
    while(!queue->isEmpty()) {
        int size = queue->count;
        for(int i = 0; i < size; i++) {
            current = queue->pop()->data;
            if(current->left != nullptr) {
                if(current->left->data + 1 == current->data) {
                    return true;
                }
                queue->push(current->left);
            }
            if(current->right != nullptr) {
                if(current->data + 1 == current->right->data) {
                    return true;
                }
                queue->push(current->right);
            }
        }
    }
    return false;
}

void ex16() {
    ArboreBinar *arbore = new ArboreBinar(30);
    citireArbore(arbore);

    cout << perechiConsecArbore(arbore->root);
}

//sa se realizeze operatia find-replace, adica toate nodurile din arbore de val. x vor fi regasite si inlocuite cu val. y

void findReplaceArbore(BinaryNode *current, int x, int y) {
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
                queue->push(current->left);
            }
            if(current->right != nullptr) {
                queue->push(current->right);
            }

            if(current->data == x) {
                current->data = y;
            }
        }
    }
}

void ex17() {
    ArboreBinar *arbore = new ArboreBinar(30);
    citireArbore(arbore);

    findReplaceArbore(arbore->root, 30, 67);
    arbore->afisare();
}

//sa se verifice daca doi arbori sunt egali

bool arboriEgali(BinaryNode* root1, BinaryNode* root2) {
    if(root1 == nullptr || root2 == nullptr) {
        return false;
    }

    Queue<BinaryNode *> *queue1 = new Queue<BinaryNode *>;
    queue1->capacity = 100;
    queue1->push(root1);
    Queue<BinaryNode *> *queue2 = new Queue<BinaryNode *>;
    queue2->capacity = 100;
    queue2->push(root2);

    while(!queue1->isEmpty() && !queue2->isEmpty()) {
        if(queue1->count != queue2->count) {
            return false;
        }
        int size = queue1->count;
        for(int i = 0; i < size; i++) {
            root1 = queue1->pop()->data;
            root2 = queue2->pop()->data;
            cout << root1->data << " " << root2->data << "  ";
            if(root1->data != root2->data) {
                return false;
            }

            if(root1->left != nullptr || root2->left != nullptr) {
                if(root1->left == nullptr || root2->left == nullptr) {
                    queue1->deleteQueue();
                    queue2->deleteQueue();
                    return false;
                }

                queue1->push(root1->left);
                queue2->push(root2->left);
            }

            if(root1->right != nullptr || root2->right != nullptr) {
                if(root1->right == nullptr || root2->right == nullptr) {
                    queue1->deleteQueue();
                    queue2->deleteQueue();
                    return false;
                }
                queue1->push(root1->right);
                queue2->push(root2->right);
            }
        }
    }
    return true;
}

void ex18() {
    ArboreBinar *arb1 = new ArboreBinar(30);
    ArboreBinar *arb2 = new ArboreBinar(30);
    citireArbore(arb1);
    citireArbore(arb2);

    cout << arboriEgali(arb1->root, arb2->root) << endl;
}

//sa se verif. daca subarborii stangi si drepti al unui arbore au structura in oglinda

bool structOglindaArbore(NodeGen<int> *left, NodeGen<int> *right) {
    if(left == nullptr || right == nullptr) {
        if(left == nullptr && right == nullptr) {
            return true;
        }
        return false;
    }

    Queue<NodeGen<int> *> *queue1 = new Queue<NodeGen<int> *>;
    queue1->capacity = 100;
    queue1->push(left);
    Queue<NodeGen<int> *> *queue2 = new Queue<NodeGen<int> *>;
    queue2->capacity = 100;
    queue2->push(right);

    while(!queue1->isEmpty() && !queue2->isEmpty()) {
        if(queue1->count != queue2->count) {
            return false;
        }
        int size = queue1->count;
        for(int i = 0; i < size; i++) {
            left = queue1->pop()->data;
            right = queue2->pop()->data;

            if(left->data != right->data) {
                return false;
            }

            if(left->left != nullptr || right->right != nullptr) {
                if(left->left == nullptr || right->right == nullptr) {
                    queue1->deleteQueue();
                    queue2->deleteQueue();
                    return false;
                }
                queue1->push(left->left);
                queue2->push(right->right);
            }

            if(left->right != nullptr || right->left != nullptr) {
                if(left->right == nullptr || right->left == nullptr) {
                    queue1->deleteQueue();
                    queue2->deleteQueue();
                    return false;
                }
                queue1->push(left->right);
                queue2->push(right->left);
            }
        }
    }
    return true;
}

void ex19() {
    ArboreGeneric<int> *arbore = new ArboreGeneric<int>;
    arbore->root = arbore->citirePre();

    cout << structOglindaArbore(arbore->root->left, arbore->root->right);
}

//sa se scrie o functie care verif. cate noduri pare sunt intr-un arbore. Sa se foloseasca aceasta fc. pt. identificarea
//subarborelui radacinii ce contine cel mai multe valori pare

int ctPareArbore(NodeGen<int> *node) {
    if(node == nullptr) {
        return 0;
    }

    if(node->data % 2 == 0) {
        return 1 + ctPareArbore(node->left) + ctPareArbore(node->right);
    }

    return ctPareArbore(node->left) + ctPareArbore(node->right);
}

NodeGen<int>* maxPareArbore(NodeGen<int> *node) {
    if(node == nullptr) {
        return nullptr;
    }

    if(ctPareArbore(node->left) >= ctPareArbore(node->right) && ctPareArbore(node->left) == ctPareArbore(node)) {
        return maxPareArbore(node->left);
    }


    if(ctPareArbore(node->right) > ctPareArbore(node->left) && ctPareArbore(node->right) == ctPareArbore(node)) {
        return maxPareArbore(node->right);
    }

    return node;
}

void ex20() {
    ArboreGeneric<int> *arbore = new ArboreGeneric<int>;
    arbore->root = arbore->citirePre();

    NodeGen<int> *max = maxPareArbore(arbore->root);

}

//sa se afiseze succesiv nodul primului vf. de pe fiecare nivel al arborelui

void afisLeftArbore(NodeGen<int>* current) {
    if(current == nullptr) {
        return;
    }
    cout << current->data << " ";
    return afisLeftArbore(current->left);
}

void ex21() {
    ArboreGeneric<int> *arbore = new ArboreGeneric<int>;
    arbore->root = arbore->citirePre();
    afisLeftArbore(arbore->root);
}

//sa se afiseze succesiv nodul din st. vf. si din dr. vf. alternativ

void afisAlternativaArbore(NodeGen<int>* current, int k = 0) {
    if(current == nullptr) {
        return;
    }
    cout << current->data << " ";
    if(k == 0) {
        afisAlternativaArbore(current->left, 1);
    }else {
        afisAlternativaArbore(current->right, 0);
    }
}

void ex22() {
    ArboreGeneric<int> *arbore = new ArboreGeneric<int>;
    arbore->root = arbore->citirePre();

    afisAlternativaArbore(arbore->root);
}

//sa se gaseasca al x-lea nod afisat la parcurgerea in postordine

NodeGen<int>* xElemPostArbore(NodeGen<int>* current, int x,int&ct) {
    if(current == nullptr) {
        return nullptr;
    }
    NodeGen<int> *p = xElemPostArbore(current->left, x,ct);
    if(p != nullptr) {
        return p;
    }
    NodeGen<int> *p1 = xElemPostArbore(current->right, x,ct);
    if(p1 != nullptr) {
        return p1;
    }
    if(x == ct) {
        return current;
    }
    ct++;
    return nullptr;
}

void ex23() {
    ArboreGeneric<int> *arbore = new ArboreGeneric<int>;
    arbore->root = arbore->citirePre();
    int x = 1, ind = 0;

    NodeGen<int> *node = xElemPostArbore(arbore->root, x,ind);
    cout << node->data;
}

//sa se genereze un arbore de cautare din n noduri, generate aleator, care sunt cuburi perfecte

bool isCube(int nr) {
    if(nr < 8) {
        return false;
    }
    for(int i = 2; i <= nr / 3; i++) {
        if(i * i * i == nr) {
            return true;
        }
    }
    return false;
}

void citireAleatorieArbBin(ArboreBinar *arbore, int n) {
    srand(time(nullptr));
    for(int i = 0; i < n; i++) {
        int aux = rand();
        while(aux > 50) {
            aux = rand();
        }
        if(isCube(aux)) {
            arbore->addChild(arbore->root, aux);
        }
        else {
            arbore->addChild(arbore->root, aux * aux * aux);
        }
    }
}

int minArbBin(BinaryNode *root) {
    if(root == nullptr) {
        return 0;
    }

    while(root->left != nullptr) {
        root = root->left;
    }

    return root->data;
}

int maxArbBin(BinaryNode *root) {
    if(root == nullptr) {
        return 0;
    }

    while(root->right != nullptr) {
        root = root->right;
    }

    return root->data;
}

void ex24() {
    ArboreBinar *arbore = new ArboreBinar(64);
    int n = 7;
    citireAleatorieArbBin(arbore,n);

    arbore->afisare();
    cout << minArbBin(arbore->root) << " " << maxArbBin(arbore->root) << endl;
}

//sa se construiasca un vec. cu inf. unui arbore binar plasate in ordine crescatoare

void vecArbBin(BinaryNode *root, int v[], int&dim) {
    if(root == nullptr) {
        return;
    }
    vecArbBin(root->left, v, dim);
    v[dim++] = root->data;
    vecArbBin(root->right, v, dim);
}

void ex25() {
    ArboreBinar *arbore = new ArboreBinar(64);
    citireArbore(arbore);
    int v[100]{}, dim = 0;
    vecArbBin(arbore->root, v,dim);

    for(int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
}

//sa se insereze intr-un arbore de cautare pentru fiecare frunza o val. egala cu dublul frunzei si sa se afis. rez. in preordine

void add2xLeafArbBin(ArboreBinar *arbore) {
    if(arbore == nullptr) {
        return;
    }

    BinaryNode *current = nullptr;
    Queue<BinaryNode *> *queue = new Queue<BinaryNode*>;
    queue->capacity = 100;
    queue->push(arbore->root);

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
                arbore->addChild(arbore->root,current->data * 2);
            }
        }
    }
}

void ex26() {
    ArboreBinar *arbore = new ArboreBinar(50);
    citireArbore(arbore);

    add2xLeafArbBin(arbore);
    arbore->preorder(arbore->root);
}
#endif //EXERCITIIARBORI_H