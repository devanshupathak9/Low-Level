#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node **head, int data) {
    Node *node = (Node* )malloc(sizeof(Node));
    node->data = data, node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        Node *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
}

Node* recursiveReverse(Node* head) {
    if (head == NULL || head->next == NULL) return head;
    Node *newHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;

    // if (head == NULL || head->next == NULL) return head;
    // Node *curr = recursiveReverse(head->next);
    // head->next = NULL;
    // Node *currNode = curr;
    // while (currNode->next) {
    //     currNode = currNode->next;
    // }
    // currNode->next = head;
    // return curr;
}

void printll(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
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
    for (int i = 1; i < 27; i = i + 4) insert(&head, i);
    printll(head);
    head = recursiveReverse(head);
    printll(head);
    freeNode(head);
    return 0;
}