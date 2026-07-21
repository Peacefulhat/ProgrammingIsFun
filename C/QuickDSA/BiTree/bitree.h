// Binary tree

#ifndef BI_TREE_H
#define BI_TREE_H
#include "../dstype.h"
#include "../sv.h"

typedef struct bt bt;

struct bt{
    string_view Sv;
    bt* Left;
    bt* Right;
};

#define ALLOC(Type, Size) (Type*)malloc(sizeof(Type) * (Size))
void PrintNode(bt* Node);
bt* CreateNode(string_view Data);

#endif

#ifdef BI_TREE_IMPLEMENTATION

void PrintNode(bt* Node)
{
  printf("Node::\n{\n");
  printf(" Sv::\n");
  printf("  {\n   Data: ");
  PRINT_SV(Node->Sv);
  printf("   Count: %d\n  }\n", Node->Sv.Count);
  printf(" LeftNode: %p\n", Node->Left);
  printf(" RightNode: %p \n}\n", Node->Right);
}

static bt* CreateEmptyNode()
{
  bt* Node =  ALLOC(bt, 1);
  Node->Left = NULL;
  Node->Right = NULL;
  Node->Sv = CstrAsSv("empty");
  return (Node);

}
bt* CreateNode(string_view Data)
{
  bt* Node =  ALLOC(bt, 1);
  Node->Left = NULL;
  Node->Right = NULL;
  Node->Sv = Data;
  return (Node);
}


#endif

