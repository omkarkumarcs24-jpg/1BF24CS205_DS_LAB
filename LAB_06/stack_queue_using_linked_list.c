#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node *top = NULL;


struct Node *front = NULL, *rear = NULL;

struct Node* createNode(int data) {
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void push(int data){
    struct Node *new =createNode(data);
    new->next=top;
    top =new;
}

void pop(){
    if(top==NULL){
        printf("stack is empty");
        return;
    }
    struct Node *temp=top;
    top=top->next;
    free(temp);
}
void enqueue(int data){
    struct Node *new =createNode(data);
    if(front==NULL)
    front=rear=new;
    else{
        rear->next=new;
        rear=new;
    }
}

void dequeue(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp=front;
    front = front->next;
    free(temp);
}

void displayStack() {
    struct Node *temp = top;
    if (temp == NULL) {
        printf("Stack empty\n");
        return;
    }
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void displayQueue() {
    struct Node *temp = front;
    if (temp == NULL) {
        printf("Queue empty\n");
        return;
    }
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, value;
        printf("\n===== MENU =====\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

    while (1) {

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}