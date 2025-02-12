#include"../include/bst.h"

extern struct node*root;

struct node*get_root(){ return root;}

struct node *memory_alloc(type_t value){
  struct node *alloc_chunk=NULL;
  alloc_chunk=(struct node*)malloc(sizeof(struct node));
  
  if(alloc_chunk==NULL){
    printf("faild to allocated memory_alloc");
    return NULL;
  }
  alloc_chunk->value=value;
  alloc_chunk->left=NULL;
  alloc_chunk->right=NULL;
  return alloc_chunk;
}


void mem_free(struct node* temp){
  free(temp);
}

void insert(type_t value){
  struct node *alloc_node=memory_alloc(value);
  if(root==NULL){
    root=alloc_node;
    return;
  }
  struct node*temp=root;
  
  while(1){
    if (temp->value > value && temp->left == NULL) {
      temp->left = alloc_node;
      return;  
    }

    if (temp->value < value && temp->right == NULL) {
      temp->right = alloc_node;
      return;  
    }

    if (temp->value > value) {
      temp = temp->left;
      continue;
    }
    if (temp->value < value) {
      temp = temp->right;
    }
  }
}

void inorder(struct node* it){
  if(it==NULL){
    return;
  }
  inorder(it->left);
  printf("%d->",it->value);
  inorder(it->right);
 }

void preorder(struct node* it){
  if(it==NULL){
    return;
  }
  printf("%d->",it->value);
  inorder(it->left);
  inorder(it->right);
 }


void postorder(struct node* it){
  if(it==NULL){
    return;
  }
  inorder(it->left);
  inorder(it->right);
  printf("%d->",it->value);
 }
