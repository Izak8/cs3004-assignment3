#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../mergesort.h"
/* global state is safe and good and never goes wrong and doesn't make testing difficult! */
/* declare the god-damned externals! (SO STUPID!!!!!) */
int* A;
int* B;
int cutoff;

void printA(size_t start, size_t end) {
	printf("\nA ");
	for(size_t i = start; i < end+1; i++) {
		printf("%d ", A[i]);
		fflush(stdout);
	}
}

void printB(size_t start, size_t end) {
	printf("\nB ");
	for(size_t i = start; i < end+1; i++) {
		printf("%d ", B[i]);
		fflush(stdout);
	}
}

int main(void) {

	{
		printf("Test 1: sort an array in parallel with not enough levels\n");	
		cutoff = 1;
		A = malloc(10 * sizeof(int));
		B = malloc(10 * sizeof(int));

		A[0] = 5;
		A[1] = 7;
		A[2] = 2;
		A[3] = 3;
		A[4] = 7;
		A[5] = 1;
		A[6] = 9;
		A[7] = 8;
		A[8] = 6;
		A[9] = 1;

		struct argument* args = buildArgs(0,9,0);
		parallel_mergesort(args);

		assert(A[0] == 1);
		assert(A[1] == 1);
		assert(A[2] == 2);
		assert(A[3] == 3);
		assert(A[4] == 5);
		assert(A[5] == 6);
		assert(A[6] == 7);
		assert(A[7] == 7);
		assert(A[8] == 8);
		assert(A[9] == 9);

		printf("Test 1: Passed\n");
	}


	{
		printf("Test 2: sort an array in parallel with too many levels\n");	
		cutoff = 16;
		A = malloc(9 * sizeof(int));
		B = malloc(9 * sizeof(int));
		
		A[5] = 1; // 0
		A[2] = 2; // 1
		A[3] = 3; // 2
		A[0] = 5; // 3
		A[8] = 6; // 4
		A[4] = 7; // 5
		A[1] = 7; // 6
		A[7] = 8; // 7
		A[6] = 9; // 8

		printA(0,8);
		printB(0,8);
		parallel_mergesort(args);

		printA(0,8);
		printB(0,8);

		assert(A[0] == 1);
		assert(A[1] == 2);
		assert(A[2] == 3);
		assert(A[3] == 5);
		assert(A[4] == 6);
		assert(A[5] == 7);
		assert(A[6] == 7);
		assert(A[7] == 8);
		assert(A[8] == 9);

		printf("Test 2: Passed\n");
	}
	return 0;
}
