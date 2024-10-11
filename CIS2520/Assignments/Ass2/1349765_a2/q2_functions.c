/*
Name: Soohwan Kim
Student ID: 1349765
Assignment 2, Question 2
Date : 10/10/2024
*/

#include "q2.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Pushes a new value onto the stack.
 * 
 * @param stack Pointer to the pointer of the stack's head.
 * @param value The value to be added to the stack.
 */
void push(Operand** stack, double value) {
    Operand* newOperand = (Operand*)malloc(sizeof(Operand));
    newOperand->value = value;
    newOperand->next = *stack;
    *stack = newOperand;
}

/**
 * Pops the top value from the stack and returns it.
 *
 * @param stack Pointer to the pointer of the stack's head.
 * @return The value that was at the top of the stack.
 */
double pop(Operand** stack) {
    if (*stack == NULL) {
        printf("The stack is empty.\n");
        return 1;
    }

    Operand* temp = *stack;
    double value = temp->value;
    *stack = temp->next;
    free(temp);

    return value;
}

/**
 * Prints all values in the stack.
 *
 * @param stack Pointer to the stack's head.
 */
void print(Operand* stack) {
    Operand* current = stack;

    while (current != NULL) {
        // If the value is an integer, print as an integer, otherwise prints the value with two decimal points
        if (current->value == (int)current->value) {
            printf(" => %.0f\n", current->value);
        }
        else {
            printf(" => %.2f\n", current->value);
        }
        current = current->next;
    }
    return;
}