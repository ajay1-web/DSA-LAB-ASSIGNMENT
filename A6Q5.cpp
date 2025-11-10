#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to check if list is circular
int isCircular(struct node *head) {
    struct node *temp = head;

    if (head == NULL)
        return 0; // Empty list is not circular

    temp = temp->next;

    while (temp != NULL && temp != head)
        temp = temp->next;

    if (temp == head)
        return 1;  // circular
    else
        return 0;  // not circular
}

// Create a simple linked list (manual for demonstration)
struct node* createNode(int val) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct node *head = createNode(2);
    head->next = createNode(4);
    head->next->next = createNode(6);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(5);

    // Make it circular
    head->next->next->next->next->next = head;

    if (isCircular(head))
        printf("True (Linked list is circular)");
    else
        printf("False (Linked list is not circular)");

    return 0;
}
