#include "list.h"

struct node * createNode(int val) {
    struct node * myNode = malloc(sizeof(struct node));
    myNode->val = val;
    myNode->next = NULL;
    return myNode;
}

void addNode(struct node ** head, int val) {
    struct node * current;
    
    if ((*head) == NULL) {
        (*head) = createNode(val);
    }
    else {
        current = (* head);
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(val);
    }
}

int getValue(struct node * head, int index) {
    struct node * current = head;
    int count = 0;
    while((current != NULL) && (count < index)) {
        current = current->next;
        count++;
    }
    if((current != NULL) && (count == index)) {
        return current->val;
    }
    else {
        return -1;
    }
}

int getMax(struct node * head) {
    struct node * current = head;
    int max = INT_MIN;
    
    while(current != NULL) {
        if (current->val > max) {
            max = current->val;
        }
        current = current->next;
    }
    
    return max;
}

int getMin(struct node * head) {
    struct node * current = head;
    int min = INT_MAX;
    
    while(current != NULL) {
        if (current->val < min) {
            min = current->val;
        }
        current = current->next;
    }
    
    return min;
}

int getSize(struct node * head) {
    struct node * current = head;
    
    if (current == 0) {
        return 0;
    }
    else {
        int size = 0;
        while(current != NULL) {
            current = current->next;
            size++;
        }
        return size;
    }
}

void printList(struct node * head) {
    struct node * current = head;
    int count = 0;
    printf("list = [");
    if (current != NULL) {
        printf("(%d, %d)", count, current->val);
        while(current->next != NULL) {
            current = current->next;
            count++;
            printf(", (%d, %d)", count, current->val);
        }
    }
    printf("]\n");
}

void sortList(struct node ** head) {
    int size = getSize((*head));
    int count = 0;
    
    while(size > 1) {
        int i;
        struct node * current = (* head);
        for (int i=0; i<size-1; i++) {
            if (current->val > current->next->val) {
                int val = current->next->val;
                current->next->val = current->val;
                current->val = val;
            }
            current = current->next;
            count++;
        }
        size--;
    }
    printf("Number of comparisons = %d\n", count);
}
