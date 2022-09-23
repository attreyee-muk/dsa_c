#include <stdio.h>
static int max=100;
static int top=-1;
static int element;
static int arr[100];
static int size;
void push(){
    printf("enter the element you want to insert:");
    scanf("%d",&element);
    if(top==size-1){
        printf("OVERFLOW");
    }
    else{
        top+=1;
        arr[top]=element;
    }

}
void pop(){
    if(top==-1){
        printf("UNDERFLOW");
    }
    else{
        printf("The element popped is: %d",arr[top]);
        top--;
    }

}
void peek(){
    if(top==-1){
        printf("UNDERFLOW");
    }
    else{
        printf("The element on the top is: %d",arr[top]);
    }

}
void display(){

    for(int i=top;i>=0;i--){
        printf("%d\n",arr[i]);
    }

}

int main(){
    
    printf("enter the size of the array stack");
    scanf("%d",&size);

    int choice;

    do{
       printf("Enter your choice:\n1. push\n 2.pop\n 3. peek \n 4. display\n 5. exit\n");
       scanf("%d",&choice); 
       switch(choice){
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        peek();
        break;
        case 4:
        display();
        break;
        case 5:
        printf("exiting...");
        break;
        default:
        printf("invalid choice");
       }
    }
    while(choice!=5);
}
