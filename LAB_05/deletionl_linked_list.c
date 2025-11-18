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

void deletefirst(){
    struct Node *temp;

    if(head==NULL){
        printf("List is Empty.Nothing to be deleted");
        return;
    }

    temp=head;
    head=head->next;
    printf("deleted first element is %d\n",temp->data);
    free(temp);

}

void deletelast(){

    struct Node *temp;
    struct Node *prev;
    if(head==NULL){
        printf("List is Empty.Nothing to be deleted");
        return;
    }
    if(head->next==NULL){
        printf("deleted element is %d\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;

    }
    printf("deleted last element is %d\n",temp->data);
    prev->next=NULL;
    free(temp);

}

void deletespecific(int value){

    struct Node *temp=head;
    struct Node *prev=NULL;

    if(head==NULL){
        printf("List is empty.nothing to be deleted");
        return;
    }
    if(head->data==value){
        printf("deleted element is %d\n",temp->data);
        head=head->next;
        free(temp);
        return;                                                      
    }

    while(temp!=NULL && temp->data!= value){

        prev=temp;
        temp=temp->next;

        if(temp==NULL){
            printf("element %d is not found in list",value);
            return;
        }
        prev->next=temp->next;
        printf("deleted element is %d \n", temp->data);
        free(temp);
    }


}

void displayList(){
    struct Node *temp=head;

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    printf("\n linked list:  ");
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
}

int main(){

    int choice , n , value;

    printf("singly linkedlist operation\n");
    printf(" 1.create linked list\n 2.Delete at beginning \n 3.Delete at End \n 4.Delete by Value \n 5.Display \n 6.Exit\n");
    while(1){
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter number of nodes: ");
                scanf("%d",&n);
                createList(n);
                break;

            case 2:
                deletefirst();
                break;

            case 3:
                deletelast();
                break;
            case 4:
                printf("enter value to be deleted: ");
                scanf("%d",&value);
                deletespecific(value);
                break;

            case 5:
                displayList();
                break;
            
            case 6:
                printf("Exiting program:\n");
                exit(0);

            default :
                printf("Invalid choice!\n");

                
        }
        
    }
    return 0;
}
