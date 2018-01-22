#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int a[MAX] = {10,8,5,3,2,1,4,6,9,7};

void swap(int val1, int val2)
{
    int temp = a[val1];
    a[val1] = a[val2];
    a[val2] = temp; 
}

int partition(int left, int right, int pivot)
{
    int leftPointer =left - 1;
    int rightPointer = right;

    while(true)
    {
        while(a[++leftPointer] < pivot){}

        while(rightPointer > 0 && a[--rightPointer] > pivot){}

        if(leftPointer >= rightPointer)
            break;
        else
           swap(leftPointer, rightPointer);
    }

    swap(leftPointer, right);
    return leftPointer;
}

void quicksort(int left, int right)
{
    if(right-left <= 0)
        return;
    else
    {
        int pivot = a[right];
        int partitionPoint = partition(left,right,pivot);
        quicksort(left, partitionPoint-1);
        quicksort(partitionPoint+1, right);
    }

}
int main(){

    printf("LIST BEFORE SORTING \n\n");
    for(int i = 0; i < MAX; i++)
        printf("%d,  ",a[i]);

    quicksort(0, MAX-1);

    printf("\n\n LIST AFTER SORTING \n\n");
    for(int i = 0; i < MAX; i++)
        printf("%d,  ",a[i]);
}