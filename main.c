//
// Created by maxxx on 13.04.2025.
//
#include "stack.h"
#include <stdio.h>

int main() {
    int max_size;
    printf("Enter the maximum stack size: ");
    if (scanf("%d", &max_size) != 1 || max_size <= 0) {
        printf("Error: enter a positive integer\n");
        return 1;
    }

    Stack* stack = createStack(max_size);
    if (!stack) {
        return 1;
    }

    printf("Enter stack elements (input stops when stack is full or non-numeric value is entered):\n");
    int value;
    while (scanf("%d", &value) == 1 && !isFull(stack)) {
        push(stack, value);
    }

    while (getchar() != '\n');

    int sum = getSumToMin(stack);
    printf("Sum of elements up to the minimum: %d\n", sum);

    destroyStack(stack);
    return 0;
}