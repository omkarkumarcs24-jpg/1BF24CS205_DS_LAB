#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void create(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertLeft(int target, int newData) {
    struct Node *temp = head;

    if (head == NULL)
        return;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
        return;

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (temp == head) {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
    printf("The value is inserted at the left of %d \n ",target);
}

void insertRight(int target, int newData) {
    struct Node *temp = head;

    if (head == NULL)
        return;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
        return;

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (temp == tail) {
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    printf("The value is inserted at the right of %d \n ",target);
}

void deleteByValue(int value) {
    struct Node *temp = head;

    if (head == NULL)
        return;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
    else if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    printf("The %d value is deleted \n",value);
}

void deleteByPosition(int pos) {
    if (head == NULL)
        return;

    struct Node *temp = head;
    int i;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
    else if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    printf("The value at position %d is deleted \n",pos);
}

void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return; 
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d < > ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, data, target, value, pos;

        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at end (create)\n");
        printf("2. Insert left of a value\n");
        printf("3. Insert right of a value\n");
        printf("4. Delete by value\n");
        printf("5. Delete by position\n");
        printf("6. Display\n");
        printf("7. Exit\n");

    while (1) {

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                create(data);
                break;

            case 2:
                printf("Enter new value: ");
                scanf("%d", &data);
                printf("Insert left of which value? ");
                scanf("%d", &target);
                insertLeft(target, data);
                break;

            case 3:
                printf("Enter new value: ");
                scanf("%d", &data);
                printf("Insert right of which value? ");
                scanf("%d", &target);
                insertRight(target, data);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteByPosition(pos);
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);
        }
    }
    return 0;
}
