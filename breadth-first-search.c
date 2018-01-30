#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex{
    char label;
    bool visited;
};

struct Vertex* vertexes[MAX];
int vertexesCount = 0;
int adjVertexes[MAX][MAX];
int rear = -1, front = 0;
int queue[MAX];
int queueCount = 0;

int isFull(){
    return vertexesCount == MAX;
}

void addVertex(char label){
    struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    vertex->label = label;
    vertex->visited = false;

    if(!isFull())
    {
        vertexes[vertexesCount++] = vertex;
    }
    else
    {
        printf("Vertexes are full \n");
    }
}

void addEdge(int start, int end)
{
    adjVertexes[start][end] = 1;
    adjVertexes[end][start] = 1;
}

int isQueueEmpty()
{
    return queueCount == 0;
}

void enqueue(int no){
    queue[++rear] = no;
    queueCount++;
}

int dequeue(){
    queueCount--;
    return queue[front++];
}

int getAdjUnvisitedVertex(int vertexIndex)
{
    for(int i = 0; i < vertexesCount; i++)
    {
        if(vertexes[i]->visited == false && adjVertexes[vertexIndex][i] == 1)
            return i;
    }

    return -1;
}

void displayVertex(int vertexIndex)
{
    printf("%c", vertexes[vertexIndex]->label);
}

void bfs(){

    int unvisitedVertex;

    vertexes[0]->visited = true;
    
    displayVertex(0);   

    enqueue(0);

    while(!isQueueEmpty())
    {
        int temp = dequeue();

        while((unvisitedVertex = getAdjUnvisitedVertex(temp)) != -1)
        {
            vertexes[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);   
            enqueue(unvisitedVertex);  
        }
    }
}

int main()
{
    int i, j;

   for(i = 0; i<MAX; i++) // set adjacency 
   {
      for(j = 0; j<MAX; j++) // matrix to 0
         adjVertexes[i][j] = 0;
   }

   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4
 
   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D
	
   printf("\nBreadth First Search: ");
   
   bfs();

   return 0;
}