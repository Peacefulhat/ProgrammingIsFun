#include"include/bst.h"
struct node*root=NULL;
int main(){
 insert(23);
 insert(30);
 insert(20);
 insert(19);
 insert(21);
 insert(17);
 printf("Iorder:");
 inorder(root);
 printf("\n");
 printf("Preorder:");
 preorder(root);
 printf("\n");
 printf("Postorder:");
 postorder(root);
 
  return 0;
}
