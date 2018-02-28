/* // A union by rank and path compression based program to detect cycle in a graph
Concept is here: https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
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

struct subset{
      int parent;
      int rank;
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

// A utility function to find set of an element no
// (uses path compression technique)
int find(struct subset subsets[], int no)
{
      if(subsets[no].parent != no)
            subsets[no].parent  = find(subsets, subsets[no].parent);

      return subsets[no].parent;

}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(int x, int y, struct subset subsets[])
{
      int xroot = x;//find(subsets, x);
      int yroot = y;//find(subsets, y);

      // Attach smaller rank tree under root of high rank tree
      // (Union by Rank)
      if(subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
      else if(subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
      
      // If ranks are same, then make one as root and increment
      // its rank by one           
      else{
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
      }
}

// The main function to check whether a given graph contains 
// cycle or not
int isCycle(struct Graph *graph)
{
      // Allocate memory for creating V subsets
      struct subset *subsets = malloc(graph->V * sizeof(struct subset));

      for(int k = 0; k < graph->V; k++)
      {
            subsets[k].parent = k;
            subsets[k].rank = 0;
      }

      // Iterate through all edges of graph, find subset of both
      // vertices of every edge, if both subsets are same, then 
      // there is cycle in graph.
      for(int i = 0; i < graph->E; i++)
      {
            int x = find(subsets, graph->edge[i].src);
            int y = find(subsets, graph->edge[i].dest);

            if(x == y)
                  return 1;

            Union(x, y, subsets);
      }

      for(int i = 0; i < graph->V; i++)
      {
            printf("subset[%d].parent = %d \n", i, subsets[i].parent);
            printf("subset[%d].rank = %d \n", i, subsets[i].rank);
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
    int V = 3, E = 2;
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
//     graph->edge[2].src = 0;
//     graph->edge[2].dest = 2;

    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );

    return 0;
}