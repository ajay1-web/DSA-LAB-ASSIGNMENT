#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// INSERT (at beginning)
void insert(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// DELETE node
void deleteNode(int val) {
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->data == val) {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("\nValue not found");
}

// SEARCH node
void search(int val) {
    struct node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == val) {
            printf("\nFound at Position %d", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("\nNot Found");
}

// DISPLAY list
void display() {
    struct node *temp = head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Search  4.Display  5.Exit → ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val); insert(val); break;
            case 2: printf("Enter value to delete: "); scanf("%d", &val); deleteNode(val); break;
            case 3: printf("Enter value to search: "); scanf("%d", &val); search(val); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
}
