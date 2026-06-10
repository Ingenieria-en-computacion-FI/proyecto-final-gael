#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

Stack* stack_create() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void stack_push(Stack* stack, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->next = stack->top;

    stack->top = newNode;
}

int stack_pop(Stack* stack) {
    if (stack->top == NULL)
        return -1;

    struct Node* temp = stack->top;

    int value = temp->value;

    stack->top = temp->next;

    free(temp);

    return value;
}

int stack_peek(Stack* stack) {
    if (stack->top == NULL)
        return -1;

    return stack->top->value;
}

int stack_is_empty(Stack* stack) {
    return stack->top == NULL;
}

void stack_destroy(Stack* stack) {
    while (!stack_is_empty(stack))
        stack_pop(stack);

    free(stack);
}
