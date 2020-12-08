#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

/* How it works:
    - DIVIDE & CONQUER (like mergeSort):
    - repeatedly (recursively) picks an element/index to be the "pivot"
        -For choosing the middle it makes the algorithm more efficient
         and is much better than picking a high or low pivot position
    - and partition the array/vector/list elements around the pivot
        - (meaning) move lower or equal elements on left of pivot, higher ones on right
    - after the recursions ends, the array will inevitable be sorted

    NOTES:
    - In merge sort, the divide step does hardly anything,
      all the real work happens in the combine step.
      Quicksort is the opposite: all the real work happens in the divide step.
      So, the combine step in quicksort does virtually nothing.
*/

//Splits vector A into two different parts based on pivot point
// Mid Pivot Partition Implementation
int Sorter::partitionMid(std::vector<int> &vec, int low, int high){
    // pivot is chosen as the middle element
    int pivot = vec[low + (high - low) / 2];
    
    while(low <= high){
        // while vec[low] < pivot, increase low index
        while(vec[low] < pivot){
            low++;
        }
        // while vec[high] > pivot, decrease high index
        while(vec[high] > pivot){
            high--;
        }
        // if i and j intersect/cross, break
        if (low >= high){break;}

        // swap vec at i and j
        std::swap(vec[low], vec[high]);
        low++;
        high--;
    }
    // low is now the position of pivot - vec is partitioned around it
    return low;
}

void quickSort(std::vector<int> &vec, int low, int high){
    if(low >= high){
        return;
    }

    int pivot = partition(vec, low, high);

    // recursively sort each "half" subvector
    quickSortMedian(vec, low, pivot - 1);
    quickSortMedian(vec, pivot + 1, high);
}

//simple function to loop through and print the vector's contents
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
        // fills the vec with random ints between 0 and 99
        vec.push_back(rand() % 100);
    }

    // prints unsorted array
    std::cout << "Unsorted: " << '\n';
    printArr(vec);

    // sorts and prints array
    quickSort(vec, 0, size - 1);
    std::cout << "Sorted: " << '\n';
    printArr(vec);

}
