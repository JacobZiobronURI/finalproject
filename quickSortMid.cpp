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
int partition(std::vector<int> &vec, int low, int high){
    int x = vec[low];
    int y = vec[(high-low)/2+low];
    int z = vec[high-1];
    int i = low -1;
    int j = high;
    int count = 0;
    if(y > x && y < z || y > z && y < x) {
        x = y;
    } else if(z > x && z < y || z > y && z < x){
        x = z;
    }
    while(1) {
        while(vec[j] > x){
            j--;
            count++;
        }
        while(vec[i] < x){
            i++;
            count++;
        }
        if(i < j){
            swap(&vec[i], &vec[j]);
        } else {
            return j + 1;
        }
    }
}

void quickSortMedian(std::vector<int> &vec, int low, int high){
    int q;
    int count = 0;
    count++;
    if(high - low < 2){
        return;
    }

    q = partition(vec, low, high);
    std::cout << "hit partition" << std::endl;
    quickSortMedian(vec, low, q);
    quickSortMedian(vec, q, high);
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
    quickSortMedian(vec, 1, high);
    std::cout << "Sorted: " << '\n';
    printArr(vec);

}