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

struct node *memory_alloc(type_t);
void mem_free(struct node*);
void insert(type_t value);
struct node*delete(struct node*,type_t value);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node *successor(struct node*);
struct node*search_node(struct node*,type_t);
void m_postorder(struct node* it);
#endif
