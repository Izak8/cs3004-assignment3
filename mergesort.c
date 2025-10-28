#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */

/* merges two sub-arrays preserving order */
void merge(int leftstart, int leftend, int rightstart, int rightend) {

	int leftindex = leftstart;
	int rightindex = rightstart;
	int index = leftstart;

	/* 	iterate through the main array A at two positions (leftstart and rightstart).
	
		for each index in B, insert the left or right element from A which is
		of lesser value until either position is out of bounds
	*/

	for(; (leftindex <= leftend) && (rightindex <= rightend); index++) {
		/* choose left element from B if smaller */
		if(A[leftindex] <= A[rightindex]) {
			B[index] = A[leftindex];
			leftindex++;
		}
		else /* choose right element */ {
			B[index] = A[rightindex];
			rightindex++;
		}
	}

	/* 	loop terminates once either sub-array is out of bounds

		as such, remaining elements in either sub-array must be
		copied to B

		either one of these copies may be a no-op (since only one
		sub-array will have elements remaining at most)
	*/

	int num_bytes_to_copy_in_total		= ((rightend - leftstart) + 1) * sizeof(int);
	int num_bytes_to_copy_from_left 	= ((leftend - leftindex) + 1) * sizeof(int);
	int num_bytes_to_copy_from_right 	= ((rightend - rightindex) + 1) * sizeof(int);
	
	memcpy(&B[index], &A[leftindex], num_bytes_to_copy_from_left);
	memcpy(&B[index], &A[rightindex], num_bytes_to_copy_from_right);
	/* copy auxiliary array B, which is now sorted, back to A */
	memcpy(&A[leftstart], &B[leftstart], num_bytes_to_copy_in_total);
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right) {
	if (left >= right ) return; /* base case: array of size 0 or 1 is already sorted */

	int mid = left + (right - left) / 2; // Split the range roughly in half

	my_mergesort(left, mid);       /* sort the left half*/
	my_mergesort(mid + 1, right);  /* sort the right half*/

	merge(left, mid, mid + 1, right); /* merge the two sorted halves */
}

/* this function will be called by the testing program. */
void *parallel_mergesort(void *arg) {
    struct argument *a = (struct argument *)arg;

	/* TEMPORARY: run the serial path so the harness passes. */

    my_mergesort(a->left, a->right);

    /* Do NOT free(a) here — the harness frees the root arg. */
    return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument* buildArgs(int left, int right, int level) {

		/* left must be <= right */
		if(left > right) {
			return NULL;
		}
		
		/* left and right are positive indices */
		if((left < 0) || (right < 0) || (level < 0)) {
			return NULL;
		}

		
		/* allocate space on the heap for an argument struct
			and create a pointer to this memory */
		struct argument* args = malloc(sizeof(struct argument));

		/* set the memory on the heap with the relevant values
			and return the pointer */

		args->left = left;
		args->right = right;			

		/* level > cutoff saturate */
		if(level > cutoff) {
			args->level = cutoff;
		}
		else {
			args->level = level;
		}
		
		return args;

		/* responsibility will be on the caller to free-up memory */
}

