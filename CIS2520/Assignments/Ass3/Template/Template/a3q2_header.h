/*
Name: Soohwan Kim
Student ID: 1349765
Assignment 3, Question 2
Date : 11/10/2024
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#ifndef HEAP
#define HEAP


void downHeap(int key[20], int pos, int array[20][10]);
bool isParent(int keyPos);
void swap(int key1Pos, int key2Pos, int key[20], int array[20][10]);

#endif