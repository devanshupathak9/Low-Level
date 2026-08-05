#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* insert(Node *head, int value) {
    if (head == NULL) {
        Node *node = (Node *)malloc(sizeof(Node));
        if (node == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        node->next = NULL;
        node->data = value;
        return node;
    }
    if (head->next == NULL) {
        head->next = (Node *)malloc(sizeof(Node));
        head->next->data = value;
        head->next->next = NULL;
    } else {
        head->next = insert(head->next, value);
    }
    return head;
}

void printll(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    for (int i = 1; i<10; i++) {
        head = insert(head, i);
    }
    printll(head);
    freeList(head);
    return 0;
}