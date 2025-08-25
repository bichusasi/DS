#include <stdio.h>

#define SIZE 5  

int queue[SIZE];
int front = 0;
int rear = -1;
int count = 0;

int isFull() {
    return count == SIZE;
}

int isEmpty() {
    return count == 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    count++;
    printf("Enqueued: %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int item = queue[front];
    front = (front + 1) % SIZE;
    count--;
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = front;
    for (int c = 0; c < count; c++) {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value, dequeuedValue;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeuedValue = dequeue();
                if (dequeuedValue != -1) {
                    printf("Dequeued: %d\n", dequeuedValue);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting Program\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
