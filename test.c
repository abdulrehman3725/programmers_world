#include <stdio.h>
#include <stdlib.h>
#define MAX 4

struct Node
{
    int key, data;
    struct Node *previous, *next;
};

struct Node *head = NULL, *tail = NULL, *current, *next, *previous, *temp;

void insert(int key, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->data = data;

    if (head == NULL)
    {
        node->next = node;
        node->previous = node;
        head = node;
        tail = node;
    }
    else
    {
        node->previous = tail;
        node->next = head;
        tail->next = node;
        tail = node;
        head->previous = tail;
    }
}

void reverse()
{
    next = NULL;
    previous = tail;
    current = head;

    if (head != NULL)
    {
        next = current->next;
        current->next = previous;
        current->previous = next;
        previous = current;
        tail = current;
        current = next;

        while (current != tail)
        {
            next = current->next;
            current->next = previous;
            current->previous = next;
            previous = current;
            current = next;
        }
        head = previous;
    }
}

struct Node *find(int key)
{
    current = head;

    if (head == NULL)
        return NULL;
    else
    {
        if (tail->key == key)
        {
            return tail;
        }
        else
        {
            while (current != tail)
            {
                if (current->key == key)
                {
                    return current;
                }
                current = current->next;
            }
        }
    }
}

struct Node *delete(int key)
{

    if (head == NULL)
        return NULL;
    else
    {
        current = head;

        if (head->key == key)
        {
            temp = head;
            if (head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = current->next;
                head->previous = tail;
                tail->next = head;
            }
            return temp;
        }
        else if (tail->key == key)
        {
            temp = tail;
            tail = tail->previous;
            tail->next = head;
            head->previous = tail;

            return temp;
        }
        else
        {
            current = current->next;

            while (current != tail)
            {
                if (current->key == key)
                {
                    previous = current->previous;
                    next = current->next;
                    previous->next = next;
                    next->previous = previous;
                    return current;
                }
                current = current->next;
            }
        }
        return NULL;
    }
}

void printList()
{
    current = head;

    if (current == NULL)
        printf("LINKLISt iS EMPTY \n");
    else
    {
        printf("Key:%d, Data:%d, Next:%p, Previous:%p \n", current->key, current->data, current->next, current->previous);
        current = current->next;
        while (current != head)
        {
            printf("Key:%d, Data:%d, Next:%p, Previous:%p \n", current->key, current->data, current->next, current->previous);
            current = current->next;
        }
    }
}

int main()
{
    insert(3, 3);
    insert(2, 2);
    insert(1, 1);

    printList();

    reverse();
    printf("\n\n REVERSED LINKLISt \n \n");
    printList();

    struct Node *temp1 = delete(3);
    printf("DELETE = data: %d, key: %d, next: %p \n", temp1->data, temp1->key, temp1->next);

    printList();

    printf("TAILS = %d , %d \n", tail->key, tail->data);
    struct Node *temp2 = delete(4);
    if (temp2 != NULL)
        printf("DELETE = data: %d, key: %d, next: %p \n", temp2->data, temp2->key, temp2->next);

    printList();

    printf("TAILS = %d , %d \n", tail->key, tail->data);
    printf("HEAD = %d , %d \n", head->key, head->data);
    
    temp2 = delete (1);
    if (temp2 != NULL)
        printf("DELETE = data: %d, key: %d, next: %p \n", temp2->data, temp2->key, temp2->next);

    printList();
    printf("TAILS = %d , %d \n", tail->key, tail->data);
    printf("HEAD = %d , %d \n", head->key, head->data);

    temp2 = delete (2);
    if (temp2 != NULL)
        printf("DELETE = data: %d, key: %d, next: %p \n", temp2->data, temp2->key, temp2->next);

    printList();
    if (tail != NULL)
        printf("TAILS = %d , %d \n", tail->key, tail->data);
    if (head != NULL)
        printf("HEADS = %d , %d \n", head->key, head->data);
             
    temp2 = delete (2);
    if (temp2 != NULL)
        printf("DELETE = data: %d, key: %d, next: %p \n", temp2->data, temp2->key, temp2->next);

    printList();
    if (tail != NULL)
        printf("TAILS = %d , %d \n", tail->key, tail->data);
    if (head != NULL)
        printf("HEADS = %d , %d \n", head->key, head->data);
    return 0;
}