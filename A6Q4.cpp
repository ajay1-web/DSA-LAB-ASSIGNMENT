#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// Insert at end
void insert(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// ✅ Check palindrome
int isPalindrome() {
    struct node *left = head;
    struct node *right = head;

    if (head == NULL)
        return 1;  // empty list = palindrome

    // Move right to last node
    while (right->next != NULL)
        right = right->next;

    // Compare data from start & end simultaneously
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return 0;  // not palindrome

        left = left->next;
        right = right->prev;
    }

    return 1;  // palindrome
}

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
        printf("\n1.Insert  2.Display  3.Check Palindrome  4.Exit → ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                display();
                break;

            case 3:
                if (isPalindrome())
                    printf("\nPalindrome");
                else
                    printf("\nNot Palindrome");
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }
    }
}
