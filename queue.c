# include <stdio.h>

int queue [50];
int front = -1,rear = -1;
int size = 0;

void enque(int value){
    if (rear == size-1){
        printf("Queue Over Flow\n");
    }
    else{
         {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("%d enqueued\n", value);
    }
    }
}

void dequeue(){
    if (front == -1 ||front>rear){
        printf("Queue Under Flow\n");
    }
    else{
        printf("%d,dequeued\n",queue[front++]);
        if(front > rear) front = rear = -1;
    }
}

void display(){
    if (front == -1 || front > rear){
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
         {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
int op,choice,value;
int i;

printf("Enter the size of Queue :");
scanf("%d", &size);
if (size <= 0 || size > 50){
    printf("Invalid size!\n");
}
printf("\nQueue Operations:\n");
printf("1. Enqueue\n2. Dequeue\n3. Display\n");
printf("How many operations do you want to perform? ");
scanf("%d", &op);

for ( i = 0; i < op; i++)
{
    printf("Enter your choice (1. Enqueue , 2. Dequeue , 3.Display) :");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Enter the value of enqueue ;");
        scanf("%d", &value);
        enque(value);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    default:
        printf("Invalid Choice :");
        break;
    }
}
return 0;
}

