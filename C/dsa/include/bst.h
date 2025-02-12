#ifndef BST_H
#define BST_H

#include<stdio.h>
#include<stdlib.h>
#define type_t int
struct node*get_root();
// node structe of binary tree;
 struct node{
   struct node *left;
   type_t value;
   struct node *right;
 };

// allocate memory for node;
struct node *memory_alloc(type_t value);
void mem_free(struct node* temp);
void insert(type_t value);
void delete(type_t value);
void inorder(struct node*it);
void preorder(struct node*it);
void postorder(struct node*it);
#endif
