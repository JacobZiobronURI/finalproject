#include <vector>
#include <string>

#ifndef __SORT_H__
#define __SORT_H__

class Sort
{
    private:
        // generate sequences
        void generateSorted(std::vector<int> &vec, int length);
        void generateReverse(std::vector<int> &vec, int length);
        void generateRandom(std::vector<int> &vec, int length);
        void generatePartialSort(std::vector<int> &vec, int length);

        // sorting algorithms - add your sort functions (+ helper functions) here
        void insertionSort();
        void quickSort();
        // quickSort helper functions
        int shuffle(std::vector<int> &vec, int size);
        void swap(int *a, int *b);
        int partition(std::vector<int> &vec, int low, int high);
        //if we decide to remove bubblesort just remove this
        void bubbleSort();



    public:
        void sort(std::string alg); // given user inputted string of sort alg type

};

#endif
