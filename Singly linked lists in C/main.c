#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};

void printList(struct node * head) {
    int counter = 0;
    while (head != NULL) {
        if (counter>0) {
            printf(", ");
        }
        printf("(%d : %d)", counter, head->val);
        head = head->next;
        counter++;
    }
    printf("\n");
}

struct node * addNode(struct node * head, int val) {
    struct node * current = head;
    if (head == NULL) {
        head = malloc(sizeof(struct node));
        head->val = val;
        head->next = NULL;
    }
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = malloc(sizeof(struct node));
        current->next->val = val;
        current->next->next = NULL;
    }
    return head;
}

void addNode2(struct node ** head, int val) {
    struct node * current = (*head);
    if ((*head) == NULL) {
        (*head) = malloc(sizeof(struct node));
        (*head)->val = val;
        (*head)->next = NULL;
    }
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = malloc(sizeof(struct node));
        current->next->val = val;
        current->next->next = NULL;
    }
}

void deleteNode(struct node ** head, int id) {
    struct node * current = (*head);
    struct node * prev = NULL;
    
    int counter = 0;
    if (head != NULL) {
        while((counter < id) && (current->next != NULL)) {
            counter++;
            prev = current;
            current = current->next;
        }
        if (counter == id) {
            // Removing the 1st node of list
            if (prev == NULL) {
                (*head) = current->next;
                free(current);
            }
            // Removing a node that is in middle of end of list
            else {
                prev->next = current->next;
                free(current);
            }
        }
    }
}

int main()
{
    struct node * list = NULL;
    list = addNode(list, 10);
    list = addNode(list, 20);
    printList(list);
    addNode2(&list, 30);
    addNode2(&list, 40);
    addNode2(&list, 50);
    printList(list);
    deleteNode(&list, 0);
    printList(list);
    deleteNode(&list, 3);
    printList(list);
    deleteNode(&list, 1);
    printList(list);
    return 0;
}

