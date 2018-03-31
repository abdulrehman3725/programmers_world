/* 
* Fibbonaci Concept & Source: https://www.tutorialspoint.com/data_structures_algorithms/fibonacci_series.htm
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int size = 0, current = 0, array[MAX];

void value(int no)
{
    if (size < MAX)
    {
        array[size] = no;
        size++;
    }
    else
        return;
}

int last()
{
    current = size - 1;
}

void insert(int position, int no)
{
    if (position > size)
        return;

    if (position == size)
    {
        last();
        array[current] = no;
    }
    else
    {
        int temp = size - 1;

        while (position <= temp)
        {
            array[temp + 1] = array[temp];
            temp--;
        }

        array[temp] = no;
    }
    size++;
}

void find(int no)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == no)
        {
            current = i;
            return;
        }
    }
}

void delete (int no)
{
    if (size == 0)
        return;
    else
    {
        find(no);
        while (current < size)
        {
            array[current] = array[current + 1];
            current++;
        }
        size--;
    }
}

void display(){

    for(int i = 0; i < size; i++)
        printf("Value %d \n", array[i]);
}

int main()
{
    int no;
    printf("Insert data in an array: \n");

    
    for(int i = 0; i < 1; i++)
    {
        printf("Enter %d value \n", i);
        value(i);
    }

    // printf("\nList \n\n");
    // display();

    // insert(2,3);

    // printf("\nList \n\n");
    // display();

    // delete(2);

    // printf("\nList \n\n");
    // display();
    
    delete(0);

    printf("\nList \n\n");
    display();
    
    //     delete(1);

    // printf("\nList \n\n");
    // display();
    
    //     delete(3);

    // printf("\nList \n\n");
    // display();   
    return 0;
}