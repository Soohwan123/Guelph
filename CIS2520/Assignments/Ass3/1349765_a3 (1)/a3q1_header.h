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

#ifndef BINARY_TREE
#define BINARY_TREE

// Node structure representing a binary tree node containing string data.
typedef struct Node {
    char data[10];
    struct Node *left, *right;
} Node;

typedef struct {
    char varName[10]; 
    float value;       
} Variable;

// Global variables
extern Variable variables[10];
extern int varCount;

Node* createNode(char *data);
Node* parseExpression(char *expr);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
void promptVariables(Node *root);
float calculate(Node *root);
int isValidParentheses(char* expr);
void removeOuterParentheses(char* expr);
void freeTree(Node *root);

#endif
