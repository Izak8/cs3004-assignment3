/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend) {
    // Preconditions (by construction from mergesort):
    // leftstart <= leftend < rightstart <= rightend
    // We’ll merge the two sorted halves into A[leftstart..rightend].

    int L = leftstart;
    int R = rightend;

    // 1) Copy the whole span once from A -> B
    size_t bytes = (size_t)(R - L + 1) * sizeof(int);
    memcpy(&B[L], &A[L], bytes);

    // 2) Merge from B back into A
    int i = leftstart;   // scans left half in B
    int j = rightstart;  // scans right half in B
    int k = leftstart;   // scans A where we write next

    while (i <= leftend && j <= rightend) {
        if (B[i] <= B[j]) A[k++] = B[i++];
        else              A[k++] = B[j++];
    }
    // Copy any remainder from the side that’s not finished
    while (i <= leftend)  A[k++] = B[i++];
    while (j <= rightend) A[k++] = B[j++];
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right) {
    if (left >= right) return;  // 0 or 1 element: already sorted

    int mid = left + (right - left) / 2;

    // Sort left half and right half
    my_mergesort(left, mid);
    my_mergesort(mid + 1, right);

    // Merge the two sorted halves
    merge(left, mid, mid + 1, right);
}


/* this function will be called by the testing program. */
void *parallel_mergesort(void *arg) {
    struct argument *a = (struct argument *)arg;
    my_mergesort(a->left, a->right);   // serial baseline
    return NULL;                       // tester frees the root arg
}

/* we build the argument for the parallel_mergesort function. */
struct argument *buildArgs(int left, int right, int level) {
    struct argument *p = malloc(sizeof *p);
    if (!p) { perror("malloc"); exit(1); }
    p->left = left; p->right = right; p->level = level;
    return p;
}

