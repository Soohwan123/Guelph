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

    // Check if the arguments are valid
    if (argc != 2) {
        printf("Error occured during execution(Incorrect Input).");
        return 1;
    }

    printf(argv[1]);

    // Loop through the second command line argument, containing the operands and the numbers
    for (int i = 0; i < strlen(argv[1]); ++i) {
        char ch = argv[1][i];

        // Check if the char is a numeric value or an operator
        if (isdigit(ch)) {
            // Convert char to double
            double value = ch - '0';
            push(&stack, value); 
        }
        else if (stack == NULL || stack->next == NULL) {
            printf("Not enough values in expression.\n");
            return 1;
        }
        else {
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
                        printf("You can't divide by zero.\n");
                        return 1;
                    }
                    else {
                        result = left / right;
                    }

                    break;
                default:
                    printf("'%c' is an invalid character.\n", ch);
                    return 1;
            }

            push(&stack, result);
        }
    }


    // Print the last value
    print(stack);

    return 0;
}