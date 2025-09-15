#include "arboreExpresii.h"

int main() {
    string expr;
    cout << "Enter an expression (use + - * / and parantheses): ";
    getline(cin, expr);

    Expresii *arbore = new Expresii();

    string postfix[100];
    int n = arbore->infixToPostfix(expr, postfix);

    arbore->root = arbore->buildTree(postfix, n);

    cout << "Infix Expression: ";
    arbore->printInfix(arbore->root);
    cout << endl;

    cout << "Prefix Expression: ";
    arbore->printPrefix(arbore->root);
    cout << endl;

    cout << "Postfix Expression: ";
    arbore->printPostfix(arbore->root);
    cout << endl;

    cout << "Result = " << arbore->evaluate(arbore->root) << endl;
}
