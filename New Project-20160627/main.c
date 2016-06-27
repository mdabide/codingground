// To compile: gcc -I ./ -c *.c ; gcc -o main *.o 
// To run pgm: ./main

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main()
{
    struct node * list = NULL;
    
    int i, n=10;
    time_t t;
    
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    
    for(i=0; i<n; i++) {
        addNode(&list, rand() % 50);
    }
    printList(list);
    printf("list[0]=%d\n", getValue(list, 0));
    printf("list[9]=%d\n", getValue(list, 9));
    printf("list[10]=%d\n", getValue(list, 10));
    printf("size=%d\n", getSize(list));
    printf("min=%d\n", getMin(list));
    printf("max=%d\n", getMax(list));
    sortList(&list);
    printList(list);

    return 0;
}

