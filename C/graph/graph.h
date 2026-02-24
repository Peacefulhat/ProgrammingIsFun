#ifndef GRAPH_H
#define GRAPH_H
#define DYNAMICARRAY_IMPLEMENTATION
#define STRSTREAM_IMPLEMENTATION
#include "dynamic_array.h"
#include "strstream.h"


// Values for Graph types.
#define ADJ_MATRIX 0 // false.
#define ADJ_LIST !0 // true.

typedef struct {
    int V1;
    int V2;
    int Weight;
}edge;

typedef struct{

    int NumberOfVertices;
    // edge storage
    union {
        int** AdjacencyMatrix;
        dynamicarray* AdjacencyList;
    };
    char GraphType; 
}graph;

// Edge
edge* CreateEdge(int V1, int V2);
edge* CreateWeightedEdge(int V1, int V2, int Weight);

// Graph
graph GraphNew(char GraphType, int NumberOfVertices);
void GraphFree(graph* Graph);

void GraphAddVertices(graph* Graph, int NumberOfVertices);
void GraphAddDirectedEdge(graph* Graph, int V1, int V2);
void GraphAddDirectedWeightedEdge(graph* Graph, int V1, int V2, int Weight);
void GraphAddUnDirectedEdge(graph* Graph, int V1, int V2);
void GraphAddUnDirectedWeightedEdge(graph* Graph, int V1, int V2, int Weight);

char* GraphToString(graph* Graph);
void GraphDfsStart(graph* Graph);

#endif

#ifdef GRAPH_IMPLEMENTATION

edge* CreateEdge(int V1, int V2)
{
    edge* Ret = malloc(sizeof(edge));
    Ret->V1 = V1;
    Ret->V2 = V2;
    Ret->Weight = 1;// Default Weight.
    return Ret;
}

edge* CreateWeightedEdge(int V1, int V2, int Weight)
{
    edge* Ret = malloc(sizeof(edge));
    Ret->V1 = V1;
    Ret->V2 = V2;
    Ret->Weight = Weight; // Default Weight.
    return Ret;
}

graph GraphNew(char GraphType, int NumberOfVertices)
{
    graph Graph = {NumberOfVertices, NULL, GraphType};
    if(GraphType)
    {
        Graph.AdjacencyList = malloc(NumberOfVertices * sizeof(dynamicarray));
        for(int Index = 0; Index < NumberOfVertices; ++Index)
        {
            Graph.AdjacencyList[Index] = dynarr_defaultAllocate();
        }
    }else
    {
        Graph.AdjacencyMatrix = malloc(NumberOfVertices * sizeof(int*));
        for(int Row = 0; Row < NumberOfVertices; Row++)
        {
            // allocate the row
            Graph.AdjacencyMatrix[Row] = malloc(NumberOfVertices * sizeof(int));
            for(int Cols = 0; Cols < NumberOfVertices; Cols++){
                Graph.AdjacencyMatrix[Row][Cols] = 0;
            }
        }
    }
    return Graph;
}

