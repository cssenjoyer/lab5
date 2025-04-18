//
// Created by maxxx on 12.04.2025.
//
// в программе реализовывается стек с подсчетом суммы элементов от начала стека до мин элемента
//gcc -o stack.exe main.c stack.c input.c merge_stacks.c
#include "stack.h"
#include "input.h"
#include "merge_stacks.h"
#include <stdio.h>

int main() {
    Stack* stack = inputStackElements();
    printf("Sum of elements up to the minimum: %d\n", getSumToMin(stack));
    destroyStack(stack);

    printf("\nCreating two new stacks for merging...\n");
    Stack* descending = inputDescendingStack();
    Stack* ascending = inputAscendingStack();
    Stack* merged = mergeStacksAscending(descending, ascending);
    printf("Merged stack in ascending order:\n");
    while (!isEmpty(merged)) {
        printf("%d ", pop(merged));
    }
    printf("\n");

    destroyStack(descending);
    destroyStack(ascending);
    destroyStack(merged);
    return 0;
}