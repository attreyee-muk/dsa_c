#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
static struct Node *head= NULL;
static struct Node *newnode= NULL;
static int n=5;

int main(){

    while(n!=0){
        newnode=(struct Node *)malloc(sizeof(struct Node));
        printf("enter data:");
        scanf("%d",&newnode->data);
    }
    return 0;

}