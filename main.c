//
// Created by maxxx on 12.04.2025.
//
// в программе реализовывается стек с подсчетом суммы элементов от начала стека до мин элемента
//gcc -o stack.exe main.c stack.c input.c
#include "stack.h"
#include "input.h"
#include <stdio.h>

int main() {
    int max_size = inputStackSize();
    Stack* stack = createStack(max_size);
    if (!stack) {
        return 1;
    }
    inputStackElements(stack);
    int sum = getSumToMin(stack);
    printf("Sum of elements up to the minimum: %d\n", sum);
    destroyStack(stack);
    return 0;
}