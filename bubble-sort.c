#include <stdio.h>
#define SIZE 5
int list[SIZE] = {4,3,2,1,0};

void sort()
{
    int temp;
    for(int i = 0; i < SIZE - 1;  i++)
    {
        for(int j = 0; j < SIZE - (i+1); j++)
        {
            if(list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
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