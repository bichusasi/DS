#include <stdio.h>
#define max 100

char stack[max];
int top = -1;

void push(char c){
     if (top < max - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9');
}


void infixToPostfix(char infix[]) {
    char postfix[max];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix[j++] = ch; 
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
        else if (isOperator(ch)) {
            while (precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 

    printf("Postfix expression: %s\n", postfix);
}


int main() {
    char infix[max];

    printf("Enter infix expression : ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
