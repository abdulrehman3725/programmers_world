/*
THe concept is here -> http://www.martinbroadhurst.com/spanning-tree-of-a-graph-in-c.html
This code is modified and improved form of the above link.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} edge;

void spanning_tree_recrursive(edge *edges, int *visited, int v, int n, int vertice, int edge, int *tree, int *len)
{
    visited[vertice] = 1 ;

    if(edge != -1)
    {
        tree[(*len)++] = edge;
    }

    
    for(int e = 0; e < n ; e++)
    {
        if(edges[e].first == vertice || edges[e].second == vertice)
        {
            int neighbour = vertice == edges[e].first ? edges[e].second : edges[e].first;

            if(!visited[neighbour])
            {
                spanning_tree_recrursive(edges, visited, v, n, neighbour, e, tree, len );
            }
        }
    }
}

int spanning_tree(edge *edges, int n, int v, int **tree)
{
    int len = 0;

    int *visited = calloc(v , sizeof(int));
    *tree = malloc((v - 1) * sizeof(int));

    if(visited == NULL || *tree == NULL)
    {
        free(visited);
        free(*tree);

        *tree = NULL;

        return 0;
    }

    spanning_tree_recrursive(edges,visited, v, n, 0, -1, *tree, &len);

    return len;
}

// Calculate the nth triangular number T(n) 
int triangular_number(int n)
{
    return (n*(n+1))/2;
}

//construct a complete graph on v vertices
int complete_graph(int v, edge **edges)
{
    //no of edges for a complete graph
    int n = triangular_number(v - 1);
    *edges = malloc( n * sizeof(edge));

    int k = 0;

    if(edges != NULL)
    {
        for(int i = 0; i < v - 1; i++)
        {
            for(int j = i + 1; j < v; j ++ )
            {
                (*edges)[k].first = i;    
                (*edges)[k].second = j;
                k++;
            }
        }
    }
    else
        return 0;

    return n;
}

int main(){

    int v = 5; // no of vertices
    edge *edges; 

    int n = complete_graph(v, &edges);

    int *tree;
    int tree_size = spanning_tree(edges, n, v, &tree);

    for( int i = 0; i < tree_size; i++)
    {
        printf("(%d, %d), ", edges[tree[i]].first, edges[tree[i]].second);
    }
    return 0;
}