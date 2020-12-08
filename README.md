# Sorting Algorithms

Sorting algorithms take an input sequence of data that can vary in length and order. This input goes through the algorithm and then outputs a sorted sequence. Our Team implemented Insertion Sort, Quicksort, Mergesort, and Radix Sort. We used four different sequence types; sorted, partially sorted, randomly sorted, and reverse sorted in order to benchmark the efficiency of each sorting algorithm. These sequence sizes ranged from the size of 1 to 100,000 elements. 

## How to Run:

Files needed: ```sort.cpp```, ```sort.h```, and ```main.cpp```

Compile with the following command:
```javascript
g++ -Wall main.cpp sort.cpp ./sort
```

Run with:
```javascript
./sort <sortAlg>
  <sortAlg>: "insert" for insertion sort, "radix" for radix sort, "merge" for mergesort, or "quick" for quicksort
```

The program will write data to csv file named ```<sortAlg>Sort.csv``` corresponding to the user-inputted algorithm  



