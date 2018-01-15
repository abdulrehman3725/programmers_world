#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int key, data;
    struct node *next, *previous;
};

struct node *head = NULL, *tail = NULL, *next = NULL, *previous = NULL, *temp = NULL, *current = NULL;
int size = 0;

void link(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = NULL;
    link->previous = NULL;

    if (head == NULL)
    {
        link->next = link;
        link->previous = link;
        head = link;
        tail = link;
    }
    else
    {
        tail->next = link;
        link->next = head;
        link->previous = tail;
        tail = link;
        head->previous = tail;
    }

    size++;
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
                head == NULL;
                tail == NULL;
            }
            else
            {
                head = head->next;
                head->previous = tail;
            }

            size--;
            return current;
        }
        else if (tail->key == key)
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
                    next = current->next;
                    previous = current->previous;
                    current = next;
                    current->previous = previous;

                    size--;

                    return current;
                }

                current = current->next;
                next = current->next;
            }

            return NULL;
        }
    }
}

void sort()
{

    int k = size, temp;
    for (int i = 0; i < size - 1; i++, k--)
    {
        current = head;
        for (int j = 1; j < k; j++)
        {
            next = current->next;
            if (current->data > next->data)
            {
                temp = current->data;
                current->data = next->data;
                next->data = temp;

                temp = current->key;
                current->key = next->key;
                next->key = temp;
            }
        }
    }
}

void reverse()
{
    current = head;
    previous = tail;
    struct node *current_previous = NULL;

    if (head == NULL)
    {
        printf("List is empty. Reverse operation is not performed \n");
    }
    else
    {
            next = current->next;
            current->next = previous;
            previous = current;
            current->previous = next;
            
            current = next;

        while (current != head)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current->previous = next;
            
            current = next;
        }

        tail = head;
        head = previous;
        tail->next = head;
        head->previous = tail;
    }
}

void reversePrint(){
    
    current = tail;
    
    if(head == NULL)
    {
        printf("List is empty to show reverse print \n");
    }
    else
    {
        printf("Key: %d, Data:  %d, Next: %p, Previous: %p \n", current->key,current->data, current->next, current->previous);
        current = current->previous;
        while(current != tail){
            printf("Key: %d, Data:  %d, Next: %p, Previous: %p \n", current->key,current->data, current->next, current->previous);
        
            current= current->previous;
        }
    }
}

struct node* find(int key){
    current = head;
    
    if(head ==NULL)
        return NULL;
    else
    {
        if(tail->key == key)
        {
            return tail;
        }
        else
        {
            while(current != tail)
            {
                if(current->key == key)
                {
                    return current;
                }
                current = current->next;                      
            }
        }
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