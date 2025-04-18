//
// Created by maxxx on 12.04.2025.
//
#include "input.h"
#include <stdio.h>
#include <ctype.h>

int inputStackSize() {
    int size;
    while (1) {
        printf("Enter the maximum stack size: ");
        if (scanf("%d", &size) == 1 && size > 0) {
            while (getchar() != '\n');
            return size;
        }
        printf("Error: enter a positive integer\n");
        while (getchar() != '\n');
    }
}

Stack* inputStackElements() {
    int max_size = inputStackSize();
    Stack* stack = createStack(max_size);
    if (!stack) {
        return NULL;
    }
    printf("Enter stack elements (only integers, press Enter twice to stop, or fill the stack):\n");
    int value;
    int is_first_char = 1;
    while (!isFull(stack)) {
        int c;
        if (is_first_char) {
            c = getchar();
            if (c == '\n') {
                break;
            } else {
                ungetc(c, stdin);
            }
            is_first_char = 0;
        }
        if (scanf("%d", &value) == 1) {
            push(stack, value);
            while (getchar() != '\n');
            is_first_char = 1;
        } else {
            printf("Error: please enter a valid integer\n");
            while (getchar() != '\n');
            is_first_char = 1;
        }
    }
    return stack;
}