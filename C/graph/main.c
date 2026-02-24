#define GRAPH_IMPLEMENTATION
#include "graph.h"

int main(int argc, char**argv)
{
    // bug invalid file pointer. (when freeing the Graph in ADJ_MATRIX mode).
    
    int NumberOfVertices = 5;
    graph Graph = GraphNew(ADJ_LIST, NumberOfVertices);
    GraphAddDirectedWeightedEdge(&Graph, 0, 1, 5);
    GraphAddUnDirectedWeightedEdge(&Graph, 0, 2, 13);
    GraphAddDirectedEdge(&Graph, 2, 3);
    GraphAddDirectedWeightedEdge(&Graph, 3, 1, 6);
    GraphAddDirectedWeightedEdge(&Graph, 3, 4, 78);
    char* Str = GraphToString(&Graph);
    printf("%s\n", Str);
    free(Str);

    GraphAddVertices(&Graph, 2);
    GraphAddDirectedWeightedEdge(&Graph, 0, 5, 16);
    GraphAddUnDirectedEdge(&Graph, 3, 6);

     Str = GraphToString(&Graph);
    printf("%s\n", Str);
    free(Str);
    GraphFree(&Graph);
    return 0;
}
