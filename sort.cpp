#include <iostream>
#include <fstream> // write to output file
#include <utility> // swap
#include <stdlib.h> // rand, srand
#include <time.h> // time, clock
#include <iomanip>  // std::setprecision

#include "sort.h"

/*
    PRIVATE
*/

// generate sequence functions
void Sorter::generateSorted(std::vector<int> &vec, int length){
    vec.clear();
    for (int i = 0; i < length; i++){
        vec.push_back(i);
    }
}

void Sorter::generateReverse(std::vector<int> &vec, int length){
    vec.clear();
    for (int i = length; i > 0; i--){
        vec.push_back(i);
    }
}

void Sorter::generateRandom(std::vector<int> &vec, int length){
    vec.clear();
    for (int i = 0; i < length; i++){
        // rand() % 100 -> random # between 0 and 99
        // rand() % 10 -> random # between 0 and 9, etc.
        vec.push_back(rand() % 100);
    }
}

void Sorter::generatePartialSort(std::vector<int> &vec, int length){
    // initialize random seed
    srand (time(NULL));
    vec.clear();

    // generate completely sorted array
    generateSorted(vec, length);
    //int temp;
    int index;

    // loop to swap % of sorted vec - 10% currently
    for (int i = 0; i < (length / 10); i++){
        index = rand() % length;
        // temp = vec[index];
        // vec[index] = vec[index + 1];
        // vec[index + 1] = temp;
        std::swap(vec[index], vec[index + 1]);
    }
}

// sorting algorithms
void Sorter::insertionSort(std::vector<int> &vec){
    int temp;
    int i, j;
    // scans array left to right
    // grows "sorted" part of vec
    for (i = 1; i < (int)vec.size(); i++){
        temp = vec[i];
        j = i - 1;
        // find index j in sorted subset {0,...,i-1} where temp (vec[i]) belongs
        while (j >= 0 && vec[j] > temp){
            // shifts unsorted part up by one index
            vec[j + 1] = vec[j];
            j--;
        }
        // inserts temp where it belongs
        vec[j + 1] = temp;
    }
}

//ADD OTHERS HERE

// PUBLIC

void Sorter::sort(std::string alg){
    // put all the "doing" here
    // main will call this method only, and this will run user-specified algorithm with all 4 seq types and write to csv
}


