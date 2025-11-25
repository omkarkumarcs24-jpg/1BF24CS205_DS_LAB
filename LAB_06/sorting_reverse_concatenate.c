#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printf("List reversed successfully.\n");
    return prev;
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {

    struct Node *head1 = NULL, *head2 = NULL;
    int choice, value;

        printf("\n----MENU---\n");
        printf(" 1. Insert into List 1 \n 2. Insert into List 2 \n 3. Display List 1\n 4. Display List 2\n 5. Sort List 1\n 6. Reverse List 1\n 7. Concatenate List 2 to List 1\n 8. Exit\n");


    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to List 1: ");
                scanf("%d", &value);
                head1 = insertEnd(head1, value);
                break;

            case 2:
                printf("Enter value to  List 2: ");
                scanf("%d", &value);
                head2 = insertEnd(head2, value);
                break;

            case 3:
                printf("List 1: ");
                display(head1);
                break;

            case 4:
                printf("List 2: ");
                display(head2);
                break;

            case 5:
                sortList(head1);
                break;

            case 6:
                head1 = reverseList(head1);
                break;

            case 7:
                head1 = concatenate(head1, head2);
                printf("Lists concatenated successfully!\n");
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
