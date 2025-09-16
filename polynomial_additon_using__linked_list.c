#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void inputPolynomial(struct Node** p) {
    int n, coeff, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter coefficients and exponents:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(p, coeff, exp);
    }
}

void printPolynomial(struct Node* p) {
    struct Node* temp = p;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    struct Node **ptr = &result;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
                insertTerm(ptr, sumCoeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insertTerm(ptr, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insertTerm(ptr, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        while (*ptr != NULL)
            ptr = &((*ptr)->next);
    }

    while (p1 != NULL) {
        insertTerm(ptr, p1->coeff, p1->exp);
        p1 = p1->next;
        while (*ptr != NULL)
            ptr = &((*ptr)->next);
    }

    while (p2 != NULL) {
        insertTerm(ptr, p2->coeff, p2->exp);
        p2 = p2->next;
        while (*ptr != NULL)
            ptr = &((*ptr)->next);
    }

    return result;
}

int main() {
    struct Node* p1 = NULL;
    struct Node* p2 = NULL;

    printf("Polynomial 1:\n");
    inputPolynomial(&p1);

    printf("Polynomial 2:\n");
    inputPolynomial(&p2);

    printf("Polynomial 1: ");
    printPolynomial(p1);

    printf("Polynomial 2: ");
    printPolynomial(p2);

    struct Node* result = addPolynomials(p1, p2);

    printf("Resultant polynomial after addition: ");
    printPolynomial(result);

    return 0;
}