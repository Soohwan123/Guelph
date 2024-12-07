# CIS2520-F24-A3

## Student Information 
Name : Soohwan Kim

Student Number : 1349765

## Assignment Overview
What is the assignment about?  
Explain the purpose of the program and what it accomplishes.

First of all, q1 is about making a tree for math equation and make it be able to preorder, inorder, postorder
and calcualtes the equation properly. 
The program will detect any useless parentheses and allocate variables, numbers,
and operands into the tree in order.

Secondly, q2 is about implementing a MAX-HEAP data structure using array representation. 
The program reads 200 two-digit integers from a file "f.dat" and stores them 
in a 20x10 array. Each row is treated as an object where the sum of the first three
integers becomes the key value, and the remaining seven integers are the information
content. The program then applies the parental node downheap algorithm to create 
a MAX-HEAP structure, where each parent node's key value must be greater 
than its children's key values. 
Finally, the program displays the resulting heap as a 20x10 array.


Resources

Did you use any resources (for example book, notes etc) in this assignment?
https://www.geeksforgeeks.org/postorder-traversal-of-binary-tree/
https://www.scaler.com/topics/binary-tree-in-c/
https://stackoverflow.com/questions/4080646/how-to-downheap
https://stackoverflow.com/questions/7021725/how-to-convert-a-string-to-integer-in-c
https://www.tutorialspoint.com/isalnum-function-in-c-language
https://stackoverflow.com/questions/21548464/how-to-write-a-makefile-to-compile-a-simple-c-program
https://makefiletutorial.com/
https://www.geeksforgeeks.org/heap-data-structure/
https://www.programiz.com/dsa/heap-data-structure


Implementation
Is the assignment complete? 
If not, mention what part of the assignment is missing or incomplete.
The assignment is complete. Although I added some functions
which are int isValidParentheses(char* expr);
void removeOuterParentheses(char* expr);
void freeTree(Node *root);
in a3q1.