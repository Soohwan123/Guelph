/*
Name: Soohwan Kim
Student ID: 1349765
Assignment 2, Question 2
Date : 10/10/2024
*/

#include "q2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
    // Pointer to the stack
    Operand* stack = NULL;
    // Operands have to be 1 more than operators so count this to validate the input
    int operand_count = 0;
    int operator_count = 0;

    // Check if the arguments are valid
    if (argc != 2) {
        printf("Error occured during execution(Incorrect Input).");
        return 1;
    }

    // Loop through the second command line argument, containing the operands and the numbers
    for (int i = 0; i < strlen(argv[1]); ++i) {
        char ch = argv[1][i];

        // Check if the char is a numeric value or an operator
        if (isdigit(ch)) {
            // Convert char to double
            double value = ch - '0';
            push(&stack, value); 
            operand_count++;
        }
        else if (stack == NULL || stack->next == NULL) {
            printf("Error - Not enough values in expression.\n");
            return 1;
        }
        else {
            operator_count++;

            // Check if there are enough operands for the operation
            if (operand_count < 2) {
                printf("Error - Not enough operands for operator '%c'.\n", ch);
                return 1;
            }

            double right = pop(&stack);
            double left = pop(&stack);
            double result;

            switch (ch) {
                case '+':
                    result = left + right;                    
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    if (right == 0) {
                        printf("Error - You can't divide by zero.\n");
                        return 1;
                    }
                    else {
                        result = left / right;
                    }

                    break;
                default:
                    printf("Error - '%c' is an invalid character.\n", ch);
                    return 1;
            }

            push(&stack, result);
        }
    }

    // Validating the notation
    if (operand_count - operator_count != 1) {
        printf("Error - Invalid postfix expression.\n");
        return 1;
    }

    // Print the last value
    printf(argv[1]);
    print(stack);
    // free the memory of stack
    free(stack);

    return 0;
}