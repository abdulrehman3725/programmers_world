/* A C / C++ program for Prim's Minimum Spanning Tree (MST) algorithm. 
 The program is for adjacency matrix representation of the graph
 Source: https://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V], int **skipList)
{

    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        printf("U= %d \n", u);
        for (int v = 0; v < V; v++)
            
            if (skipList[u][v] == -1)
            {
                printf("SKIPPED \n");
            }
            else
            {
                // graph[u][v] is non zero only for adjacent vertices of m
                // mstSet[v] is false for vertices not yet included in MST
                // Update the key only if graph[u][v] is smaller than key[v]
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                    parent[v] = u, key[v] = graph[u][v];
            }
    }

    // print the constructed MST
    printMST(parent, V, graph);
}

// driver program to test above function
int main()
{
    /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    /*=====================================================================
        FOLLOWING WAY IS TO ASSIGN A MULTI DIMENSIONAL ARRAY USING CALLOC   
     ====================================================================*/
    // //define a pointer to pointer
    int **skipList;
    // //allocate a one-dimensional array of pointers
    skipList = calloc(V, sizeof(int*));

    for (int i = 0; i < V; i++)
        skipList[i] = calloc(5, sizeof(int));
  
    for(int i = 0; i < V; i++)
        for(int j = 0; j<V; j++)
        {
            skipList[i][j] = 0;
        }

    /* ======================================
        NOW YOU CAN USE AS skipList[i][j] 
    =========================================*/

    //to remove all loops and parallel edges
    for (int i = 0; i < V; i++)
    {
        //skip those indexes which are creating loops
        if (graph[i][i] != 0)
        {
            skipList[i][i] = -1;
        }
        else
        {
            for (int j = 0; j < V; j++)
            {
                //check if any edge is not in skiplist and skip the index which is current index
                //being checked
                if (skipList[i][j] != -1 && graph[i][j] != graph[j][i])
                {
                    if (graph[i][j] < graph[j][i])
                        graph[j][i] = graph[i][j];
                    else if(graph[i][j] > graph[j][i])
                        graph[i][j] = graph[j][i];
                        
                    break;
                }
            }
        }
    }

    // Print the solution
    primMST(graph, skipList);

    return 0;
}