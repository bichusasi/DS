#include <stdio.h>

int deque[100]; 
int front = -1, rear = -1;
int size = 0; 

void insertFront(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[front] = value;
        printf("%d inserted at front\n", value);
    } else if (front == 0) {
        front = size - 1;
        deque[front] = value;
        printf("%d inserted at front\n", value);
    } else {
        deque[--front] = value;
        printf("%d inserted at front\n", value);
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[rear] = value;
        printf("%d inserted at rear\n", value);
    } else if (rear == size - 1) {
        rear = 0;
        deque[rear] = value;
        printf("%d inserted at rear\n", value);
    } else {
        deque[++rear] = value;
        printf("%d inserted at rear\n", value);
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("%d deleted from front\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("%d deleted from rear\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        int i = front;
        printf("Deque: ");
        if (front <= rear) {
            while (i <= rear) {
                printf("%d ", deque[i]);
                i++;
            }
        } else {
            while (i < size) {
                printf("%d ", deque[i]);
                i++;
            }
            i = 0;
            while (i <= rear) {
                printf("%d ", deque[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    int operations, choice, value;
    printf("Enter the size of the deque (max 100): ");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid size.\n");
        return 1;
    }
    printf("\nDeque Operations:\n");
    printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n");
    printf("How many operations do you want to perform? ");
    scanf("%d", &operations);
    for (int i = 0; i < operations; i++) {
        printf("\nEnter your choice (1-Insert Front, 2-Insert Rear, 3-Delete Front, 4-Delete Rear, 5-Display): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}