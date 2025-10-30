#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../mergesort.h"

/* global state is safe and good and never goes wrong and doesn't make testing difficult! */
/* declare the god-damned externals! (SO STUPID!!!!!) */
int* A;
int* B;
int cutoff;

int main(void) {

	struct argument* p;
	
	{
		/* check that a valid struct is built */
		printf("Test 1: a valid struct is built from valid arguments\n");
		p = buildArgs(0,4,0);
		assert(p->left == 0);
		assert(p->right == 4);
		assert(p->level == 0);
		printf("Test 1: Passed\n");
	}

	{
		printf("Test 2: NULL is returned for left > right\n");
		p = buildArgs(6,5,5);
		assert(p == NULL);
		printf("Test 2: Passed\n");	
	}

	{
		printf("Test 3: NULL is returned for negative left\n");
		p = buildArgs(-1,5,5);
		assert(p == NULL);
		printf("Test 3: Passed\n");
	}

	{
		printf("Test 4: NULL is returned for negative right\n");
		p = buildArgs(1,-5,5);
		assert(p == NULL);
		printf("Test 4: Passed\n");
	}

	{
		printf("Test 5: NULL is returned for negative level\n");
		p = buildArgs(1,5,-5);
		assert(p == NULL);
		printf("Test 5: Passed\n");
	}

	{
		printf("Test 6: NULL is returned for all negative arguments\n");
		p = buildArgs(-1,-5,-5);
		assert(p == NULL);
		printf("Test 6: Passed\n");
	}
}
