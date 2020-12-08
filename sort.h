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

        // INSERTION SORT
        void insertionSort(std::vector<int> &vec);

        // QUICK SORT
        void quickSort(std::vector<int> &vec, int low, int high);
        void swap(int *a, int *b);
        int partitionMid(std::vector<int> &vec, int low, int high);

        // MERGE SORT
        std::vector<int> merge(std::vector<int> left, std::vector<int> right);
        void mergeSort(std::vector<int> &m);

        // RADIX SORT
        void radixSort(std::vector<int> &vec);
        int findMax(std::vector<int> &vec);
        void countSort(std::vector<int> &vec, int exp);

        // sorts a specific seq type and alg and writes to given file
        void specificSeqSort(std::ofstream &of, std::string seq, std::string alg, std::vector<int> &vec);

    public:
        // given user-inputted sort alg, function writes data to csv for all sequence sizes and types
        void sort(std::string alg); 


};

#endif
