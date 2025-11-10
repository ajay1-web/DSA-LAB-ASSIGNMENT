#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// Insert at beginning (simple insertion for testing)
void insertDLL(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// ✅ SIZE OF DOUBLY LINKED LIST
int sizeDLL() {
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display DLL (optional)
void displayDLL() {
    struct node *temp = head;
    printf("\nDLL : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insertDLL(10);
    insertDLL(20);
    insertDLL(30);

    displayDLL();
    printf("\nSize of Doubly Linked List = %d", sizeDLL());
}
