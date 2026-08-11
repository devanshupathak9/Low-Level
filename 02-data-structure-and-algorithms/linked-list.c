#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


void insert(Node **head, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    printf("%p\n", head);
    printf("%p\n", *head);
    printf("------------\n");
    Node *curr = *head;
    if (*head) {
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
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    printf("%p-->\n", head);

    insert(&head, 43);
    insert(&head, 53);
    insert(&head, 12);
    insert(&head, 98);
    insert(&head, 14);
    insert(&head, 45);
    print(head);
    return 0;
}