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

	/* copy the remainder from whichever side still has elements */
    if (leftindex <= leftend) {
		/* Left run has leftovers: copy them in one bulk transfer. */
        size_t n = (size_t)(leftend - leftindex + 1);
        memcpy(&B[index], &A[leftindex], n * sizeof(int));
        index += (int)n;
    } else if (rightindex <= rightend) {
		/* Right run has leftovers: copy them in one bulk transfer. */
        size_t n = (size_t)(rightend - rightindex + 1);
        memcpy(&B[index], &A[rightindex], n * sizeof(int));
        index += (int)n;
    }

	/* 	loop terminates once either sub-array is out of bounds

		as such, remaining elements in either sub-array must be
		copied to B

		either one of these copies may be a no-op (since only one
		sub-array will have elements remaining at most)
	*/

	/* One bulk copy back into A. */ /* copy auxiliary array B, which is now sorted, back to A */
    size_t total = (size_t)(rightend - leftstart + 1);
    memcpy(&A[leftstart], &B[leftstart], total * sizeof(int));
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right) {

}

/* this function will be called by the testing program. */
void * parallel_mergesort(void* arg) {
		return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument* buildArgs(int left, int right, int level) {
		return NULL;
}

