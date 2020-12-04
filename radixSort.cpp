#include <iostream>
#include <vector>
#include <stdlib.h> // rand, srand
#include <time.h> // time

/* How it works:
    - based on digits - very fast sort algorithm for integers
    - "radix" is the base of the number system - decimal numbers have a base of 10
    - radix sort first orders elements based on LSD (least significant digit)
    - this is achieved through countSort
    - digit-by-digit sort starting with LSD to MSD (ones, then tens, then 100s, ...)
    - uses countSort as subroutine to sort
*/

int findMax(std::vector<int> &vec);
void countSort(std::vector<int> &vec, int exp);
void radixSort(std::vector<int> &vec);
void printArr(std::vector<int> &vec);

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
    radixSort(vec);

    std::cout << "Sorted: " << '\n';
    printArr(vec);
}



// function to return maximum value in vector
int findMax(std::vector<int> &vec){
    int max = vec[0];
    for (unsigned int i = 1; i < vec.size(); i++){
        if (vec[i] > max){max = vec[i];}
    }
    return max;
}

// A function to do counting sort of vec based on the digit represented by exp
// puts integers into "buckets" (similar to hash tables) and counts # of encounters
void countSort(std::vector<int> &vec, int digit){
    int count[10] = {0}; // fill count array with 0s, array size 10 bc 10 digits (0-9)
    int size = vec.size();
    int output[size]; // output array

    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++){
        count[(vec[i] / digit) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    // Build the output vector
    for (int i = size - 1; i >= 0; i--){
        output[count[(vec[i] / digit) % 10] - 1] = vec[i];
        count[(vec[i] / digit) % 10]--;
    }

    // Copy the output vector to vec, so that vec now
    // contains sorted numbers according to current digit
    for (int i = 0; i < size; i++){
        vec[i] = output[i];
    }
}

// The main part of Sort function to that sorts vec using Radix Sort
void radixSort(std::vector<int> &vec){
    if (vec.empty()){return;}
    // Find the maximum number to know number of digits
    int max = findMax(vec);

    // Do counting sort for every digit where i is current digit number
    for (int digit = 1; max / digit > 0; digit *= 10){
        countSort(vec, digit);
    }
}

// print vector/array
void printArr(std::vector<int> &vec){
    for (unsigned int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}
