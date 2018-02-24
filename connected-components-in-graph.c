/*
To find connected components in a graph use this code with uncommented int main().
This code is basically base for finding the spanning trees in a graph which you can find in spanning-trees-of-a-graph.c. For that
we need to comment the int main() in this code so that we can include this file in spanning-trees-of-a-graph.c

The following code explanation is at following link
http://www.martinbroadhurst.com/connected-components-of-a-graph-in-c.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <D:\wamp\www\Concepts\Datastructure\cirque_implementation.c>

typedef struct
{
    unsigned int first;
    unsigned int second;
} edge;

//USING DEPTH FIRST SEARCH METHOD
void connected_components_recursive(const edge *edges, unsigned int e, int vertix, int component, int *components)
{
    components[vertix] = component;

    for (int i = 0; i < e; i++)
    {
        if (edges[i].first == vertix || edges[i].second == vertix)
        {
            const unsigned int *neighbour = vertix == edges[i].first ? &edges[i].second : &edges[i].first;

            //not visited
            if (components[*neighbour] == -1)
            {
                connected_components_recursive(edges, e, *neighbour, component, components);
            }
        }
    }
}

//USING BREADTH FIRST SEARCH METHOD
void connected_components_internal(const edge *edges, unsigned int e, int vertix, int component, int *components)
{
    components[vertix] = component;
    cirque *queue = cirque_create();

    if (queue == NULL)
    {
        cirque_delete(queue);
        return;
    }

    cirque_insert(queue, &vertix);

    while (cirque_get_count(queue))
    {
        int *current = cirque_remove(queue);

        for (int i = 0; i < e; i++)
        {
            if (edges[i].first == *current || edges[i].second == *current)
            {
                const unsigned int *neighbour = *current == edges[i].first ? &edges[i].second : &edges[i].first;

                //not visited
                if (components[*neighbour] == -1)
                {
                    components[*neighbour] = component;
                    cirque_insert(queue, (void*)neighbour);
                }
            }
        }
    }
    cirque_delete(queue);
}

unsigned int connected_components(const edge *edges, unsigned int e, unsigned int v, int **components)
{
    int component = 0;

    *components = malloc(v * sizeof(int));

    if (*components == NULL)
        return 0;

    for (int i = 0; i < v; i++)
        (*components)[i] = -1;

    for (int j = 0; j < v; j++)
    {
        if ((*components)[j] == -1)
        {
            //by breadth first method
            connected_components_internal(edges, e, j, component, *components);

            //by depth first method
            // connected_components_recursive(edges, e, j, component, *components);

            component++;
        }
    }

    return component;
}

void printComponents(int *components, int v)
{
    for (int i = 0; i < v; i++)
    {
        printf("%d vertix is in %d component \n", i, components[i]);
    }
}

int main()
{
    int *components;
    edge *edges;
    //no of vertices
    unsigned const int v = 9;
    //no of edges
    unsigned const int e = v - 1;

    edges = malloc(e * sizeof(edge));

    if (edges == NULL)
        return 1;

    //Square component
    edges[0].first = 0;
    edges[0].second = 1;
    edges[1].first = 1;
    edges[1].second = 2;
    edges[2].first = 2;
    edges[2].second = 3;
    edges[3].first = 3;
    edges[3].second = 0;

    //Triangle component
    edges[4].first = 4;
    edges[4].second = 5;
    edges[5].first = 5;
    edges[5].second = 6;
    edges[6].first = 6;
    edges[6].second = 4;

    //Line component
    edges[7].first = 7;
    edges[7].second = 8;
    edges[8].first = 8;
    edges[8].second = 7;

    int c = connected_components(edges, e, v, &components);

    if (components == NULL) 
    {
        free(edges);
        return 1;
    }

    printf("There are %d components \n", c);
    printComponents(components, v);

    free(edges);
    free(components);
 
    return 0;
}