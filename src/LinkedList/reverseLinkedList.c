#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **head, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        Node *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
}

void printll(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void reverseLL(Node **head) {
    Node *curr = *head, *prev = NULL, *nxt = NULL;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    *head = prev;
}

void freeNode(Node *head) {
    Node *curr = NULL;
    while (head) {
        curr = head;
        head = head->next;
        free(curr);
    }
}

int main() {
    Node *head = NULL;
    for (int i = 1; i < 17; i = i + 3) {
        insert(&head, i);
    }
    printll(head);
    reverseLL(&head);
    printll(head);
    freeNode(head);
    printll(head);
    return 1;
}