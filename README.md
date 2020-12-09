# Sorting Algorithms

Sorting algorithms take an input sequence of data that can vary in length and order. This input goes through the algorithm and then outputs a sorted sequence. Our Team implemented Insertion Sort, Quicksort, Mergesort, and Radix Sort. We used four different sequence types; sorted, partially sorted, randomly sorted, and reverse sorted in order to benchmark the efficiency of each sorting algorithm. These sequence sizes ranged from the size of 1 to 100,000 elements. 

## How to Run:

Files needed: ```sort.cpp```, ```sort.h```, and ```main.cpp```

Compile with the following command:
```javascript
g++ -Wall main.cpp sort.cpp ./sort
```

### To create a CSV file, run with:
```javascript
./sort <sortName>
  <sortName>: "insert" for insertion sort, "radix" for radix sort, "merge" for mergesort, or "quick" for quicksort
```

This will write data to csv file named ```<sortAlg>Sort.csv``` corresponding to the user-inputted algorithm  

### To see an example, run with:
```javascript
./sort <sortNameEx> <seqType>
  <sortName>: "insertEx" for insertion sort, "radixEx" for radix sort, "mergeEx" for mergesort, or "quickEx" for quicksort
  <seqType>: "sorted" for sorted sequence, "reverse" for a reverse sorted sequence, "random" for a random sequence, "partial" for a partially sorted sequence (10% unsorted)
```

This will print a sequence of length 30 and of type given by user, run the user-inputted algorithm, and print the sorted sequence as well as the execution time in milliseconds




