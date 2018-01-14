#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

int array[MAX], size = 0, current = 0;

int get()
{
    return array[current];
}

void first(){
    current = 0;
}

void last(){
    current = size - 1;
}

void update(int data){
    array[current] = data;
}

int length(){
    return size;
}

void value(int no)
{
    if(size < MAX)
    {
        array[current] =  no;
        current++;
        size++;
    }
    else{
        return;
    }
}

void insert(int position, int data){

    if(position  > size)
        return;
    //last postion
    if((position) == size)
    {
        last();
        array[current] = data;
        return;
    }
    else
    {
        int temp = length() - 1;

        while( position <= temp ){
            array[temp + 1] = array[temp];
            temp--;
        }

        array[position] = data;
    }

    size++;
}

void find(int data){
    for(int i = 0; i < size; i++)
    {
        if(data == array[i])
        {
            current = i;
            break;
        }
    }
}

void delete(int data){
    if(size == 0)
        return;
    else
    {
        find(data);
        while( current < size){
            array[current] = array[current + 1];
            current = current + 1;  
        }
        
        size--;
    }
}

void display(){

    for(int i = 0; i < size; i++)
        printf("Value %d \n", array[i]);
}

void main(){

    int no;
    printf("Insert data in an array: \n");

    
    for(int i = 0; i < MAX - 1; i++)
    {
        printf("Enter %d value \n", i);
        value(i);
    }

    printf("\nList \n\n");
    display();

    insert(2,3);

    printf("\nList \n\n");
    display();

    delete(2);

    printf("\nList \n\n");
    display();
    
    delete(0);

    printf("\nList \n\n");
    display();
    
        delete(1);

    printf("\nList \n\n");
    display();
    
        delete(3);

    printf("\nList \n\n");
    display();
    
    
}
