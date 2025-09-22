#ifndef ARBOREEXPRESII_H
#define ARBOREEXPRESII_H
#include "stiva.h"

struct NodeExpr {
    string value;
    NodeExpr *left;
    NodeExpr *right;
    NodeExpr(string v) : value(v), left(nullptr), right(nullptr) {}
};

struct Expresii {
    NodeExpr *root = nullptr;

    int precedence(char op) {
        if(op == '+' || op == '-') return 1;
        if(op == '*' || op == '/') return 2;

        return -1;
    }

    int infixToPostfix(string expr, string output[]) {
        Stiva<char> *stiva = new Stiva<char>();
        string number = "";
        int ct = 0;

        for (int i = 0; i <(int)expr.size(); i++) {
            char c = expr[i];

            if(isdigit(c)) {
                number += c;
            }else {
                if(number != "") {
                    output[ct++] = number;
                    number = "";
                }

                if(c == ' ') continue;

                if(c == '(') {
                    stiva->push(c);
                }else if(c == ')') {
                    while(!stiva->isEmpty() && stiva->peek()->data != '(') {
                        output[ct++] = string(1, stiva->pop()->data);
                    }
                    stiva->pop();
                }else {
                    while(!stiva->isEmpty() && precedence(stiva->peek()->data) >= precedence(c)) {
                        output[ct++] = string(1, stiva->pop()->data);
                    }
                    stiva->push(c);
                }
            }
        }

        if(number != "") {
            output[ct++] = number;
        }

        while(!stiva->isEmpty()) {
            output[ct++] = string(1, stiva->pop()->data);
        }

        stiva->deleteStack();

        return ct;
    }

    int evaluate(NodeExpr *node) {
        if(!node->left && !node->right) {
            return stoi(node->value);
        }

        int leftVal = evaluate(node->left);
        int rightVal = evaluate(node->right);

        if(node->value == "+") return leftVal + rightVal;
        if(node->value == "-") return leftVal - rightVal;
        if(node->value == "*") return leftVal * rightVal;
        if(node->value == "/") return leftVal / rightVal;

        return 0;
    }

    bool isNumber(string &s) {
        if(s.empty()) return false;

        for(int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if(!isdigit(c)) return false;
        }

        return true;
    }

    NodeExpr *buildTree(string postfix[], int n) {
        Stiva<NodeExpr*> *stiva = new Stiva<NodeExpr*>();

        for(int i = 0; i < n; i++) {
            string token = postfix[i];

            if(token == " " || token.empty()) continue;

            if(isNumber(token)) {
                stiva->push(new NodeExpr(token));
            }else {
                NodeExpr *right = stiva->pop()->data;
                NodeExpr *left = stiva->pop()->data;
                NodeExpr* node = new NodeExpr(token);
                node->left = left;
                node->right = right;
                stiva->push(node);
            }
        }
        return stiva->pop()->data;
    }

    void printInfix(NodeExpr *node) {
        if(!node) return;
        if(node->left != nullptr) cout << "(";

        printInfix(node->left);
        cout << node->value << " ";
        printInfix(node->right);

        if(node->right != nullptr) cout << ")";
    }

    void printPrefix(NodeExpr *node) {
        if(!node) return;

        cout << node->value << " ";
        printPrefix(node->left);
        printPrefix(node->right);
    }

    void printPostfix(NodeExpr *node) {
        if(!node) return;
        printPostfix(node->left);
        printPostfix(node->right);
        cout << node->value << " ";
    }

    void mein() {
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
};
#endif //ARBOREEXPRESII_H
