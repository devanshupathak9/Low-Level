#include <stdio.h>
#define STACK_SIZE 20

typedef struct Stack {
    int data[STACK_SIZE];
    int top;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
}

void insert(Stack *stack, int value) {
    if (stack->top + 1 == STACK_SIZE) {
        fprintf(stderr, "Stack size full!!");
        return;
    }
    stack->data[stack->top + 1] = value;
    stack->top++;
}

void pop(Stack *stack) {
    printf("%p\n", stack);
    if (stack->top == -1) {
        fprintf(stderr, "Empty Stack!");
        return;
    }
    stack->top--;
}

int size(Stack *stack) {
    return stack->top + 1;
}

int top(Stack *stack) {
    if (stack->top == -1) {
        fprintf(stderr, "Empty Stack!");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    printf("%lu\n", sizeof(stack));
    printf("%p\n", (void *)&stack);
    init(&stack);

    insert(&stack, 12);
    insert(&stack, 43);
    pop(&stack);
    printf("%d\n", top(&stack));

    insert(&stack, 65);
    insert(&stack, 14);
    insert(&stack, 45);
    pop(&stack);
    printf("%d\n", top(&stack));
    return 0;
}