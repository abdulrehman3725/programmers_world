/*
 * C Program to Implement a Heap & provide Insertion & Deletion Operation 
 * Source: 
 * Concept: https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm
 * Source Code: http://www.sanfoundry.com/c-program-heap-insertion-deletion-operation/
 * Following is Max Heap Implementation, same case is for min heap but in opposite manner.
 * To understand concept for the line no 107, you must refer to the example in heap_example.txt file.
 */
#include <stdio.h>
#include <stdlib.h>

int array[100], n;

void insert(int num, int location)
{
    int parent;

    while (location > 0)
    {
        //for parent node location
        parent = (location - 1) / 2;

        if (num <= array[parent])
        {
            array[location] = num;
            return;
        }

        array[location] = array[parent];
        array[parent] = num;
        location = parent;
    }

    array[0] = num;
}

void display()
{
    int i;
    if (n == 0)
    {
        printf("Heap is empty \n");
        return;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
} /*End of display()*/

void delete (int num)
{
    int left, right, i, temp, parent;

    for (i = 0; i < n; i++)
    {
        if (array[i] == num)
            break;
    }

    if( num != array[i])
    {
        printf("Number not found ! \n");
        return;
    }

    parent = (i - 1)/2;
    array[i] = array[n-1]; /* insert final number to the deleted location */
    n = n-1;

    /* invoke insert function when item at i location is greater than parent */
    if (array[i] > array[parent])
    {
        insert(array[i], i);
        return;
    }

    left = i * 2 + 1;  /*left child of i */
    right = i * 2 + 2; /*right child of i */

    while (right < n) /*incremented value for right should be less than size of items inserted*/
    {
        /*if replaced item at deleted location is greater than both left and right child then no need 
        to iterate*/
        if (array[i] >= array[left] && array[i] >= array[right])
            return;
        /*if left child is greater than equal to right child than it should be in place of parent 
        i.e at i location */
        else if (array[right] <= array[left])
        {
            temp = array[left];
            array[left] = array[i];
            array[i] = temp;
            i = left;
        }
        else
        {
            temp = array[right];
            array[right] = array[i];
            array[i] = temp;
            i = right;
        }
        left = i * 2 + 1;
        right = i * 2 + 2;
    }

    /* if we do not do following than the smaller value will be at upper positions. */
    if (array[left] && array[i] < array[left])
    {
        temp = array[left];
        array[left] = array[i];
        array[i] = temp;
    }
}
int main()
{
    int choice, num;
    n = 0; /*Represents number of nodes in the heap*/
    while (1)
    {
        printf("1.Insert the element \n");
        printf("2.Delete the element \n");
        printf("3.Display all elements \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted to the list : ");
            scanf("%d", &num);
            insert(num, n);
            n = n + 1;
            break;
        case 2:
            printf("Enter the elements to be deleted from the list: ");
            scanf("%d", &num);
            delete (num);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice \n");
        }
    }
}