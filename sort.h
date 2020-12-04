#ifndef __SORT_H__
#define __SORT_H__

#include <iostream>
#include <fstream> // write to output file
#include <vector>
#include <string>
#include <stdlib.h> // rand, srand
#include <time.h> // time, clock
#include <iomanip>  // std::setprecision

class Sort
{
    Private:
        // generate sequences
        void generateSorted(std::vector<int> &vec, int length);
        void generateReverse(std::vector<int> &vec, int length);
        void generateRandom(std::vector<int> &vec, int length);
        void generatePartialSort(std::vector<int> &vec, int length);

        // sorting algorithms
        void insertionSort();

        // add your sort functions (+ helper functions) here
        void

    Public:
        Sort(); // constructor of "object"
        void Sort(std::string alg); // given user inputted string of sort alg type

};

#endif
