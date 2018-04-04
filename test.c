#include <stdio.h>
#include <stdlib.h>

#define MAX 5

    int array[MAX] = {5,3,1,2,4};
    int array2[MAX];

    void merging(int low, int mid, int high)
    {
        int l1, l2, i;

        for(l1 = low, l2 = mid+1, i = low; l1 <= mid && l2 <= high; i++)
        {
            if(array[l1]<=array[l2])
                array2[i] = array[l1++];
            else
                array2[i] = array[l2++];
        }
        
        while(l1 <= mid)
        {
            array2[i++] = array[l1++]; 
        }

        while(l2 <= high)
        {
            array2[i++] = array[l2++]; 
        }

        for(int j = low; j<=high;j++)
            array[j] = array2[j];    
    }

    void sort(int low, int high)
    {
        int mid;

        if(low<high)
        {
            mid = (low+high)/2;
            sort(low,mid);
            sort(mid+1, high);
            merging(low,mid,high);
        }
        else 
            return;
    }

int main()
{
    printf("Before sorted \n");
    for(int i=0; i < 5; i++)
    {
        printf("%d ",array[i]);
    }

    sort(0, MAX-1);

    printf(" \n After sorted \n");
    for(int j=0; j < 5; j++)
    {
        printf("%d",array[j]);
    }
}