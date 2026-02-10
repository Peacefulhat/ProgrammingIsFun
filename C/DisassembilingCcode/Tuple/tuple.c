#include <stdio.h>
#include <stdlib.h>
typedef float real32;

// Tuple (using Linked list) for testing asm code generation.
// not full implemenation but some rough idea.

typedef struct
{
  real32 x, y;
}Point;

typedef enum 
  {
    CHAR,
    INT,
    FLOAT,
    POINT
}Type;

typedef struct Node Node;

struct Node {
  Type TypeOfData;
  void* Data;
  Node* Next;
};

int GetSizeFromType(Type TypeOfData)
{
  int Size;
  switch(TypeOfData)
    {
    case CHAR:
      {
        Size = sizeof(char);
      }
      break;
    case INT:
      {
        Size =  sizeof(int);
      }
      break;
    case FLOAT:
      {
        Size = sizeof(float);
      }
      break;
            
    case POINT:
      {
        Size = sizeof(Point);
      }
      break;
    default :
      {
        Size = sizeof(char);
      }
            
    }
  return Size;
}

// Creats a node
Node* CreateNode(Type TypeOfData, void *Data)
{
  Node* NewNode = (Node*)malloc(sizeof(Node));
  NewNode->TypeOfData = TypeOfData;
  NewNode->Data = Data;
  NewNode->Next = NULL;
  return NewNode;
}

Node* Head = NULL;
Node* Tail = NULL;

void Append(Node* LNode)
{
  if(Head == NULL)
    {
      Head = LNode;
      Tail = LNode;
      return;
    }
  Tail->Next = LNode;
  Tail = LNode;
}

void PrintNode(Node* Head)
{
  Node* Temp = Head;
  while(Temp!=NULL)
    {
      switch(Temp->TypeOfData)
        {
        case CHAR:
          {
            printf("%c-> ",*((char*)Temp->Data));
          }
          break;
        case INT:
          {
            printf("%d-> ",*((int*)Temp->Data));
          }
          break;
        case FLOAT:
          {
            printf("%f-> ",*((float*)Temp->Data));
          }
          break;
        case POINT:
          {
            Point* P = (Point*)Temp->Data;
            printf("{%f, %f}-> ",P->x, P->y);
          }
          break;

        }
      Temp = Temp->Next;
    }
  printf("%p", Temp);
}


int main(void)
{
  int Value = 23;
  char Value2 = 'A';
  float Oint = 23.4f;
  Point Player = {.x = 54, .y = 60};
   
  Node* MyNode = CreateNode(INT, &Value);
  Append(MyNode);
  MyNode = CreateNode(CHAR, &Value2);
  Append(MyNode);
  MyNode = CreateNode(POINT, &Player);
  Append(MyNode);
  MyNode = CreateNode(FLOAT, &Oint);
  Append(MyNode);
  printf("Tuple Like Linked List\n");
  printf("Head: %p\n", Head);
  printf("Tail: %p\n", Tail);
  PrintNode(Head);
  return 0;
}

