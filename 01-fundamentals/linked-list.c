#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;


void insert(Node **head, int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    if (*head) {
        Node *curr = *head;
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
        printf("%d ", head->value);
        head = head->next;
    } 
    printf("\n");
}

int main() {
    Node *head = NULL;
    insert(&head, 5);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 12);
    print(head);
    return 0;
}