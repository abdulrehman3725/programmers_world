#include <stdio.h>

#define SIZE 10

int a[SIZE] = {10,9,8,7,6,5,4,3,2,1};
int b[SIZE];

void merging(int low, int mid, int high)
{
    int l1,l2,i;

    for(l1 = low, l2 = mid+1, i = low; l1 <= mid && l2 <= high; i++)
    {
        if(a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }

    while(l1 <= mid)
    {
        b[i++] = a[l1++];
    }

    while(l2 <= high)
    {
        b[i++] = a[l2++];
    }

    for(i = low; i<=high; i++)
        a[i] = b[i];
}

void sort(int low , int high){
    
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid+1, high);
        merging(low, mid, high);
    }
    else
        return;
}

void display(){
    printf("\n\n ====================== \n\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("list[%d] = %d \n",i, a[i]);
    }
}

int main(){

    printf("LIST BEFORE SORTING \n \n");
    display();
    
    sort(0, SIZE-1);

    printf("LIST AFTER SORTING \n \n");
    display();
    return 0;
}