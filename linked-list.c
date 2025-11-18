#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


int main(){

    struct node *head = NULL;

    struct node *n1, *n2, *n3;
    
    n1 = malloc(sizeof(struct node));
    n2 = malloc(sizeof(struct node));
    n3 = malloc(sizeof(struct node));

    head = n1;
    n1->data = 12;
    n1->next = n2;

    n2->data = 22;
    n2->next = n3;

    n3->data = 63;
    n3->next = NULL;

    struct node *curr = head;
    while (curr != NULL){
        printf("%d\n", curr->data);
        curr = curr->next;
    }

}