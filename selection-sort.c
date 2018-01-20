#include <stdio.h>

#define SIZE 10

int list[SIZE] = {0,3,2,1,4,9,8,7,6,6};

void sort(){
    
    int temp, min;

    for(int i = 0; i < SIZE - 1; i++)
    {
        min = i;

        for(int j= i+1; j < SIZE; j++)
        {
            if(list[j]<list[min])
                min = j;
        }

        if(min != i)
        {
            temp = list[i];
            list[i] = list[min]; 
            list[min] = temp;
        }
    }
}

void display(){
    printf("\n\n ====================== \n\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("list[%d] = %d \n",i, list[i]);
    }
}

int main(){
    display();
    sort();
    display();

    return 0;
}