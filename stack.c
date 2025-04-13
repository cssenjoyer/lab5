//
// Created by maxxx on 13.04.2025.
//
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* createStack(int max_size) {
    if (max_size <= 0) {
        printf("Error: stack size must be greater than 0\n");
        return NULL;
    }
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Error: memory allocation for stack failed\n");
        return NULL;
    }
    stack->data = (int*)malloc(max_size * sizeof(int));
    if (!stack->data) {
        printf("Error: memory allocation for stack data failed\n");
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->max_size = max_size;
    return stack;
}

void destroyStack(Stack* stack) {
    if (stack) {
        if (stack->data) {
            free(stack->data);
        }
        free(stack);
    }
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->max_size - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Error: stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: stack is empty\n");
        return 0;
    }
    return stack->data[stack->top--];
}

int getSumToMin(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, sum is 0\n");
        return 0;
    }

    int min_value = stack->data[0];
    int min_index = 0;
    for (int i = 1; i <= stack->top; i++) {
        if (stack->data[i] < min_value) {
            min_value = stack->data[i];
            min_index = i;
        }
    }

    int sum = 0;
    for (int i = 0; i <= min_index; i++) {
        sum += stack->data[i];
    }
    return sum;
}