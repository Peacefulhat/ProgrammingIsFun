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
  if(temp==NULL){
    return;
  }
  free(temp);
}


struct node*search_node(struct node *it,type_t value){
  if(it==NULL){
    return NULL;
  }
  //    while(it->left!=NULL&&it->right!=NULL)// not valid because if we are at  last node and try to search its child and found the left or right null before search it we will never find the value because we will break out of loop.
while(it!=NULL){  
    if(it->value==value){
      return it;
    }
    if(it->value<value){
      it=it->right;
      continue;
    }
    if(it->value>value){
      it=it->left;
    }
  }
  fprintf(stderr,"not able to find node");
  return NULL;
}


struct node* successor(struct node* it){
  if(it==NULL||it->right==NULL){
    return NULL;
  }
   while(it->left!=NULL){
    it=it->left;
  }
   return it;
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








/*void delete(struct node* it,type_t value){
   for node with no child
  struct node*prev=NULL;
    if(it->left==NULL&&it->right==NULL){
    root=NULL;
    mem_free(it);
    return;
    }
  while(it!=NULL){
  if(it->value==value && (it->left==NULL&&it->right==NULL)){
    if( prev->left->value==value)prev->left=NULL;
    if( prev->right->value==value)prev->right=NULL;
    mem_free(it);
    break;
  }

  if(it->value==value&&(it->right!=NULL)){
    if( prev->left->value==value)prev->left=it->right;
    if( prev->right->value==value)prev->right=it->right;
    mem_free(it);
    break;
  }
  else{
    if( prev->left->value==value)prev->left=it->left;
    if( prev->right->value==value)prev->right=it->left;
    mem_free(it);
    break;
  
  }
  
  if(it->value==value &&(it->right!=NULL && it->left!=NULL)){
    struct node*temp = successor(it->right);
    
    if(it->left==NULL){temp->left=NULL;}else{
      temp->left=it->left;
    }
    
    if( prev->left->value==value)prev->left=temp;
    if( prev->right->value==value)prev->right=temp;
    
    if(it->right==temp){
      temp->right=NULL;
     }else{
      temp->right=it->right;
    }
    }
  
  if(it->value>value){
    it=it->left;
  }else{
    it=it->right;
  }
  
  prev=it;
  }
  
}
*/


struct node* delete(struct node* root, type_t value) {
    struct node* parent = NULL;
    struct node* current = root;

    // Step 1: Find the node to delete
    while (current != NULL && current->value != value) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) return root; // Value not found
 
    // Step 2: Handle different cases of deletion
    if (current->left == NULL || current->right == NULL) {
        // Case 1 & 2: Node has at most one child
        struct node* child = (current->left != NULL) ? current->left : current->right;

        if (parent == NULL) {
            free(current);
            return child;  // Update root if deleting root
        }

        if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }

        free(current);
    } else {
        // Case 3: Node has two children (find inorder successor)
        struct node* successor_parent = current;
        struct node* successor = current->right;

        while (successor->left != NULL) {
            successor_parent = successor;
            successor = successor->left;
        }

        // Replace current node with successor
        current->value = successor->value;

        // Delete successor node
        if (successor_parent->left == successor) {
            successor_parent->left = successor->right;
        } else {
            successor_parent->right = successor->right;
        }

        free(successor);
    }

    return root;
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
  postorder(it->left);
  postorder(it->right);
  printf("%d->",it->value);
 }

void m_postorder(struct node* it){
  if(it==NULL){
    return;
  }
  m_postorder(it->left);
  m_postorder(it->right);
  printf("{%d:%p}\n",it->value,it);
 }
