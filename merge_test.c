#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"

// global state is safe and good and never goes wrong and doesn't make testing difficult!
int* A;
int* B;

void printA(size_t start, size_t end) {
	printf("\nA ");
	for(size_t i = start; i < end+1; i++) {
		printf("%d ", A[i]);
	}
}

void printB(size_t start, size_t end) {
	printf("\nB ");
	for(size_t i = start; i < end+1; i++) {
		printf("%d ", B[i]);
	}
}

/* unit test for merge function */
int main(void) {
	/* contrary to popular practice, malloc should not be casted
		as void* is casted safely automatically */

	/* first test: merge two halves of the full array */
	{
		printf("Test 1: merge two havles of full array\n");
		A = malloc(10 * sizeof(int));
		B = malloc(10 * sizeof(int));

		A[0] = 0; /* leftstart = 0*/
		A[1] = 1;
		A[2] = 2;
		A[3] = 3;
		A[4] = 4; /* leftend = 4*/
		
		A[5] = 3; /* rightstart = 5 */
		A[6] = 4;
		A[7] = 5;
		A[8] = 6;
		A[9] = 7; /* rightend = 9 */

		/* expected result is A=[0,1,2,3,3,4,4,5,6,7] */
		merge(0,4,5,9);

		assert(A[0] == 0);
		assert(A[1] == 1);
		assert(A[2] == 2);
		assert(A[3] == 3);
		assert(A[4] == 3);
		assert(A[5] == 4);
		assert(A[6] == 4);
		assert(A[7] == 5);
		assert(A[8] == 6);
		assert(A[9] == 7);

		printf("Test 1: Passed\n");
	}


	/* first test: merge two halves of the full array */
	{
		printf("Test 2: merge two havles of sub-array\n");
		A = malloc(10 * sizeof(int));
		B = malloc(10 * sizeof(int));

		A[0] = 5; 
		A[1] = 6;
		A[2] = 7;
		A[3] = 8;
		A[4] = 9; 
	
		A[5] = 10;	/* leftstart = 5 */
		A[6] = 11;	/* leftend = 6 */
		A[7] = 2;	/* rightstart = 7 */
		A[8] = 3;
		A[9] = 4;	/* rightend = 9 */

		/* expected result is A=[2,3,4,10,11] */
		merge(5,6,7,9);

		assert(A[5] == 2);
		assert(A[6] == 3);
		assert(A[7] == 4);
		assert(A[8] == 10);
		assert(A[9] == 11);

		printf("Test 2: Passed\n");
	}
}
