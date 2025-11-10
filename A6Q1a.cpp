#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;  // make circular
    }
    else {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

// DELETE node
void deleteNode(int val) {
    if (head == NULL) return;

    struct node *temp = head, *prev = NULL;

    // delete head node
    if (head->data == val) {
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        
        // only one node in list
        if (head == head->next) {
            free(head);
            head = NULL;
            return;
        }

        free(head);
        head = temp->next;
        return;
    }

    temp = head;
    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == val) {
            prev->next = temp->next;
            free(temp);
            return;
        }
    } while (temp != head);
}

void search(int val) {
    struct node *temp = head;
    int pos = 1;

    if (head == NULL) return;

    do {
        if (temp->data == val) {
            printf("\nFound at Position %d", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("\nNot Found");
}

void display() {
    if (head == NULL) {
        printf("\nEmpty List\n");
        return;
    }

    struct node *temp = head;
    printf("\nList : ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
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
