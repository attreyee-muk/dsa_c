#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int pos;
int i;
int n;
static struct Node *head = NULL;
static struct Node *newnode = NULL;
static struct Node *temp= NULL , *prevnode= NULL;
void insert_beg();
void insert_last();
void insert_middle();
void delete_first();
void delete_last();
void delete_middle();
void displayfull();
void display();
void create();

int main()
{
    
    int choice;
    do{
        printf("which one do you want to perform: \n 1.CREATE\n 2. INSERT AT ANY POSITION \n 3.DELETE FROM THE BEGINNING\n 4.DELETE FROM THE END\n 5.DELETE FROM THE MIDDLE\n 6.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            create();
            displayfull();
            break;
            case 2:
            insert_beg();
            display();
            break;
            case 3:
            insert_last();
            display();
            break;
            case 4:
            insert_middle();
            display();
            break;
            case 5:
            delete_first();
            display();
            break;
            case 6:
            delete_last();
            display();
            break;
            case 7:
            delete_middle();
            display();
            break;
            case 8:
            break;
            default:
            printf("invalid choice");
        }

    }
    while(choice!=6);
    return 0;   
}


void insert_beg(){
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number that you want to enter");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head=newnode;
    temp=head;
}
void insert_last(){
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number that you want:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;

}
void insert_middle(){
    printf("enter the index after which you want to insert an element");
    scanf("%d",&pos);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->next=0;
    if(pos>n){
        printf("invalid");
    }
    else{
        temp=head;  
        while(i<pos){
            temp=temp->next;
            i++;
        }
    }
    printf("enter data");
    scanf("%d",&newnode->data);
    if(i==1){
        insert_beg();
        }
    else if(i==n){
        insert_last();
    }
    else{
        newnode->next=temp->next;
        temp->next=newnode;
    }
        
    
}

void delete_first(){
    temp=head;
    head=temp->next;
    free(temp);

}
void delete_last(){
    temp=head;
    prevnode=0;
    while (temp->next!=0){
        if(temp==head){
            prevnode=head;
        }
        else{
            prevnode=prevnode->next;
        }
        temp=temp->next;
        if(temp->next==0){
            prevnode->next=0;
            free(temp);
        }
    }

}
void delete_middle(){
    printf("enter the index whose element you want to delete:");
    scanf("%d",&pos);
    i=1;
    if(pos==1){
        delete_first();
    }
    else if(pos==n){
        delete_last();
    }
    else{
        prevnode=0;
    temp=head;
    while (temp->next!=0){
    if(temp==head){
            prevnode=head;
        }
    else{
            prevnode=prevnode->next;
        }
    temp=temp->next;
    i++;
    if(i==pos){
        prevnode->next=temp->next;
        free(temp);
        break;
    }
    }
    }
//3.INSERT AT THE END \n 4.INSERT AT A GIVEN POSITION 

}
void displayfull(){
    temp=head;
    printf("the elements are:");
    while (temp!= 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}  

void display(){
    temp=head;
    printf("the elements are:");
    while (temp!= 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next; 
        free(temp);    
    }
    free(temp);
    
}

void create(){
    head = 0;
    printf("How many elements do you want? ");
    scanf("%d",&n);
    int m=n;
    while (m)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("enter data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        m--;
    }

}

