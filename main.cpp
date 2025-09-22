#include "arboreBinar.h"

int main() {
    ArboreBinar *arbore = new ArboreBinar(50);
    arbore->addChild(arbore->root, 40);
    arbore->addChild(arbore->root, 20);
    arbore->addChild(arbore->root, 60);
    arbore->addChild(arbore->root, 30);
    arbore->addChild(arbore->root, 10);
    arbore->addChild(arbore->root, 45);
    arbore->addChild(arbore->root, 55);

    cout << arbore->getDepth(20);

}
