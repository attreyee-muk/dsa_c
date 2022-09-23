#include <stdio.h>
static int max=100;
static int front=-1;
static int rear=-1;
static int element;
static int arr[100];
static int size;
void insert(){
    printf("enter the element you want to insert:");
    scanf("%d",&element);
    if(rear==size-1){
        printf("UNDERFLOW\n");
    }
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }
    else{
        rear+=1;
    }
    arr[rear]=element;

}
void delete(){
    if(front==-1 || front>rear){
        printf("UNDERFLOW\n");
    }
    else{
        printf("The element deleted is:%d",arr[front]);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front+=1;
        }
    }

}
void display(){
    if(front==-1 || front>rear){
        printf("Nothing\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\n",arr[i]);
        }
    }

}
void peep(){
    if(front==-1 || front>rear){
        printf("UNDERFLOW\n");
    }
    else{
        printf("The element deleted is:%d",arr[front]);
        
    }

}
int main(){
    printf("enter the size of the array queue:");
    scanf("%d",&size);

    int choice;

    do{
       printf("Enter your choice:\n1. insert\n 2.delete\n 3. peep \n 4. display\n 5. exit\n");
       scanf("%d",&choice); 
       switch(choice){
        case 1:
        insert();
        break;
        case 2:
        delete();
        break;
        case 3:
        peep();
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