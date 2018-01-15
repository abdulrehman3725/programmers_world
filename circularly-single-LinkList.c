#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data, key;
    struct node *next, *previous;
};

struct node *head = NULL, *tail = NULL, *current = NULL, *next = NULL, *previous = NULL, *temp = NULL;
int size = 0;

void link(int data, int key)
{
    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->key = key;

    if (head == NULL)
    {
        head = link;
        tail = link;
    }
    else
    {
        tail->next = link;
        link->previous = tail;
        tail = link;
    }

    size++;
}

void reversePrint(){
    current = tail;
    while(current != NULL)
    {
        printf("data:%d , key:%d \n", current->data, current->key);
        current = current->previous;
    }
}
struct node *delete (int key)
{

    current = head;

    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        if (head->key == key)
        {
            if (head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                head->previous = NULL;
            }

            size--;
            return current;
        }
        else if(tail->key == key)
        {
            current = tail;
            tail = tail->previous;
            tail->next = head;
            head->previous = tail;

            size--;
            return current;
        }
        else
        {
            next = current->next;
            current = next;
            while (current != tail)
            {
                if (current->key == key)
                {
                        temp = current->next;
                        previous = current->previous;
                        previous->next = temp;
                        temp->previous = previous;
                }
                size--;
                return current;
                }
                current = current->next;
            }
            return current;
        }
    }


struct node *find(int key)
{
    current = head;
    next = head->next;

    if (head == NULL)
        return NULL;
    else
    {
        if (head->key == key)
            return head;
        else if (tail->key == key)
            return tail;
        else
        {
            current = next;

            while (current != tail)
            {
                if (current->key == key)
                {
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

    if (head == NULL)
        printf("Linklist is empty \n");
    else
        while (current != NULL)
        {
            printf("Key: %d , Data: %d next:%p previous:%p \n", current->key, current->data, current->next, current->previous);
            current = current->next;
        }
}

void reverse()
{
    current = head;
    struct node *current_previous = NULL;
    
    int i = 0;
    while( current != NULL)
    {
       next = current->next;
       current_previous = current->previous;
       current->next = previous;
       previous = current;
       current->previous = next;
       current = next;
    }
    
    tail = head;
    tail->next = NULL;
    head = previous;
    
}

void sort(){

    current = head;
    int k = size, temp;

    for(int i = 0; i < size - 1; i++, k--)
    {
        current = head;
        
        for(int j = 1; j < k; j++)
        {
            next = current->next;
            if(current->data > next->data)
            {
                temp = current->data;
                current->data = next->data;
                next->data = temp;

                temp = current->key;
                current->key = next->key;
                next->key = temp;
            }

            current = current->next;
        }
    }
}

void main(){
    link(3, 3);
    link(2, 1);
    link(1, 2);

    printf(" \n \n UN-sOrted linklist: \n \n");
    printList();
    printf(" \n \n Reverse Print: \n \n");
    reversePrint();
    printf("TAILS = %d , %d \n", tail->key, tail->data);
    printf(" \n \n SOrted linklist: \n \n");
    sort();
    printList();
    printf("TAILS = %d , %d \n", tail->key, tail->data);

    printf(" \n \n Reversed linklist: \n \n");
    reverse();
    printList();
    printf("TAILS = %d , %d \n", tail->key, tail->data);
    printf("HEAD = %d , %d \n", head->key, head->data);

    struct node *temp = find(1);
    printf("Find = data: %d, key: %d, next: %p \n", temp->data, temp->key, temp->next);

    struct node *temp4 = find(2);
    printf("Find = data: %d, key: %d, next: %p \n", temp4->data, temp4->key, temp4->next);

    struct node *temp5 = find(3);
    printf("Find = data: %d, key: %d, next: %p \n", temp5->data, temp5->key, temp5->next);

    struct node *temp6 = find(4);
    if (temp6 != NULL)
        printf("Find = data: %d, key: %d, next: %p \n", temp6->data, temp6->key, temp6->next);

    struct node *temp1 = delete (3);
    printf("DELETE = data: %d, key: %d, next: %p \n", temp1->data, temp1->key, temp1->next);

    printList();

    printf("TAILS = %d , %d \n", tail->key, tail->data);
    struct node *temp2 = delete (4);
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
}