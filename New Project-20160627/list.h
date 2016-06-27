#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int val;
    struct node * next;
};

struct node * createNode(int val);
void addNode(struct node ** head, int val);
int getValue(struct node * head, int index);
int getMax(struct node * head);
int getMin(struct node * head);
int getSize(struct node * head);
void printList(struct node * head);
void sortList(struct node ** head);
