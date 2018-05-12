/*  C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
of a given connected, undirected and weighted graph
Concept is here: https://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
Below code is more optimized then above. Below code technique is little bit modified then above but both
are correct.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
// a structure to represent an edge in graph
struct Edge
{
    int src, dest, weight;
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
int isCycle(int v, int len, struct Edge *mstTree)
{
      // Allocate memory for creating V subsets
      struct subset *subsets = malloc(v * sizeof(struct subset));

      for(int k = 0; k < v; k++)
      {
            subsets[k].parent = k;
            subsets[k].rank = 0;
      }

      // Iterate through all edges of graph, find subset of both
      // vertices of every edge, if both subsets are same, then 
      // there is cycle in graph.
      for(int i = 0; i < len; i++)
      {
            int x = find(subsets, mstTree[i].src);
            int y = find(subsets, mstTree[i].dest);

            if(x == y)
                return 1;

            Union(x, y, subsets);
      }

    //   for(int i = 0; i < v; i++)
    //   {
    //         printf("subset[%d].parent = %d \n", i, subsets[i].parent);
    //         printf("subset[%d].rank = %d \n", i, subsets[i].rank);
    //   }      
      return 0;
}

void Sort(struct Edge edge[],int e)
{
    struct Edge temp;

    for(int i = 0; i < e - 1;  i++)
    {
        bool swapped = true;
        for(int j = 0; j < e - (i+1); j++)
        {
            if(edge[j].weight > edge[j+1].weight)
            {
                temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;

                swapped = false;
            }
        }

        if(swapped == true)
        {
            // printf("Already Sorted \n");
            break;
        }
        else
        {
            // printf("NOt Already SOrted \n");
        }
    }
}

int main()
{
      // int V = 9, E = 14;
      // struct Graph* graph = createGraph(V, E);

      // // add edge 0-1
      // graph->edge[0].src = 0;
      // graph->edge[0].dest = 1;
      // graph->edge[0].weight = 4 ;

      // // add edge 1-2
      // graph->edge[1].src = 1;
      // graph->edge[1].dest = 2;
      // graph->edge[1].weight = 8 ;

      // // add edge 2-3
      // graph->edge[2].src = 2;
      // graph->edge[2].dest = 3;
      // graph->edge[2].weight = 7 ;

      // // add edge 3-4
      // graph->edge[3].src = 3;
      // graph->edge[3].dest = 4;
      // graph->edge[3].weight = 9 ;

      // // add edge 4-5
      // graph->edge[4].src = 5;
      // graph->edge[4].dest = 4;
      // graph->edge[4].weight = 10;

      // // add edge 5-2
      // graph->edge[5].src = 2;
      // graph->edge[5].dest = 5;
      // graph->edge[5].weight = 4;

      // // add edge 5-3
      // graph->edge[6].src = 3;
      // graph->edge[6].dest = 5;
      // graph->edge[6].weight = 14 ;

      // // add edge 5-6
      // graph->edge[7].src = 6;
      // graph->edge[7].dest = 5;
      // graph->edge[7].weight = 2;

      // // add edge 6-8
      // graph->edge[8].src = 8;
      // graph->edge[8].dest = 6;
      // graph->edge[8].weight = 6;

      // // add edge 8-2
      // graph->edge[9].src = 8;
      // graph->edge[9].dest = 2;
      // graph->edge[9].weight = 2;

      // // add edge 6-7
      // graph->edge[10].src = 7;
      // graph->edge[10].dest = 6;
      // graph->edge[10].weight = 1;

      // // add edge 7-8
      // graph->edge[11].src = 7;
      // graph->edge[11].dest = 8;
      // graph->edge[11].weight = 7;

      // // add edge 7-1
      // graph->edge[12].src = 1;
      // graph->edge[12].dest = 7;
      // graph->edge[12].weight = 11;

      // // add edge 7-0
      // graph->edge[13].src = 0;
      // graph->edge[13].dest = 7;
      // graph->edge[13].weight = 8;

      /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */

      int V = 4, E = 7;
      int *skipList = calloc(E, sizeof(int));

      struct Graph *graph = createGraph(V, E);

      // add edge 0-1
      graph->edge[0].src = 0;
      graph->edge[0].dest = 1;
      graph->edge[0].weight = 10;

      // add edge 0-2
      graph->edge[1].src = 0;
      graph->edge[1].dest = 2;
      graph->edge[1].weight = 6;

      // add edge 0-3
      graph->edge[2].src = 0;
      graph->edge[2].dest = 3;
      graph->edge[2].weight = 5;

      // add edge 1-3
      graph->edge[3].src = 1;
      graph->edge[3].dest = 3;
      graph->edge[3].weight = 15;

      // add edge 2-3
      graph->edge[4].src = 2;
      graph->edge[4].dest = 3;
      graph->edge[4].weight = 4;

      // add edge 3-2
      graph->edge[5].src = 3;
      graph->edge[5].dest = 2;
      graph->edge[5].weight = 3;

      // add edge 1-1
      graph->edge[6].src = 1;
      graph->edge[6].dest = 1;
      graph->edge[6].weight = 15;

      //to remove all loops and parallel edges
      for (int i = 0; i < E; i++)
      {
            //skip those indexes which are creating loops
            if (graph->edge[i].src == graph->edge[i].dest)
            {
                  skipList[i] = -1;
            }
            else
            {
                  for (int j = 0; j < E; j++)
                  {
                        //check if any edge is not in skiplist and skip the index which is current index
                        //being checked
                        if (skipList[j] != -1 && j != i)
                        {
                              printf("I = %d J = %d \n",i,j);
                              if ((graph->edge[i].src == graph->edge[j].dest) && (graph->edge[i].dest == graph->edge[j].src))
                              {
                                    if (graph->edge[i].weight > graph->edge[j].weight)
                                          skipList[j] = -1;
                                    else
                                          skipList[i] = -1;

                                    break;
                              }
                        }
                  }
            }
      }

      //sort the edges by weight in ascending order
      Sort(graph->edge, graph->E);

      for (int i = 0; i < graph->E; i++)
      {
            printf("weight = %d, src = %d, dest = %d  \n", graph->edge[i].weight, graph->edge[i].src, graph->edge[i].dest);
      }

      struct Edge *mstTree = malloc((graph->V - 1) * sizeof(struct Edge));

      int k = 0;

      //include those edges in Mst Tree which do not form cycle
      for (int m = 0; m < graph->E; m++)
      {
            if (skipList[m] == -1)
                  printf("SKIPPED \n");
            else
            {
                  mstTree[k++] = graph->edge[m];

                  if (isCycle(graph->V, k, mstTree))
                  {
                        printf("Is Cycle \n");
                        k--;
                  }
                  else
                  {
                        printf("Is not Cycle \n");
                  }
            }
      }

      // print the edges included in Minimum Spanning Tree.
      for (int i = 0; i < k; i++)
      {
            printf("(src = %d, dest = %d, weight = %d), ", mstTree[i].src, mstTree[i].dest, mstTree[i].weight);
      }

      return 0;
}