void GraphFree(graph *Graph)
{
    if (Graph)
    {
        if (Graph->GraphType)
        {
            // free each list
            for (int i = 0; i < Graph->NumberOfVertices; i++)
            {
                dynarr_freeDeep(Graph->AdjacencyList + i); // &g->adjacencyLists[i]
            }
            free(Graph->AdjacencyList);
        }
        else
        {
            for (int i = 0; i < Graph->NumberOfVertices; i++)
            {
                free(Graph->AdjacencyMatrix + i);
            }
            free(Graph->AdjacencyMatrix);
        }
    }
}
void GraphAddVertices(graph* Graph, int NumberOfVertices )
{
    int NewNumberOfVertices = Graph->NumberOfVertices + NumberOfVertices;

    if (Graph->GraphType)
    {
        dynamicarray *OldMemory = Graph->AdjacencyList; // get original pointer
        Graph->AdjacencyList = realloc(Graph->AdjacencyList, NewNumberOfVertices * sizeof(dynamicarray));
        if (!Graph->AdjacencyList)
        {
            // reallocate in new location
            Graph->AdjacencyList = malloc(NewNumberOfVertices * sizeof(dynamicarray));
            memcpy(Graph->AdjacencyList, OldMemory, Graph->NumberOfVertices * sizeof(dynamicarray));
            free(OldMemory);

            // allocate new lists
            for (int i = 0; i < NumberOfVertices; i++)
            {
                Graph->AdjacencyList[i + Graph->NumberOfVertices] = dynarr_defaultAllocate();
            }
        }
    }
    else
    {
        int **NewAdjacencyMatrix = malloc(NewNumberOfVertices * sizeof(int *));
        for (int Row = 0; Row < NewNumberOfVertices; Row++)
        {
             NewAdjacencyMatrix[Row] = malloc(NewNumberOfVertices * sizeof(int));
            if (Row < Graph->NumberOfVertices)
            {
                // copy existing values
                memcpy(NewAdjacencyMatrix[Row], Graph->AdjacencyMatrix[Row], Graph->NumberOfVertices * sizeof(int));
                // set new values
                for (int Cols = 0; Cols < NumberOfVertices; Cols++)
                {
                    NewAdjacencyMatrix[Row][Cols + Graph->NumberOfVertices] = 0;
                }

                // free old memory
                free(Graph->AdjacencyMatrix[Row]);
            }
            else
            {
                // set new rows to hold all zeros
                for (int Cols = 0; Cols < NewNumberOfVertices; Cols++)
                {
                    NewAdjacencyMatrix[Row][Cols] = 0;
                }
            }
        }
        // free old memory
        free(Graph->AdjacencyMatrix);

        // update pointers
        Graph->AdjacencyMatrix = NewAdjacencyMatrix;
    }

    Graph->NumberOfVertices = NewNumberOfVertices;
}

void GraphAddDirectedEdge(graph* Graph, int V1, int V2)
{
    if(Graph->GraphType)
    {
        dynarr_addLast(Graph->AdjacencyList + V1, CreateEdge(V1, V2));
        
    }
    else
    {
        Graph->AdjacencyMatrix[V1][V2] = !0;
    }
    
}

void GraphAddDirectedWeightedEdge(graph* Graph, int V1, int V2, int Weight)
{
    if(Graph->GraphType)
    {
        dynarr_addLast(Graph->AdjacencyList + V1, CreateWeightedEdge(V1, V2, Weight));
        
    }
    else
    {
        Graph->AdjacencyMatrix[V1][V2] = Weight;
    }
    
}

void GraphAddUnDirectedEdge(graph* Graph, int V1, int V2){
    if(Graph->GraphType)
    {
        dynarr_addLast(Graph->AdjacencyList + V1, CreateEdge(V1, V2));
        dynarr_addLast(Graph->AdjacencyList + V2, CreateEdge(V2, V1));    
    }
    else
    {
        Graph->AdjacencyMatrix[V1][V2] = !0;
        Graph->AdjacencyMatrix[V2][V1] = !0;
    } 
}

void GraphAddUnDirectedWeightedEdge(graph* Graph, int V1, int V2, int Weight)
{
    if(Graph->GraphType)
    {
        dynarr_addLast(Graph->AdjacencyList + V1, CreateWeightedEdge(V1, V2, Weight));
        dynarr_addLast(Graph->AdjacencyList + V2, CreateWeightedEdge(V2, V1, Weight));    
    }
    else
    {
        Graph->AdjacencyMatrix[V1][V2] = Weight;
        Graph->AdjacencyMatrix[V2][V1] = Weight;
    } 
}

char* GraphToString(graph* Graph)
{
    strstream Ret = strstream_alloc(Graph->NumberOfVertices);
    for(int Row = 0; Row < Graph->NumberOfVertices; ++Row)
    {
        if(Graph->GraphType)
        {
            edge *E = NULL;
            dynarr_iterator It = dynarr_iterator_new(Graph->AdjacencyList + Row);
            while((E = dynarr_iterator_next(&It)))
            {
                if(E->Weight)
                {
                    strstream_concat(&Ret, "%d -> %d; %d\n",E->V1, E->V2, E->Weight);
                }
            }
            
        }
        else
        {
            for(int Cols = 0; Cols < Graph->NumberOfVertices; ++Cols)
            {
                if(Graph->AdjacencyMatrix[Row][Cols])
                {
                    strstream_concat(&Ret, "%d -> %d; %d\n", Row, Cols, Graph->AdjacencyMatrix[Row][Cols]);
                }
            }
        }
        
    }
    return Ret.str;
}


#endif

