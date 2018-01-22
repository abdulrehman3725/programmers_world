#include <stdio.h>
#define MAX 11

int a[11] = {10,9,8,7,6,5,4,3,2,1,0};

void sort(){
    int valueToInsert, inner,outer, interval = 1, elements = MAX;

    while( interval <= (elements/3))
    {
        interval = (interval * 3) + 1;
    }

    while(interval > 0)
    {
        for(outer = interval; outer < MAX; outer++)
        {
            valueToInsert = a[outer];
            inner = outer;

            while( inner >= (interval - 1) && a[inner - interval] > valueToInsert)
            {
                a[inner] = a[inner - interval];
                inner -= interval;
            }

            a[inner] = valueToInsert;
        }

        interval = (interval-1)/3;
    }
}
int main() { 
   int i;

   printf("List before sorting\n");
   
   for(i = 0; i < MAX; i++)
      printf("%d ", a[i]);

   sort(0, MAX);

   printf("\nList after sorting\n");
   
   for(i = 0; i < MAX; i++)
      printf("%d ", a[i]);
}
