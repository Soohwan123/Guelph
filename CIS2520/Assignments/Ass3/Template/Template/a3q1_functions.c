/*
Name: Soohwan Kim
Student ID: 1349765
Assignment 3, Question 1
Date : 11/10/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "a3q1_header.h"


// The createNode function allocates memory to the tree and creates a new node using the given data before returning the node.
Node* createNode(char *data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new_node->left = NULL;
    new_node->right = NULL;
    strncpy(new_node->data, data, sizeof(new_node->data) - 1);
    new_node->data[sizeof(new_node->data) - 1] = '\0';
    return new_node;
}

// The parseExpression function parses the expression string passed in from command line, stores the information in a new node, and returns the root node of the tree.
Node* parseExpression(char *expr) {    
    if (strlen(expr) == 0) return NULL;

    removeOuterParentheses(expr);

    // Find operators
    int parentheses = 0;
    int split_pos = -1;
    
    // Find +/- first
    for (int i = strlen(expr) - 1; i >= 0; i--) {
        if (expr[i] == ')') parentheses++;
        if (expr[i] == '(') parentheses--;
        
        if (parentheses == 0 && (expr[i] == '+' || expr[i] == '-')) {
            split_pos = i;
            break;
        }
    }
    
    // If there's not +/- then find *//
    if (split_pos == -1) {
        parentheses = 0;
        for (int i = strlen(expr) - 1; i >= 0; i--) {
            if (expr[i] == ')') parentheses++;
            if (expr[i] == '(') parentheses--;
            
            if (parentheses == 0 && (expr[i] == '*' || expr[i] == '/')) {
                split_pos = i;
                break;
            }
        }
    }
    
    if (split_pos != -1) {
        // When it's found
        char operator[2] = {expr[split_pos], '\0'};
        Node* root = createNode(operator);

        // Allocate memory for left and right strings
        char* left = (char*)malloc(sizeof(char) * (split_pos + 1));
        char* right = (char*)malloc(sizeof(char) * (strlen(expr) - split_pos));

        // Temporary copy for splitting the string
        strncpy(left, expr, split_pos);
        left[split_pos] = '\0';  // Make sure it's null-terminated

        strncpy(right, expr + split_pos + 1, strlen(expr) - split_pos - 1);  // Skip operator
        right[strlen(expr) - split_pos - 1] = '\0';  // Null-terminate
        
        root->left = parseExpression(left);
        root->right = parseExpression(right);
        
        free(left);
        free(right);
        return root;
    }
    

    // If there's no operator, it's either a number or a variable
    if (!isdigit(expr[0]) && expr[0] != '-' && expr[0] != '.') {  // If it's not a number
        int exists = 0;
        // Check if variable already exists in the array
        for (int i = 0; i < varCount; i++) {
            if (strcmp(variables[i].varName, expr) == 0) {
                exists = 1;
                break;
            }
        }
        
        // If it's a new variable, add it to the array
        if (!exists && varCount < 10) {  // Check if we have space (max 10 variables)
            strncpy(variables[varCount].varName, expr, sizeof(variables[varCount].varName) - 1);
            variables[varCount].varName[sizeof(variables[varCount].varName) - 1] = '\0';
            variables[varCount].value = 0.0;  // Initialize with default value
            varCount++;
        }
    }
    
    // Create and return the node regardless of whether it's a number or variable
    Node* newNode = createNode(expr);
    return newNode;
}

// The preOrder function prints tree nodes in preorder traversal.
void preorder(Node *root){
    if (root == NULL) return;
    
    // Remove parentheses and unnecessary characters
    char cleaned_data[20];
    strncpy(cleaned_data, root->data, sizeof(cleaned_data) - 1);
    cleaned_data[sizeof(cleaned_data) - 1] = '\0';
    
    // Remove parentheses
    char* p = strchr(cleaned_data, '(');
    if (p) *p = '\0';
    p = strchr(cleaned_data, ')');
    if (p) *p = '\0';
    
    // Print data
    printf("%s ", cleaned_data);
    
    // Traverse left and right subtrees
    preorder(root->left);
    preorder(root->right);
}

// The inOrder function prints tree nodes in inorder traversal fully parenthesized.
void inorder(Node *root){
    if(root == NULL) return;
    //Adds parentheses for all nodes
    printf("(");

    //Prints all the data recursively
    inorder(root->left);
    printf("%s", root->data);
    inorder(root->right);

    //Adds closing parentheses for all nodes
    printf(")");
}

