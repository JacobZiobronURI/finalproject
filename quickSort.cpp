#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

/* How it works:
    - DIVIDE & CONQUER (like mergeSort):
    - repeatedly (recursively) picks an element/index to be the "pivot"
    - and partition the array/vector/list elements around the pivot
        - (meaning) move lower or equal elements on left of pivot, higher ones on right
    - after the recursions ends, the array will inevitable be sorted

    NOTES:
    - In merge sort, the divide step does hardly anything,
      all the real work happens in the combine step.
      Quicksort is the opposite: all the real work happens in the divide step.
      So, the combine step in quicksort does virtually nothing.
*/

//creates a random set
int shuffle(std::vector<int> &A, int size){
    for(int i = 0; i < size - 1; i++){
        int j = i + rand() % (size - i);
        std::swap(A[i], A[j]);
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
int partition(std::vector<int> &A, int low, int high){
    int pivot = A[high];
    int i = (low-1);
    for( int j = low; j <= high - 1; j++){
        if(A[j] < pivot){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return(i+1);
}

void quicksort(std::vector<int> &A, int low, int high, int size){
    if(low < high){
        //creates a partition for the quicksort to run on
        int pi = partition(A, low, high);

        //runs both partitions
        quicksort(A, low, pi-1, size);
        quicksort(A, pi+1, high, size);
    }
}

//simple function to print the vector
void printArr(std::vector<int> &A){
    for (unsigned int i = 0; i < A.size(); i++){
        std::cout << A[i] << ' ';
    }
    std::cout << std::endl;
}


int main(){
    std::vector<int> A;

    // initialize random seed
    srand (time(NULL));

    // generates random size for vec (between 0 and 99, currently)
    int size = rand() % 100;

    for (int i = 0; i < size; i++){
        // rand() % 100 -> random # between 0 and 99
        // rand() % 10 -> random # between 0 and 9, etc.
        A.push_back(rand() % 100);
    }

    // prints unsorted array
    std::cout << "Unsorted: " << '\n';
    printArr(A);

    // sorts and prints sorted array
    int high = size - 1;
    quicksort(A, 0, high, size);
    std::cout << "Sorted: " << '\n';
    printArr(A);

}