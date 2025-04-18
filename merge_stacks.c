//
// Created by maxxx on 18.04.2025.
//

#include "merge_stacks.h"
#include "stack.h"
#include <stdio.h>
#include <ctype.h>

Stack* inputDescendingStack() {
    printf("Enter the maximum stack size for descending stack: ");
    int max_size = 0;
    while (scanf("%d", &max_size) != 1 || max_size <= 0) {
        printf("Error: enter a positive integer\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    Stack* stack = createStack(max_size);
    if (!stack) {
        return NULL;
    }
    printf("Enter stack elements in descending order (only integers, press Enter twice to stop, or fill the stack):\n");
    int value;
    int is_first_char = 1;
    int last_value = 0;
    int is_first_element = 1;
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
            if (is_first_element || value <= last_value) {
                push(stack, value);
                last_value = value;
                is_first_element = 0;
                while (getchar() != '\n');
                is_first_char = 1;
            } else {
                printf("Error: value must be <= %d to maintain descending order\n", last_value);
                while (getchar() != '\n');
                is_first_char = 1;
            }
        } else {
            printf("Error: please enter a valid integer\n");
            while (getchar() != '\n');
            is_first_char = 1;
        }
    }
    return stack;
}

Stack* inputAscendingStack() {
    printf("Enter the maximum stack size for ascending stack: ");
    int max_size = 0;
    while (scanf("%d", &max_size) != 1 || max_size <= 0) {
        printf("Error: enter a positive integer\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    Stack* stack = createStack(max_size);
    if (!stack) {
        return NULL;
    }
    printf("Enter stack elements in ascending order (only integers, press Enter twice to stop, or fill the stack):\n");
    int value;
    int is_first_char = 1;
    int last_value = 0;
    int is_first_element = 1;
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
            if (is_first_element || value >= last_value) {
                push(stack, value);
                last_value = value;
                is_first_element = 0;
                while (getchar() != '\n');
                is_first_char = 1;
            } else {
                printf("Error: value must be >= %d to maintain ascending order\n", last_value);
                while (getchar() != '\n');
                is_first_char = 1;
            }
        } else {
            printf("Error: please enter a valid integer\n");
            while (getchar() != '\n');
            is_first_char = 1;
        }
    }
    return stack;
}

Stack* mergeStacksAscending(Stack* descending, Stack* ascending) {
    Stack* result = createStack(descending->max_size + ascending->max_size);
    if (!result) {
        return NULL;
    }

    Stack* temp_desc = createStack(descending->max_size);
    Stack* temp_asc = createStack(ascending->max_size);
    if (!temp_desc || !temp_asc) {
        destroyStack(result);
        destroyStack(temp_desc);
        destroyStack(temp_asc);
        return NULL;
    }

    while (!isEmpty(descending)) {
        push(temp_desc, pop(descending));
    }
    while (!isEmpty(ascending)) {
        push(temp_asc, pop(ascending));
    }

    while (!isEmpty(temp_desc) || !isEmpty(temp_asc)) {
        if (isEmpty(temp_asc)) {
            int value = pop(temp_desc);
            push(descending, value);
            push(result, value);
        } else if (isEmpty(temp_desc)) {
            int value = pop(temp_asc);
            push(ascending, value);
            push(result, value);
        } else {
            int desc_value = temp_desc->data[temp_desc->top];
            int asc_value = temp_asc->data[temp_asc->top];
            if (desc_value <= asc_value) {
                pop(temp_desc);
                push(descending, desc_value);
                push(result, desc_value);
            } else {
                pop(temp_asc);
                push(ascending, asc_value);
                push(result, asc_value);
            }
        }
    }

    destroyStack(temp_desc);
    destroyStack(temp_asc);
    return result;
}