// The postOrder function prints tree nodes in postorder traversal.
void postorder(Node *root){
    if(root == NULL) return;
    //Prints all the data recursively
    postorder(root->left);
    postorder(root->right);
    printf("%s ", root->data);
}

// The promptVariables function prompts the user to assign values to each variable found in the expression tree. The values should be stored in the Variables struct.
void promptVariables(Node *root) {
    if (root == NULL) return;
    
    // Process only if it's a variable (not an operator)
    if (!strchr("+-*/", root->data[0]) && !isdigit(root->data[0]) && root->data[0] != '-') {
        int exists = 0;
        // Check if variable already exists
        for (int i = 0; i < varCount; i++) {
            if (strcmp(variables[i].varName, root->data) == 0) {
                exists = 1;
                break;
            }
        }
        
        // If it's a new variable, get input from user
        if (!exists) {
            printf("Enter value for %s (Y.YY format): ", root->data);
            float value;
            if (scanf("%f", &value) == 1) {
                strncpy(variables[varCount].varName, root->data, sizeof(variables[varCount].varName) - 1);
                variables[varCount].varName[sizeof(variables[varCount].varName) - 1] = '\0';
                variables[varCount].value = roundf(value * 100) / 100;
                varCount++;
            } else {
                printf("Invalid input. Using default value 0.00\n");
                strncpy(variables[varCount].varName, root->data, sizeof(variables[varCount].varName) - 1);
                variables[varCount].varName[sizeof(variables[varCount].varName) - 1] = '\0';
                variables[varCount].value = 0.00;
                varCount++;
                getchar(); // Clear input buffer
            }
        }
    }
    
    // Check left and right subtrees
    promptVariables(root->left);
    promptVariables(root->right);
}

// The calculate function calculates the expression and returns its result. Division by 0 and/or other error scenarios should be checked.
float calculate(Node *root) {
    if (root == NULL) return 0;

    // If the node is a number, return it directly
    if (isdigit(root->data[0]) || (root->data[0] == '-' && isdigit(root->data[1]))) {
        return atof(root->data);
    }
    // If the node is a variable, find its value and return it
    if (!strchr("+-*/", root->data[0])) {
        for (int i = 0; i < varCount; i++) {
            if (strcmp(variables[i].varName, root->data) == 0) {
                return variables[i].value;
            }
        }
        printf("Error: Unknown variable %s\n", root->data);
        return 0;
    }

    // If the node is an operator, calculate the left and right subtrees
    float left = calculate(root->left);
    float right = calculate(root->right);

    switch (root->data[0]) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/':
            if (right == 0) {
                printf("Error: Division by zero\n");
                return 0;
            }
            return left / right;
        default:
            printf("Error: Unknown operator %s\n", root->data);
            return 0;
    }
}

// The removeOuterParentheses function removes the outermost parentheses from the expression if they are unnecessary.
void removeOuterParentheses(char* expr) {
    while(strlen(expr) >= 2 && 
          *expr == '(' && 
          expr[strlen(expr)-1] == ')') {
        
        // Make a copy of the expression
        char* temp = (char*)malloc(strlen(expr) + 1);
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        
        // Copy the content inside the parentheses (from the first character after the opening parenthesis to the last character before the closing parenthesis)
        strncpy(temp, expr + 1, strlen(expr) - 2);
        temp[strlen(expr) - 2] = '\0';
        
        // Check if there's an operator inside the parentheses and if it's the top level
        int parentheses = 0;
        int hasOperator = 0;
        
        for(int i = 0; temp[i]; i++) {
            if(temp[i] == '(') parentheses++;
            else if(temp[i] == ')') parentheses--;
            else if(parentheses < 0 && 
                   (temp[i] == '+' || temp[i] == '-' || 
                    temp[i] == '*' || temp[i] == '/')) {
                hasOperator = 1;
                break;
            }
        }

        // If there's no operator and the parentheses are valid, remove them
        if(hasOperator == 0 && isValidParentheses(temp)) {
            strcpy(expr, temp);
        } else {
            free(temp);
            break;
        }
        free(temp);
    }
}

// The isValidParentheses function checks if the parentheses in the expression are valid.
int isValidParentheses(char* expr) {
    int count = 0;
    for(int i = 0; expr[i]; i++) {
        if(expr[i] == '(') count++;
        if(expr[i] == ')') count--;
        if(count < 0) return 0;  
    }
    return count == 0; 
}