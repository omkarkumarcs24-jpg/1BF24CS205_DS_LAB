#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};



struct Node *head = NULL;


void createList(int n ){
    struct Node *newNode , *temp;
    int data , i;
    if (n<=0){
        printf("Number of nodes should be greater than 0. \n");
        return;
    }
    for(i = 1 ; i<=n ; i++){
        newNode=(struct node*)malloc (sizeof(struct Node));
        if(newNode==NULL){
            printf("memory allocation failed\n");
            return;
        }

        printf("Enter data for node %d: ",i);
        scanf("%d",&data);

        newNode->data=data;
        newNode->next=NULL;
        if(head == NULL){
            head = newNode;
        }
        else{
            temp->next= newNode;
        }
        temp=newNode;
    }
    printf("linked list created successfully.\n");

}



void insertatbeginning(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    if(newNode ==NULL){
        printf("memory allocation failed.\n");
        return;
    }
    newNode ->data=data;
    newNode->next=head;
    head = newNode;
    printf("node inserted at the beginning.\n");
}



void insertatend(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;

    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return ;
    }
    newNode->data= data;
    newNode->next=NULL;

    if(head == NULL){
        head = newNode;
        printf("Node insertd at the end");
        return;
    }
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next= newNode;
    printf("Node inserted at the end.\n");
}

void insertatposition(int data , int pos){
    int i;
    struct Node *newNode , *temp = head;

    if(pos<1){
        printf("invalid position .\n");
        return;
    }

    if(pos==1){
        insertatbeginning(data);
        return;
    }
    newNode =(struct node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data= data;

    for (i = 1 ; i<pos-1 && temp!=NULL; i++){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("position is out of range.\n");
        free(newNode);
        return;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    printf("Node inserted at position %d. \n",pos);


}


void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, n, data, pos;
    printf("\n--- Singly Linked List Operations ---\n");
    printf("1. Create Linked List 2.Insert at Beginning  3.At any pos. 4.At End 5.Display 6.Exit\n");

    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertatbeginning(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertatposition(data, pos);
                break;

            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertatend(data);
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! \n");
        }
    }
    return 0;
}
