#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    else
        printf("Value %d already exists in the tree.\n", value);
    return root;
}

int search(struct Node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (data == root->data) {
        return 1;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data, int *deleted) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data, deleted);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data, deleted);
    } else {
        // Node found
        *deleted = 1;
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, deleted);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, deleted;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display Inorder\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n');
                    break;
                }
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n');
                    break;
                }
                if (search(root, value)) {
                    printf("Value %d found in the Binary Search Tree.\n", value);
                } else {
                    printf("Value %d not found in the Binary Search Tree.\n", value);
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n');
                    break;
                }
                deleted = 0;
                root = deleteNode(root, value, &deleted);
                if (deleted) {
                    printf("Value %d deleted from the Binary Search Tree.\n", value);
                } else {
                    printf("Value %d not found in the Binary Search Tree.\n", value);
                }
                break;
            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                freeTree(root);
                printf("Exiting Program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

