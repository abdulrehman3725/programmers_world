#include <stdio.h>

#define MAX 8

int list[MAX] = {1,5,10,11,32,55,68,85};

int find(int no)
{
    int low = 0;
    int high = MAX-1;
    int mid = -1;
    int index = -1;
    int comparisions = 1;

    while(low <= high)
    {
        comparisions++;
        
        /* To understand interpolation formula visit:
        https://study.com/academy/lesson/interpolation-in-statistics-definition-formula-example.html 
        */
        mid = low + (((high - low) / (list[high] - list[low])) * (no - list[low]));

        if(list[mid] == no)
        {
            index = mid;
            printf("Total Comparisions: %d \n",comparisions);
            break;
        }
        else
        {
            if(list[mid] < no)
                low = mid + 1;
            else 
                high = mid - 1;
        }        
    }

    return index;
}


int main(){
    int index = find(32);

    if(index != -1)
        printf("Value found at location: %d",(index+1));
    else
        printf("Value was not found");

    return 0;

    
}