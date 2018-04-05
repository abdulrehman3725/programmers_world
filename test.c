#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

struct Vertice
{
    char label;
    bool visited;
};

int adjVertices[SIZE][SIZE], verticeQueue[SIZE], front = 0, rear=-1, queueCount=0, count = 0;
struct Vertice *verticeList[SIZE];

bool isFull()
{
    return count == SIZE;
}

bool isEmpty()
{
    return count == 0;
}

bool isEmptyQueue()
{
    if(front == SIZE)
    {
        front = 0;        
    }
    return queueCount == 0;
}

bool isFullQueue()
{
    return queueCount == SIZE;
}

void enqueue(int index)
{
    if(!isFullQueue())
    {
        verticeQueue[++rear] = index;
        
        if(rear == SIZE-1)
        {
            rear = -1;
        }

        queueCount++;
    }
    else
        printf("QUEUE is full \n");
}

int dequeue()
{
    if(!isEmpty())
    {
        verticeQueue[front++];
        queueCount--;
    }
    else    
        printf("QUeue is Empty \n");

}

void addVertice(char label)
{
    if (!isFull())
    {
        struct Vertice *vertice = (struct Vertice *)malloc(sizeof(struct Vertice));

        vertice->label = label;
        vertice->visited = false;
        verticeList[count++] = vertice;
    }
    else
        printf("ARRAY IS FULL \n");
}

void addEdge(int vertice1, int vertice2)
{
    adjVertices[vertice1][vertice2] = 1;
}

int unvisitedVertex(int vertexIndex)
{
    for (int j = 0; j < SIZE; j++)
    {
        if (adjVertices[vertexIndex][j] == 1 && verticeList[j]->visited == false)
        {
            return j;
        }
    }

    return -1;
}

void display(struct Vertice *vertice)
{
    printf("Label: %c \n", vertice->label);
}

void dfs()
{
    int unvisited,top, i = 0;
    verticeList[0]->visited = true;
    display(verticeList[0]);
    enqueue(0);
    
    while (!isEmptyQueue())
    {
        top = dequeue();

        while((unvisited = unvisitedVertex(top)) != -1)
        {            
            verticeList[unvisited]->visited = true;
            display(verticeList[unvisited]);
            enqueue(unvisited);
        }
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            adjVertices[i][j] = 0;
        }
    }

    addVertice('S');
    addVertice('A');
    addVertice('B');
    addVertice('C');
    addVertice('D');

    addEdge(0, 1); // S - A
    addEdge(0, 2); // S - B
    addEdge(0, 3); // S - C
    addEdge(1, 4); // A - D
    addEdge(2, 4); // B - D
    addEdge(3, 4); // C - D

    dfs();
    return 0;
}