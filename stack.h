//
// Created by maxxx on 12.04.2025.
//

#ifndef UNTITLED7_STACK_H
#define UNTITLED7_STACK_H

#ifndef STACK_H
#define STACK_H

typedef struct {
    int* data;
    int top;
    int max_size;
} Stack;

Stack* createStack(int max_size);
void destroyStack(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int getSumToMin(Stack* stack);

#endif

#endif //UNTITLED7_STACK_H
