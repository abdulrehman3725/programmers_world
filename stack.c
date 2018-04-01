#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int top = -1, array[SIZE];

int isFull()
{
    return top == SIZE-1;
}

int isEmpty()
{
    return top == -1;
}

void push(int no)
{
    if(!isFull())
        array[++top] = no;
    else
        printf("Stack if Full \n");
}

int pop()
{
    if(!isEmpty())
        return array[top--];
    else
        printf("Stack is empty \n");
}

int peek()
{
    return array[top];
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("PEEK VALUE IS: %d \n",peek());

    while(!isEmpty())
        printf("POPPED value is: %d \n",pop());
        
    return 0;
}