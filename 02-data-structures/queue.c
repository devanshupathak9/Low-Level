// Queue = FIFO (First In, First Out)
// Main operations:
// enqueue -> push element
// pop -> pop element
// peek    -> see front element

// Important pointers:
// front -> points to the first element
// rear  -> points to the last element

// Time complexity:
// enqueue -> O(1)
// pop -> O(1)
// peek -> O(1)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

void init(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

void push(Queue *queue, int element) {
    Node *node = malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;
    if (queue->size == 0) {
        queue->front = node;
        queue->rear = node;
        queue->size = 1;
        return;  
    }
    queue->rear->next = node;
    queue->rear = node;
    queue->size += 1;
}

void pop(Queue *queue) {
    if (queue->size == 0) {
        fprintf(stderr, "Empty queue!!");
        return;
    }
    Node *node = queue->front;
    queue->front = queue->front->next;
    node->next = NULL;
    queue->size--;
    if (queue->size == 0) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;   
    }
    free(node);
}

int front(Queue *queue) {
    if (queue->size == 0) {
        fprintf(stderr, "Empty queue!!");
        return -1;
    }
    return queue->front->data;
}

int size(Queue *queue) {
    return queue->size;
}

int main() {
    Queue queue;

    init(&queue);
    push(&queue, 54);
    pop(&queue);
    push(&queue, 5);
    push(&queue, 534);
    push(&queue, 4);
    pop(&queue);

    printf("%d\n", front(&queue));
    printf("%d\n", size(&queue));
    return 0;
}