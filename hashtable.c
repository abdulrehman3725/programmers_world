#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem
{
    int data;
    int key;
};

struct DataItem *hashArray[SIZE], *Item, *dummyItem;
int arraySize = 0;

int isFull()
{
    return arraySize == SIZE;
}

int hashCode(int key)
{
    return key % SIZE;
}

void insert(int key, int data)
{
    if (!isFull())
    {
        Item = (struct DataItem *)malloc(sizeof(struct DataItem));
        Item->data = data;
        Item->key = key;

        int hashIndex = hashCode(key);

        while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= 20;
        }

        hashArray[hashIndex] = Item;
        arraySize++;
    }
    else
    {
        printf("HashArray Is Full \n");
    }
}

struct DataItem *search(int key)
{
    int hashIndex = hashCode(key);
    int count = 0; //if we do not use count then the loop will iterate infinitely in case of key is not found

    while (hashArray[hashIndex] != NULL && count != SIZE)
    {
        if(hashArray[hashIndex]->key == key )
        {
            return hashArray[hashIndex];
        }

        hashIndex++;
        hashIndex %= 20;

        count++;
    }

    return NULL;
}

struct DataItem *delete(int key){

    int hashIndex = hashCode(key);
    int count = 0; //if we do not use count then the loop will iterate infinitely in case of key is not found
    
    while (hashArray[hashIndex] != NULL && count != SIZE)
    {
        if(hashArray[hashIndex]->key == key )
        {
            Item = hashArray[hashIndex];
            hashArray[hashIndex] = dummyItem;
            return Item;
        }

        hashIndex++;
        hashIndex %= 20;

        count++;
    }

    return NULL;
}

void display(){

    for(int i = 0 ; i < SIZE; i++)
    {
        if(hashArray[i] != NULL )
            printf("Key: %d , Data: %d \n", hashArray[i]->key, hashArray[i]->data);
        else
            printf("-- \n");
    }
}

int main()
{
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 

   insert(1, 10);
   insert(2, 20);
   insert(3, 30);
   insert(4, 45);
   insert(5, 54);
   insert(6, 62);
   insert(7, 71);
   insert(8, 88);
   insert(9, 97);
   insert(10, 20);
   insert(11, 70);
   insert(12, 80);
   insert(13, 25);
   insert(14, 44);
   insert(16, 32);
   insert(15, 11);
   insert(17, 78);
   insert(18, 97);
   insert(19, 11);
   insert(20, 78);
   insert(20, 78);

   display();
   Item = search(17);

   if(Item != NULL)
   {
        printf("Element Found key:%d , data:%d \n", Item->key, Item->data);
   }
   else
      printf("Element not found \n");

   delete(17);
   Item = search(17);

   if(Item != NULL) {
      printf("Element found: %d\n", Item->data);
   } else {
      printf("Element not found\n");
   }
}