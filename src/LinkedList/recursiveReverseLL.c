#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node **head, int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        Node *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
}

void printll(Node *curr) {
    while (curr) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

Node *reverseLL(Node *curr) {
    if (curr == NULL || curr->next == NULL) return curr;
    Node *revNode = reverseLL(curr->next);
    curr->next->next = curr;
    curr->next = NULL;
    return revNode;
}

int main() {
    Node *head = NULL;
    for (int i = 0; i < 20; i = i + 2) {
        insert(&head, i);
    }
    printll(head);
    Node *reverseHead = reverseLL(head);
    printll(reverseHead);
    return 0;
}