#include <stdio.h>

#define SIZE 10

int list[SIZE] = {10,9,8,7,6,5,4,3,2,1};

void sort(){

    int insertValue;
    int location;

    for(int i = 1; i < SIZE ; i++)
    {
        insertValue = list[i];
        location = i;

        while( location > 0 && list[location - 1] > insertValue)
        {
            list[location] = list[location - 1];
            location--;
        }

        if(location != i)
        {
            list[location] = insertValue;
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