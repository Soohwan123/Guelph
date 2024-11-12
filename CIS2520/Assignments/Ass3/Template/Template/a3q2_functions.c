/*
Name: Soohwan Kim
Student ID: 1349765
Assignment 3, Question 2
Date : 11/10/2024
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "a3q2_header.h"


/*
 * The downHeap function performs the downheap algorithm.
 * The key at the passed position is swapped with the key of it's child with the smallest value.
 * If the key is smaller, than both of it's children's keys then no swap happens.
 * After swap, the downHeap is called again to the new position of the swapped key and it terminates when it's value is smaller than both children.
*/
void downHeap(int key[20], int pos, int array[20][10]){
    int left_child = 2 * pos + 1;
    int right_child = 2 * pos + 2;
    // Consider the current position is the biggest
    int biggest = pos;  

    // If the position has a left child
    if (isParent(pos)) {
        biggest = key[left_child] > key[biggest] ? left_child : biggest;
    }

    // If the position has a right child
    if (right_child < 20) {
        biggest = key[right_child] > key[biggest] ? right_child : biggest;
    }

    //Swap and call downHeap if the biggest is not the current pos 
    if (biggest != pos) {
        swap(pos, biggest, key, array);
        downHeap(key, biggest, array); 
    }
}

// The isParent function returns true if the passed position has a child or false if there's no child
bool isParent(int keyPos){
    return (2 * keyPos + 1) < 20; 
}


// The swap function swaps 2 rows in the 2D array and the key array. It receives the position of the 2 rows to be swapped, the key array, and the 2D array in its arguements.
void swap(int key1Pos, int key2Pos, int key[20], int array[20][10]){
    // Swap keys
    int temp_key = key[key1Pos];
    key[key1Pos] = key[key2Pos];
    key[key2Pos] = temp_key;
    
    // Swap entire rows
    for(int i = 0; i < 10; i++) {
        int temp = array[key1Pos][i];
        array[key1Pos][i] = array[key2Pos][i];
        array[key2Pos][i] = temp;
    }
}
