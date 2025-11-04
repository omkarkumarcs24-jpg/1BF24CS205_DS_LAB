#include <stdio.h>
#define SIZE 5 

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    
    if ((front == 0 && rear == SIZE - 1) || (front == (rear + 1) % SIZE)) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {  
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = x;
        printf("%d is inserted into queue\n", x);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("%d is deleted from queue\n", queue[front]);

        if (front == rear) {  
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        printf("Queue elements are: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu -- 1.Enqueue , 2.Dequeue , 3.Display , 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
