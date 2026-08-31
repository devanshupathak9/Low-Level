#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **head, int data) {
    Node *node = malloc(sizeof( *node));
    node->data = data;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        Node *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
}

void print(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void reverseLinkedList(Node **head) {
    Node *curr = *head;
    Node *nxt = NULL;
    Node *prev = NULL;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    *head = prev;
}

int main() {
    Node *head = NULL;

    insert(&head, 6);
    insert(&head, 54);
    insert(&head, 12);
    insert(&head, 8);
    print(head);

    reverseLinkedList(&head);
    print(head);
}