#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

node* insert_front(node *root, int item) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = item;
    temp->next = NULL;

    if(root == NULL) {
        root = temp;
    } else {
        temp->next = root;
        root = temp;
    }
    return root;
}

node* reverse(node* head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    node* main_list = head;
    node* reversed_list = head;

    main_list = main_list->next;
    reversed_list->next = NULL;

    while(main_list != NULL) {

        node* temp = main_list;
        
        main_list = main_list->next;
        
        temp->next = reversed_list;
        
        reversed_list = temp;
    }
    
    return reversed_list;
}


void insertToPlace(node* head, int val, int place) {

    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    node* current = head;
    int count = 1;

    while(current->next != NULL && count < place - 1) {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void display(node* t) {
    printf("\nPrinting your linked list.......");
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    node *root = NULL;
    int ch, ele, place;

    while(1) {
        printf("\nMenu: 1. insert at front, 2. reverse list 3. Insert to place 0. exit: ");
        scanf("%d", &ch);

        if(ch == 0) {
            printf("\nGOOD BYE>>>>\n");
            break;
        }
        if(ch == 1) {
            printf("\nEnter data (an integer): ");
            scanf("%d", &ele);
            root = insert_front(root, ele);
            display(root);
        }
        if(ch == 2) {
            root = reverse(root);
            printf("\nList reversed.");
            display(root);
        }
        if(ch == 3) {
            printf("\nEnter data (an integer) and place (>1) separated by space: ");
            scanf("%d %d", &ele, &place);
            if(place <= 1) {
                 printf("\nList is empty or place is not valid");
            } else {
                 insertToPlace(root, ele, place);
            }
            display(root);
        }
    }
    return 0;
}
