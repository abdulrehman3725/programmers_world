#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX], front = 0, rear = -1, size = -1;

int isFull()
{
    return size == MAX - 1;
}

int isEmpty()
{
    if(front == MAX)
        front =0;
    return size == -1;
}

void enqueue(int no)
{
    if (!isFull())
    {
        if (rear == MAX - 1)
            rear = -1;

        queue[++rear] = no;
        size++;
    }
    else
        printf("QUEUE IS FULL \n");
}

int dequeue()
{
    if (!isEmpty())
    {
        if (front == MAX)
        {
            front = 0;
            return queue[size--];
        }

        size--;
        return queue[front++];
    }
    else
        printf("QUEUE IS EMPTY \n");
}
void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());

    enqueue(10);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);

    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
    printf("DEQUED: %d: \n", dequeue());
}