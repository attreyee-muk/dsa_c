struct Node *delete (struct Node *root, int key){
//     if(root==NULL){
//         return root;
//     }
//     if(key<root->key){
//         root->left=delete(root->left,key);
//     }
//     else if(key>root->key){
//         root->right=delete(root->right,key);
//     }
//     else{
//         if(root->left==NULL && root->right==NULL){
//             free(root);
//             return NULL;
//         }
//         else if(root->left==NULL){
//             struct Node *temp=root->right;
//             free(root);
//             return temp;
//         }
//         else if(root->right==NULL){
//             struct Node *temp=root->left;
//             free(root);
//             return temp;
//         }
//         else{
//             int rightmin=smallest(root->right);
//             root->key=rightmin;
//             root->right=delete(root->right,rightmin);
            
//         }
        
//     }
//     return root;
// }