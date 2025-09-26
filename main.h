#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;


node* insert_front(node *root, int item);

node* reverse(node* head);

void insertToPlace(node* list, int val, int place);

#endif
