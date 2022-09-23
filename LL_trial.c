#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
static struct Node * head= NULL;
static struct Node * newnode= NULL;
static struct Node * temp= NULL;
static int n=5;
int main(){
    
    while(n!=0){
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=temp->next;
        }
        n--;
    }
    temp=head;

    while(temp!=0){
        printf("%d",temp->data);
        temp=temp->next;
        free(temp);
    }
    return 0;
}