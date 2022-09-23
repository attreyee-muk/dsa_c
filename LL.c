#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    int n = 5;
    struct Node *head = NULL;
    struct Node *newnode = NULL;
    struct Node *temp = NULL;
    head = 0;
    while (n)
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
        n--;
    }

    temp = head;
    while (temp != 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    return 0;
}
