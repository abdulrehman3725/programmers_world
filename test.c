#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int rear = -1, front = 0, size = 0, queue[MAX];

int top()
{
    return queue[front];
}

int isFull()
{
    return size == MAX;
}

void enqueue(int no)
{
    if(!isFull())
    {
        queue[++rear] = no;
        if(rear == MAX-1)
        {
            rear = -1;
        }
        size++;
    }
    else
        printf("QUEUE is FULL \n");
}

int isEmpty()
{
    if(front == MAX)
        front = 0;
    return size == 0;
}

int dequeue()
{
    if(!isEmpty())
    {
        size--;
        return queue[front++];
    }
    else
        printf("QUEUE is empty");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(15);


printf("\n");
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    // printf("DEQUED: %d: \n", dequeue());

    enqueue(10);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    
printf("\n");
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());


    return 0;
}