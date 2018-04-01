#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data, key;
    struct node *next;
};

struct node *head = NULL, *tail = NULL, *current = NULL, *previous;
int size = 0;

void insert(int data, int key)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->data = data;
    link->key = key;
    link->next = NULL;

    if (size == 0)
    {
        head = link;
        tail = link;
    }
    else
    {
        tail->next = link;
        tail = link;
    }

    size++;
}

struct node *delete (int key)
{
    current = head;
    previous = NULL;

    if (head == NULL)
    {
        return NULL;
    }

    if(head->key == key)
    {
        if(head == tail)
            tail = NULL;
        head = head->next;
        size--;
        return current;
    }
    
    previous = current;
    current = head->next;
    
    while (current != NULL)
    {
        if(current->key == key)
        {
            previous->next = current->next;
            size--;
            if(current == tail)
            {
                if(previous->next != NULL)
                {
                    tail = previous->next;                    
                }
                else
                {
                        tail = previous;
                }

            }
            return current;
        }

        previous = current;
        current = current->next;
    }

    return current;
}

struct node *find(int key)
{
    current = head;

    if (head == NULL)
    {
        return NULL;
    }
    else if (tail->key == key)
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
        return NULL;
    }

    return current;
}

void reverse(){

    struct node *next = NULL;
    previous = NULL;
    current = head;

    while(current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    tail = head;
    tail->next = NULL;
    head = previous;
}

void sort(){

    int tempData, tempKey;
    struct node *next = NULL;
    int i = 0, j = 0;
    int k = size;

    for( i = 0; i < size - 1; i++, --k )
    {
        current = head;
        next = head->next;
        for(j = 1; j < k; j++)
        {
            if( current->data > next->data)
            {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
                
            }
            
            current = current->next;
            next = current->next;
            
        }
    }
}

void printList(){

    current = head;

    while(current != NULL)
    {
            printf("(key = %d, value = %d) \n",current->key, current->data);
            current = current->next;
    }

}

void main(){

    insert(3,3);
    insert(2,1);
    insert(1,2);

    printf(" \n \n UN-sOrted linklist: \n \n");
    printList();
        printf("TAILS = %d , %d \n",tail->key, tail->data);
    printf(" \n \n SOrted linklist: \n \n");
    sort();
    printList();
        printf("TAILS = %d , %d \n",tail->key, tail->data);
    
  printf(" \n \n Reversed linklist: \n \n");
    reverse();
    printList();
        printf("TAILS = %d , %d \n",tail->key, tail->data);
    
    struct node *temp = find(1);
    printf("Find = data: %d, key: %d, next: %p \n", temp->data, temp->key, temp->next);
    
        struct node *temp4 = find(2);
    printf("Find = data: %d, key: %d, next: %p \n", temp4->data, temp4->key, temp4->next);
    
        struct node *temp5 = find(3);
    printf("Find = data: %d, key: %d, next: %p \n", temp5->data, temp5->key, temp5->next);
    
        struct node *temp6 = find(4);
    if(temp6 != NULL)
        printf("Find = data: %d, key: %d, next: %p \n", temp6->data, temp6->key, temp6->next);
    
    struct node *temp1 = delete(3);
    printf("DELETE = data: %d, key: %d, next: %p \n", temp1->data, temp1->key, temp1->next);
    
    printList();

    printf("TAILS = %d , %d \n",tail->key, tail->data);
    struct node *temp2 = delete(4);
    if(temp2 != NULL)
        printf("DELETE = data: %d, key: %d, next: %p \n", temp2->data, temp2->key, temp2->next);
    
    printList();
    
    temp2 = delete(1);
    if(temp2 != NULL)
    printf("DELETE = data: %d, key: %d, next: %p \n", temp2->data, temp2->key, temp2->next);
    
    printList();
    printf("TAILS = %d , %d \n",tail->key, tail->data);
    
    temp2 = delete(2);
    if(temp2 != NULL)
    printf("DELETE = data: %d, key: %d, next: %p \n", temp2->data, temp2->key, temp2->next);
    
    printList();
    if(tail != NULL)
        printf("TAILS = %d , %d \n",tail->key, tail->data);
}