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


/**
 * Performs the downheap algorithm.
 * The key at the passed position is swapped with the key of it's child with the largest value
 *
 * @param int key array
 * @param int current position
 * @param int 2D array that has keys and values
 */
void downHeap(int key[20], int pos, int array[20][10]){
    //If it's a last leaf node then return
    if (!isParent(pos)) return;
    
    int left_child = 2 * pos + 1;
    int right_child = 2 * pos + 2;
    int bigger_child = left_child;
    
    //If right child exists and it's biggger, swap
    if (right_child < 20 && key[right_child] > key[left_child]) {
        bigger_child = right_child;
    }
    
    if (key[bigger_child] > key[pos]) {
        swap(pos, bigger_child, key, array);
        downHeap(key, bigger_child, array);
    } 
}


/**
 * Returns true if the passed position has a child or false if there's no child
 *
 * @param int key index
 * @return true if the key is a parent false if it isn't
 */
bool isParent(int keyPos){
    return (2 * keyPos + 1) < 20; 
}


/**
 * Swaps 2 rows in the 2D array and the key array. 
 * It receives the position of the 2 rows to be swapped, the key array, and the 2D array in its arguements.
 *
 * @param int key 1 index
 * @param int key 2 index
 * @param int array that has key values
 * @param int 2D array that has keys and values
 */
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
