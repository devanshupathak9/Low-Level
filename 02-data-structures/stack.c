// Stack = LIFO
// Last In, First Out

// Main operations:
// push  -> add element to top
// pop   -> remove element from top
// top -> points to / represents the top element

// Time complexity:
// push -> O(1)
// pop  -> O(1)
// peek -> O(1)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node *array;
    int size;
} Stack;

void init(Stack *stack) {
    stack->array = NULL;
    stack->size = 0;
}

void push(Stack *stack, int value) {
    Node *node = malloc(sizeof(Node));
    node->data = value;
    node->next = stack->array;
    stack->array = node;
    stack->size++;
}

void pop(Stack *stack) {
    if (stack->size == 0){
        fprintf(stderr, "Empty stack!!");
        return;
    }
    Node *node = stack->array;
    stack->array = stack->array->next;
    node->next = NULL;
    stack->size--;
    free(node);
}

int top(Stack *stack) {
    if (stack->size == 0){
        fprintf(stderr, "Empty stack!!");
        return -1;
    }
    return stack->array->data;
}

int size(Stack *stack) {
    return stack->size;
}

int main() {
    Stack stack;
    printf("%lu\n", sizeof(stack));
    init(&stack);

    push(&stack, 126);
    push(&stack, 23);
    push(&stack, 14);
    pop(&stack);
    printf("%d\n", top(&stack));
    push(&stack, 71);
    push(&stack, 56);
    pop(&stack);

    printf("%d\n", size(&stack));
    printf("%d\n", top(&stack));   
    return 0;
}



