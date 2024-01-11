#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
    } else {
        stack->items[++(stack->top)] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1; 
    } else {
        return stack->items[(stack->top)--];
    }
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No element to peek.\n");
        return -1;
    } else {
        return stack->items[stack->top];
    }
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element of the stack: %d\n", peek(&myStack));

    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));

    printf("Top element of the stack: %d\n", peek(&myStack));

    return 0;
}

