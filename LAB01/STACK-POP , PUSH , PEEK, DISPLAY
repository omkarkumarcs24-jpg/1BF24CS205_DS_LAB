#include<stdio.h>
#include<conio.h>
#define SIZE 5
void push();
void pop();
void display();
void peek();
int stack[SIZE], top =-1;
void main(){
    int value , choice;
    while(1){
        printf("\n\n *** MENU *** \n");
        printf("1Push 2.pop 3.Display 4.Exit\n");
        printf("Enter your choice:  \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong selection! Try again!!");



                }
            }}
  void push(int value)
            {
                if(top == SIZE-1)
                    printf("\n Stack is full , Insertion not possible: stack OVERFLOW ");

                    else{
                    top++;
                    stack[top]= value;
                    printf("\n Insertion succesful");

                }
            }
            void pop(){
                if (top==-1)
                    printf("\n stack is empty\n");

                else{
                    printf("Deleted: %d", stack[top]);
                    top--;

                }

            }
            void display(){
                if(top==-1)
                printf("stack is empty\n");
                else {
                    int i ;
                    printf("\n stack elements are : \n");
                    for(int i = top ; i>=0 ; i--){
                        printf("%d \n ", stack[i]);
                    }
                }
            }
            void peek(){
                if(top==-1)
                printf("stack is empty\n");
                else{
                    printf("%d", stack[top]);
    }}
