#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* nodeStack[MAX];
int nodeTop = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    else return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    else return stack[top];
}

void pushNode(Node *node) {
    nodeStack[++nodeTop] = node;
}

Node* popNode() {
    if (nodeTop == -1) return NULL;
    else return nodeStack[nodeTop--];
}

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

int isOperator(char c) {
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    top = -1; 
    while ((c = infix[i]) != '\0') {
        if (isalpha(c) || isdigit(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (peek() == '(') {
                pop();
            }
        } else if (isOperator(c)) {
            while (top != -1 && isOperator(peek()) && 
                   ((precedence(peek()) > precedence(c)) || 
                    (precedence(peek()) == precedence(c) && c != '^'))) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

Node* newNode(char data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* constructExpressionTree(char postfix[]) {
    int i = 0;
    char c;
    nodeTop = -1; 
    while ((c = postfix[i]) != '\0') {
        if (isalpha(c) || isdigit(c)) {
            pushNode(newNode(c));
        } else if (isOperator(c)) {
            Node *right = popNode();
            Node *left = popNode();
            Node *opNode = newNode(c);
            opNode->left = left;
            opNode->right = right;
            pushNode(opNode);
        }
        i++;
    }
    return popNode();
}

void printPrefix(Node *root) {
    if (root == NULL) return;
    printf("%c", root->data);
    printPrefix(root->left);
    printPrefix(root->right);
}

void printPostfix(Node *root) {
    if (root == NULL) return;
    printPostfix(root->left);
    printPostfix(root->right);
    printf("%c", root->data);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    Node *exprTree = constructExpressionTree(postfix);

    printf("Prefix expression: ");
    printPrefix(exprTree);
    printf("\n");

    printf("Postfix expression (from tree): ");
    printPostfix(exprTree);
    printf("\n");

    return 0;
}
