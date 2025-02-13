#include"include/bst.h"
struct node*root=NULL;
int main(){
 insert(23);
 insert(30);
 insert(20);
 insert(19);
 insert(21);
 insert(17);
 insert(35);
 insert(37);
 insert(28);
 // printf("Iorder:");
 // inorder(root);
 // printf("\n");
 // printf("Preorder:");
 // preorder(root);
 //printf("\n");
 // printf("Postorder:");
 // postorder(root);
 //  printf("\n");
 // printf("%d",successor(root->right));
 // printf("\n");
 inorder(root);
 printf("Node search:");
 delete(root, 37);
 inorder(root);


  return 0;
}
