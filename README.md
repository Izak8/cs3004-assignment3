README.template

## Project Number/Title 

* Authors: Izak Baldacchino (a1830164), Bunsarak Ann (a1827385), Matthew Edmonds-Wilson(a1850372)
* Group name: Assignment 3 Groups 190

## Overview

This program benchmarks the performance of the parallel merge sort algorithm.
Given an array of random integers of size N, and a "level", it performs merge
sort; each time the array is partitioned, a new thread is spawned to perform
the recursive merge sort on the sub-array. This continues until the "level"
is exceeded.

## Manifest

Makefile 		 -- the recipes which are used to compile the project.
README.md 		 -- this file!
mergesort.c 	 -- contains the source for the functions which need to be implemented.
mergesort.h 	 -- contains the declarations for the functions and structs used.
test-mergesort.c -- contains the source for the program which runs the algorithm.
merge_test.make  -- tiny makefile to build the merge unit test

## Building the project

To build the project simply execute `make`. This assumes it is being built on a UNIX-like
system which features some rendition of the `make` utility. In fact, any system which is
POSIX-compliant shall be able to execute and run this makefile.

From this point execute the built executable `./test-mergesort` and provide relevant arguments.

macOS note: If you see a build error about <error.h>, we’ve already removed that include for macOS compatibility in this branch. If you pull a branch that still includes it, delete the line in test-mergesort.c.

## Features and usage

To run the program use `./test-mergesort N level seed` where `N` refers to the size of the generated
array, `level` refers to the number of times the array is partitioned and sorted in parallel, and
`seed` is used as the seed for generating the random array; same seed = same array.

TODO: write more perhaps?

## Testing
Unit tests for merge()
Balanced halves, unbalanced halves, left/right remainder cases, duplicates, already sorted, reverse-sorted, tiny segments (size 0/1).

Integration check (temporary)
While parallel_mergesort is incomplete, we verify my_mergesort correctness by temporarily routing parallel_mergesort to call my_mergesort (serial path) and checking the harness output. (In this branch, parallel_mergesort is intentionally a stub.)

This section should detail how you tested your code. Simply stating "I ran
it a few times and it seems to work" is not sufficient. Your testing needs
to be detailed here.


TODO: figure out testing scheme.

## Known Bugs

List known bugs that you weren't able to fix (or ran out of time to fix).

TODO: haven't made any bugs yet ...

## Reflection and Self Assessment
Early failure we hit: Harness printed “sorting failed!!!!” because it always calls parallel_mergesort() and ours was a stub.
What we learned: keep a unit test for merge() separate from threading so we can validate core correctness early.

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your own?
What kinds of errors did you get? How did you fix them?

What parts of the project did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this project? How well
did the development and testing process go for you?


TODO: haven't finished yet ...

## Sources Used
Operating Systems: Three Easy Pieces — chapters on concurrency for general pthread patterns.
Assignment 3 specification and starter code (University of Adelaide, COMP SCI 3004–7064).
Assistance with structuring tests and clarifying merge-edge cases provided by AI (ChatGPT).
https://www.youtube.com/watch?v=b1n9T-Iy3SA 
https://stackoverflow.com/questions/2550774/what-is-size-t-in-c

If you used any sources outside of the textbook, you should list them here. 
If you looked something up on stackoverflow.com or you use help from AI, and 
fail to cite it in this section, it will be considered plagiarism and dealt 
with accordingly. So be safe CITE!

TODO: haven't used any sources yet ...
