#include <vector>
#include <string>

#ifndef __SORT_H__
#define __SORT_H__

class Sort
{
    Private:
        // generate sequences
        void generateSorted(std::vector<int> &vec, int length);
        void generateReverse(std::vector<int> &vec, int length);
        void generateRandom(std::vector<int> &vec, int length);
        void generatePartialSort(std::vector<int> &vec, int length);

        // sorting algorithms - add your sort functions (+ helper functions) here
        void insertionSort();
        void quickSort();

        //if we decide to remove bubblesort just remove this
        void bubbleSort();



    Public:
        void sort(std::string alg); // given user inputted string of sort alg type

};

#endif
