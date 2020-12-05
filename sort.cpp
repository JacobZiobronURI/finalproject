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

// Quicksort has many functions so they are all under here //

//creates a random set
int shuffle(std::vector<int> &vec, int size){
    for(int i = 0; i < size - 1; i++){
        int j = i + rand() % (size - i);
        std::swap(vec[i], vec[j]);
    }
    return 0;
}

//instead of using swap function create own to swap pointers
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

//Splits vector A into two different parts based on pivot point
int partition(std::vector<int> &vec, int low, int high){
    int pivot = vec[high];
    int i = (low-1);
    for( int j = low; j <= high - 1; j++){
        if(vec[j] < pivot){
            i++;
            swap(&vec[i], &vec[j]);
        }
    }
    swap(&vec[i+1], &vec[high]);
    return(i+1);
}

void Sorter::quicksort(std::vector<int> &vec, int low, int high, int size){
    if(low < high){
        //creates a partition for the quicksort to run on
        int pi = partition(vec, low, high);

        //runs both partitions
        quicksort(vec, low, pi-1, size);
        quicksort(vec, pi+1, high, size);
    }
}

//simple function to print the vector
void printArr(std::vector<int> &vec){
    for (unsigned int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}


int main(){
    std::vector<int> vec;

    // initialize random seed
    srand (time(NULL));

    // generates random size for vec (between 0 and 99, currently)
    int size = rand() % 100;

    for (int i = 0; i < size; i++){
        // rand() % 100 -> random # between 0 and 99
        // rand() % 10 -> random # between 0 and 9, etc.
        vec.push_back(rand() % 100);
    }

    // prints unsorted array
    std::cout << "Unsorted: " << '\n';
    printArr(vec);

    // sorts and prints sorted array
    int high = size - 1;
    quicksort(vec, 0, high, size);
    std::cout << "Sorted: " << '\n';
    printArr(vec);

}

// PUBLIC

void Sorter::sort(std::string alg){
    // put all the "doing" here
    // main will call this method only, and this will run user-specified algorithm with all 4 seq types and write to csv
}


