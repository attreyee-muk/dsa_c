#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *left,*right;
};
int TotalNodes(struct node *root)
{
 if(root!=NULL)
 {
  return TotalNodes(root->left)+TotalNodes(root->right)+1;
 }
}
struct node *create(struct node *root)
{
 struct node *newnode=(struct node *)malloc(sizeof(struct node));
 int x;
 printf("\nEnter the value(-1 for no node): ");
 scanf("%d",&x);
 if(x==-1)
 {
  return 0;
 }
 else
 {
  newnode->data=x;
  printf("\nEnter the left child of %d :",x);
  newnode->left=create(root);
  printf("\nEnter the right child of %d :",x);
  newnode->right=create(root);
 }
 return root;
}
void inorder(struct node *root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
 }
}
void preorder(struct node *root)
{
 if(root!=NULL)
 {
  printf("%d\t",root->data);
  preorder(root->left);
  preorder(root->right);
 }
}
void postorder(struct node *root)
{
 if(root!=NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf("%d\t",root->data);
 }
}
int main()
{
 int choice,value;
 struct node *root;
 struct node *newnode=(struct node *)malloc(sizeof(struct node));
 root=create(root);
 printf("**MAIN MENU**");
 printf("\n1.No. of Nodes\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit");
 do
 {
  printf("\nEnter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:value=TotalNodes(root);
          printf("\nThe no. of nodes are : %d",value);
          break;
   case 2:inorder(root);
          break;
   case 3:preorder(root);
          break;
   case 4:postorder(root);
          break;
   case 5: printf("Exit");
          break;
   default : printf("Invalid choice");
             break;
  }
 }while(choice!=5);
 return 0;
}