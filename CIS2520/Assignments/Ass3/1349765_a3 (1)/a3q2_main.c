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

// The main function parses the f.dat file and stores information into static arrays before calling downHeap and printing the array contents. 
int main(void){
	int array[20][10];
	int key[20];
	int i = 0, j = 0;

	FILE *fp;
	fp = fopen("f.dat", "r");
	
	// Check if file opened successfully
	if (fp == NULL) {
		printf("Error: Unable to open f.dat file\n");
		return 1;
	}

	// Check the number of values read from file
	int read_count = 0;
	while(!feof(fp)){
		for(i = 0; i < 20; ++i){
			for(j = 0; j < 10; ++j){
				if (fscanf(fp, "%d", &(array[i][j])) != 1) {
					printf("Error: Invalid data format or insufficient data in f.dat\n");
					fclose(fp);
					return 1;
				}
				read_count++;
			}
		}
	}

	// Verify total number of values
	if (read_count != 200) {  // 20 rows * 10 columns
		printf("Error: Incorrect number of values in f.dat (expected 200, got %d)\n", read_count);
		fclose(fp);
		return 1;
	}

	fclose(fp);

	// Evaluating the keys and storing them in the key array. Key array is being used for the heap
	for(i = 0; i < 20; ++i){
		key[i] = array[i][0] + array[i][1] + array[i][2];
	}

	// The downheap algorithm is applied to the last node and then goes backward to the root
	for(i = 19; i >= 0; --i){
        downHeap(key, i, array);
	}

	for(i = 0; i < 20; ++i){
		for(j = 0; j < 10; ++j){
			if(array[i][j] < 10){
				printf("0%d ", array[i][j]);
			}
			else{	
				printf("%d ", array[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}

