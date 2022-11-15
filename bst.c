#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data){
   struct node *root=(struct node *)malloc(sizeof(struct node));
   root->data=data;
   root->left=root->right=NULL;
   return root;
} 

struct node *insert(struct node *root,int data){
    if(root==NULL){
        return create(data);
    }
    else if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
    
}
    
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d",root->data);
        inorder(root->left);
        
        inorder(root->right);
    }
   
}
void postorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        inorder(root->right);
        printf("%d",root->data);
        
    }
    
}

int smallest(struct node *root){
    struct node *temp=root;
    while(temp && temp->left!=NULL){
       temp=temp->left; 
    }
    return temp->data;
}

struct node * delete(struct node *ptr, int x){
    struct node *p1,*p2;
    if(!ptr) {
		printf("\n Node not found ");
		return(ptr);
	} else {
		if(ptr->data < x) {
			ptr->right = delete(ptr->right,x);
			/*return(ptr);*/
		} else if (ptr->data >x) {
			ptr->left=delete(ptr->left,x);
			return ptr;
		} else{
			
				if(ptr->left==NULL && ptr->right==NULL) 
				/*i.e., a leaf node*/ {
					free(ptr);
					return(NULL);
				} else if(ptr->left==NULL){
					p1=ptr->right;
					free(ptr);
					return p1;
				} else if(ptr->right==NULL)   
				/* a left subtree */ {
					p1=ptr->left;
					free(ptr);
					return p1;
				} else {
                        int rightmin=smallest(ptr->right);
						ptr->data=rightmin;
                    	ptr->right=delete(ptr->right,rightmin);
                    }

			}
		}
    return ptr;
}

struct node *search(struct node *root){
    int data;
    struct node *temp=root;
    while(temp){
       if(temp->data<data){
           temp=temp->right;
           
       } 
       else if (temp->data>data){
           temp=temp->left;
           
       }
       else{
           break;
       }
    }
    return root;
    
}

int main(){
    struct node *root;
	int choice, item,item_no;
	root = NULL;
	
	/* rear  = NULL;*/
	do {
		printf("\n \t 1. Insert in Binary Tree  ");
		printf("\n\t 2. Delete from Binary Tree ");
		printf("\n\t 3. Inorder traversal of Binary tree");
		printf("\n\t 4. Postorder traversal of Binary tree");
		printf("\n\t 5. Preorder traversal of Binary tree");
		printf("\n\t 6. Search and replace ");
		printf("\n\t 7. Exit ");
		printf("\n\t Enter choice : ");
		scanf(" %d",&choice);
		switch(choice) {
			case 1:
				   printf("\n Enter new element: ");
			scanf("%d", &item);
			root = insert(root,item);
			printf("\n root is %d", root->data);
			printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			case 2:
				  printf("\n Enter the element to be deleted : ");
			scanf(" %d",&item_no);
			root=delete(root,item_no);
			inorder(root);
			break;
			case 3:
				  printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			case 4:
				  printf("\n Postorder traversal of binary tree is : ");
			postorder(root);
			break;
			case 5:
				  printf("\n Preorder traversal of binary tree is : ");
			preorder(root);
			break;
			case 6:
				  printf("\n Search and replace operation in binary tree ");
			root=search(root);
			break;
                     case 7:
                     printf("\nexiting");
                     break;
			default:
                     printf("\n Invalid choice - try again");
		}
		/* end of switch */
	}
	while(choice !=7);
	return(0);
}

