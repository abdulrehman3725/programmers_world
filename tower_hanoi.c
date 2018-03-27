/*
* Concept: https://www.tutorialspoint.com/data_structures_algorithms/tower_of_hanoi.htm
* Source: https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
* To understand the code first for 2 disks only and do it yourself without seeing the source code!
*/

#include <stdlib.h>
#include <stdio.h>

void towerOfHanoi(int n, char s, char d, char a)
{
    if(n == 1)
    {
        printf("Disk %d is moved from %c to %c \n", n, s, d);
        return;
    }
    else
    {
        towerOfHanoi(n-1,s,a,d);
        printf("Disk %d is moved from %c to %c \n", n, s, d);
        towerOfHanoi(n-1,a,d,s);
    }

}

void main(){

    int n = 3;

    towerOfHanoi(n,'S','D','A');
}