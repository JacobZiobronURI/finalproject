# Final Project - Sorting Algorithms

## The Team:

Jacob Ziobron
Leslie Ortiz
Tuyetinh Nguyen

## Introduction

This team was charged with the task of implementing three different sorting algorithms from CSC 212 and an additional
new one. The three given sorting algorithms from class are insertion sort, mergesort, and quicksort. The new algorithm is
called radix sort. This project's purpose is to implement and anlyze these algorithms and compare them to each other to
determine which one has the fastest runtime, the slowest runtime, and their efficiency based on differences in
sequence size and type. A greater purpose of this project is to prepare this team for future employment by
modeling what project development in a company setting might look like. From day one, this team has scheduled
weekly plans and objectives that move us closer to project completion. This project process is another step
in preparing the team members for jobs after college.

## Methods

### Insertion Sort

Insertion sort (O(n^2)) sorts elements one by one and inserts them in a newly sorted list in the correct position with the following characteristics:
> 1. The algorithm efficiently takes advantage of presorting, making its best case O(n)
> 2. Works best with small data sets
> 3. Requires only one comparison per element for a presorted list
> 4. Considered a stable sort since it does not change the relative order of elements with equal keys.
> 5. Requires fewer comparisons than that of bubble sort (unless list is backwards) yielding a time complexity of O(n + d) where d signifies the number of inversions.
> 6. Only requires a constant amount of additional memory.
> 7. It can sort a list as it receives it
> 8. New elements can be inserted with a sorted array
*Description provided by https://www.bogotobogo.com/Algorithms/insertionsort.php*


### Mergesort

Merge sort is an (O(nlogn)) divide and conquer algorithm. In order to achieve a faster runtime, this algorithm follows these methods:
> 1. Dividing the n-element sequence to be sorted into two subsequences of n/2 elements each
> 2. Sorting the two subsequences recursively by re-applying merge sort
> 3. Merging the two sorted subsequences to produce the sorted answer.

This divide-and-conquer paradigm involes three steps at each level of recursion:
> 1. Divide the problem into a number of subproblems that are smaller instances of the same problem.
> 2. Conquer the subprograms by solving them recursively. If the subproblem sizes are small enough, however, just solve the subproblems in a straightforward manner.
> 3. Combine the solutions to the subproblems into the solution for the original problem.

*Description provided by "Introduction To ALGORITHMS" by Cormen et al. (2009)*

### Quicksort

The Quicksort algorithm (O(nlogn)) is regarded as the fastest known comparison-based sorting algoritm. Similar to merge sort, it uses the divide and conquer method, performing the following steps:
> 1. An element, or "pivot", is selected from the list
> 2. The list is reordered in such a way that all elements with values less than the pivot come before the pivot. Otherwise, greater values will be placed after it and equal values go either way. After this partition operation, the pivot will then be placed in its rightful position.
> 3. Since this algorithm is being run in linear time and utilizes swaps, no extra memory will be needed. 
> 4. After two sub-lists of lesser and greater lists are established, recursively sort them.

*Description provided by https://www.bogotobogo.com/Algorithms/quicksort.php*


### Radix Sort

The radix sort derives its name from the radices (similar to digits) of numbers. This is due to its method of begins by sorting input values according to its first radix, second radix and so on. This alogirthm is a multipass sort, meaning that the number of passes equals the number of radices of a lists' values. Radix sort begins by first sorting:

> **Least significant digits (LSD)**
- Where short keys come before longer keys. Keys of the same length are sorted lexicographically (alphabetically).

Then:

> **Most significant digit (MSD)**
- Where MSD radix sorts use lexicographic order. 

*Description provided by https://www.bogotobogo.com/Algorithms/radixsort.php*

## Implementation

Describe work, include plots/figures if necessary

## Contributions

### Jacob

- collaborated on SCRUM wkst

  #### Algorithms*

  - quicksort

### Leslie

- collaborated on SCRUM wkst

  #### Algorithms*

  - mergesort

### Tuyetlinh

- collaborated on SCRUM wkst

  #### Algorithms*

  - insertion sort

###### Note

*All algorithms (except radix sort, which was a collaborative effort) were initially an individual’s projects,
but after completiion, or if a problem was encountered, all other team members checked, debugged, and refined
each other’s programs as a group to produce a project to this best of our combined abilities.




