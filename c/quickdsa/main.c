#define BI_TREE_IMPLEMENTATION
#include "BiTree/bitree.h"

int main()
{
    bt* Root = CreateNode(CstrAsSv("23.42"));
    PrintNode(Root);
    return (0);
}
