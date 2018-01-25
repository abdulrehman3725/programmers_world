#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertix
{
    char label;
    bool visited;
};

struct Vertix *vertixes[MAX];
int adjVertix[MAX][MAX];
int count = 0;
int top = 0;
int stack[MAX];

int isFull()
{
    return count == MAX;
}

void addVertix(char label){
    
    if(!isFull())
    {
        struct Vertix* vertix = (struct Vertix*) malloc(sizeof(struct Vertix));
        vertix->label = label;  
        vertix->visited = false;     
        vertixes[count++] = vertix;
    }
    else
    {
        printf("VERTICES ARRAY IS FULL, Cannot add more! \n");
    }   
}

void addEdge(int vertix1, int vertix2){
    adjVertix[vertix1][vertix2] = 1;
}

void push(int vertixNo)
{
    stack[top++] = vertixNo;
}

int peek()
{
    return stack[top];
}

int pop(){
    return stack[top--];
}

int getUnvisitedVertix(int vertexIndex)
{
    for(int j=0; j < MAX; j++)
    {
        if(vertixes[j]->visited == false && adjVertix[vertexIndex][j] == 1)
        {
            return j;
        }
    }

    return -1;
}

int isStackEmpty()
{
    return top == 0;
}

void display(int visitedVertex)
{
    printf("VISITED VERTIX: %c \n", vertixes[visitedVertex]->label);
}

void dfs()
{
    if(count != 0)
    {
        int i = 0;

        vertixes[0]->visited = true;
        display(0);
        push(0);

        while(top != 0)
        {
            int unvisitedVertix = getUnvisitedVertix(peek()); 
            if(unvisitedVertix == -1)
            {
                pop();
            }
            else
            {
                vertixes[unvisitedVertix]->visited = true;
                display(unvisitedVertix);
                push(unvisitedVertix);
            }
        }
    }
}

int main()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            adjVertix[i][j] = 0;
        }
    }

    addVertix('S');
    addVertix('A');
    addVertix('B');
    addVertix('C');
    addVertix('D');
 
    addEdge(0, 1);    // S - A
    addEdge(0, 2);    // S - B
    addEdge(0, 3);    // S - C
    addEdge(1, 4);    // A - D
    addEdge(2, 4);    // B - D
    addEdge(3, 4);    // C - D

    dfs();

    return 0;
}
