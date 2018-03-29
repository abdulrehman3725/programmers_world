/* 
* Fibbonaci Concept & Source: https://www.tutorialspoint.com/data_structures_algorithms/fibonacci_series.htm
*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int fibbonaci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        return (fibbonaci(n - 1) + fibbonaci(n - 2));
    }
}
int main()
{
    int n = 8;
    printf("Factorial of %d is %d \n", n, factorial(n));

    int n1 = 0, n2 = 1, temp;

    //recursive method
    printf("\n RECURSIVE METHOD \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibbonaci(i));
    }

    //non recursive method
    printf("\n NON RECURSIVE METHOD \n");
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("0 ");
        }
        else if (i == 1)
        {
            printf("1 ");
        }
        else
        {
            printf("%d ", n1 + n2);
            n2 = n1 + n2;
            n1 = n2 - n1;
        }
    }

    return 0;
}