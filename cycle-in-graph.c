/* A union-find algorithm to detect cycle in a graph
Concept is here: https://www.geeksforgeeks.org/union-find/
Below code is more optimized then above.
This code will is used in the kruskal's method to find Minimum Spanning Tree (MSM)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// a structure to represent an edge in graph
struct Edge
{
    int src, dest;
};
 
// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = 
           (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
     printf("V = %d , E = %d \n", graph->V, graph->E);

    graph->edge = 
        (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}

// A utility function to find the subset of an element no
int find(int *parent, int no)
{
      if(parent[no] == -1)
            return no; 
      
      find(parent, parent[no]);
}

// A utility function to do union of two subsets 
void Union(int x, int y, int **parent)
{
      (*parent)[x] = y;

}

// The main function to check whether a given graph contains 
// cycle or not
int isCycle(struct Graph *graph)
{
      // Allocate memory for creating V subsets
      int *parent = malloc(graph->V * sizeof(int));

      // Initialize all subsets as single element sets
      memset(parent, -1, sizeof(int) * graph->V);

      // Iterate through all edges of graph, find subset of both
      // vertices of every edge, if both subsets are same, then 
      // there is cycle in graph.
      for(int i = 0; i < graph->E; i++)
      {
            int x = find(parent, graph->edge[i].src);
            int y = find(parent, graph->edge[i].dest);

            if(x == y)
                  return 1;

            Union(x, y, &parent);
      }

      for(int i = 0; i < graph->V; i++)
      {
            printf("parent[%d] = %d \n", i, parent[i]);
      }
      
      return 0;
}

int main()
{
    /* Let us create following graph
         0
        |  \
        |    \
        1-----2 */    
    int V = 3, E = 3;
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 2;
    graph->edge[2].dest = 0;

    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );

    return 0;
}