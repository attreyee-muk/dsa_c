#include <stdio.h>
#include <stdlib.h>
// Linked List Node
struct node {
	int coeff;
    int power;
	struct node* next;
};

static struct node *head = 0;
static struct node *newnode = NULL;
static struct node *temp=NULL , *prevnode= NULL;
static struct node * head1=0;
static struct node * head2=0;

void display(struct node * head)
{
	struct node* temp;

	// List is empty
	if (head == NULL)
		printf("\nList is empty\n");

	// Else print the LL
	else {
		temp = head;
        printf("The polynomial is : ");
		while (temp != NULL) {
			printf("%d x ^ %d + ",temp->coeff,temp->power);
			temp = temp->next;
		}
        
	}
}
void createList(int n, struct node * head)
{
    newnode=(struct node *)malloc(sizeof(struct node ));
    struct node *temp;
    printf("enter coefficient for first term:");
    scanf("%d",newnode->coeff);
    printf("enter power for first term:");
    scanf("%d",newnode->power);
    temp=newnode;
    temp->next=0;
	if(head==0){
        head=temp;
    }
    else{
        for(i=2;i<=n;i++){
            newnode=(struct node *)malloc(sizeof(struct node ));
        }

    }
}

void addition(struct node *head1,struct node *head2)
    {
    struct node * temp1=head1;
    struct node * temp2=head2;
    int coeff_final=temp1->coeff;
    int power_final=temp1->power;
    while(temp1!=0){
        if(temp1->power==temp2->power){
            coeff_final=temp1->coeff+temp2->coeff;
            power_final=temp1->power+temp2->power;
            printf("%d %d",coeff_final,power_final);
        }
        else{
            if(temp2->next!=0){
                temp2=temp2->next;
            }
        }
        printf("%d %d",coeff_final,power_final);
        printf("+");
        temp1=temp1->next;
    }

}
int main()
{
    struct node * head1=(struct node *)malloc(sizeof(struct node));
    struct node * head2=(struct node *)malloc(sizeof(struct node));
    int n1;
	printf("\nEnter the number of terms in polynomial 1: ");
	scanf("%d", &n1);
	createList(n1,head1);
    printf("%d",temp->coeff);
    int n2;
	printf("\nEnter the number of terms in polynomial 2: ");
	scanf("%d", &n2);
	createList(n2,head2);
    addition(head1,head2);


    return 0;
}


