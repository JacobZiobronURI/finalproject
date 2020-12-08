#include <iostream>
#include <vector>
#include <stdlib.h> // rand, srand
#include <time.h> // time

/* How it works:
    - array is divided into two parts: sorted and unsorted
    - algorithm scans array left to right
    - elements in sorted part are in ascending ordeer
    - elements in unsorted have not been "seen" yet
*/

void insertionSort(std::vector<int> &vec);
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
    insertionSort(vec);
    std::cout << "Sorted: " << '\n';
    printArr(vec);
}

void insertionSort(std::vector<int> &vec){
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

void printArr(std::vector<int> &vec){
    for (unsigned int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}

