/* 
This concept is combined effort of following tutorials
https://www.tutorialspoint.com/data_structures_algorithms/spanning_tree.htm 
                            &
http://www.martinbroadhurst.com/spanning-trees-of-a-graph-in-c.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <D:\wamp\www\Concepts\Datastructure\connected-components-in-graph.c>

typedef void (*treefn)(edge*, int);

int different_component(edge *tree, int t, int v, int v1, int v2)
{
    int *components;
    connected_components(tree, t, v, &components);
    int different = components[v1] != components[v2];
    free(components);

    return different;
}

void spanning_tree_recrursive(edge *edges, edge *tree, int n, int v, int t, int predecessor, treefn fun)
{
    if( t == (v - 1) ){
        //print if a tree is found
        fun(tree, (v - 1));
    }
    else{
        
        for(int e = predecessor + 1; e < n; e++)
        {
            if(t == 0 || different_component(tree, t, v, edges[e].first, edges[e].second))
            {
                tree[t] = edges[e];
                spanning_tree_recrursive(edges, tree, n , v , t + 1, e, fun);
            }
        }
    }
}

void spanning_trees(edge *edges, int v, int n, treefn fun)
{
    edge *tree;

    tree = malloc((n-1) * sizeof(edge));
    if(tree == NULL)
        return;

    spanning_tree_recrursive(edges, tree, n , v , 0 , -1, fun);
}
//Calculate the nth triangular numbert T(n)
int triangular_number(int n)
{
    return (n*(n+1))/2;
}

//construct a complete graph using v vertices
edge *complete_graph(int v){
    int k;

    int n = triangular_number(v - 1);
    edge *edges = malloc(n * sizeof(edge));

    if(edges != NULL)
    {
        for(int i = 0; i < v - 1; i++)
        {
            for(int j = i + 1; j < v; j++)
            {
                edges[k].first = i;
                edges[k].second = j;
                k++;
            }
        }
    }

    return edges;
}

static void print_tree(edge *tree, int v)
{
    for(int i = 0; i < v; i++)
    {
        printf("(%d, %d) ",tree[i].first, tree[i].second);
    }
    putchar('\n');
}

int main(){

    //no of vertices
    int v = 5;
    int n = triangular_number(v - 1);

    edge *edges;

    //construct a complete graph
    edges = complete_graph(v);
    
    if(edges == NULL)
    {
       printf("NULL edges \n");
       return 0;
    }

     //construct spanning trees
    spanning_trees(edges, v, n, print_tree);
    free(edges);

    return 0;
}