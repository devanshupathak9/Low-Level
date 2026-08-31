#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insert(Node **head, int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    Node *curr = *head;
    if (curr) {
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    } else {
        *head = node;
    }
}

void print(Node *head) {
    while (head) {
        printf("%d->", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    insert(&head, 43);
    insert(&head, 53);
    insert(&head, 12);
    insert(&head, 98);
    insert(&head, 14);
    insert(&head, 45);
    print(head);
    return 0;
}