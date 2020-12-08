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

// SEQUENCE GENERATOR FUNCTIONS
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

// SORTING ALGORITHMS

// INSERTION SORT

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

// QUICK SORT

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

void Sorter::quickSort(std::vector<int> &vec, int low, int high){
    if(low >= high){return;}

    int pivot = partitionMid(vec, low, high);

    quickSort(vec, low, pivot - 1);
    quickSort(vec, pivot + 1, high);
}

// MERGE SORT

std::vector<int> Sorter::merge(std::vector<int> left, std::vector<int> right)
{
   std::vector<int> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((int)left.front() <= (int)right.front()) {
            result.push_back((int)left.front());
            left.erase(left.begin());
         }
   else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

void Sorter::mergeSort(std::vector<int> &m)
{
   if (m.size() <= 1)
      return;

   std::vector<int> left, right, result;
   int middle = ((int)m.size()+ 1) / 2;

   // splits vector m into two subvectors
   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }
   
   // recursively splits vector in half, then merges them back
   mergeSort(left);
   mergeSort(right);
    
   // merge function is doing the work of sorting 
   m = merge(left, right);
}

// RADIX SORT

// function to return maximum value in vector
int Sorter::findMax(std::vector<int> &vec){
    int max = vec[0];
    for (unsigned int i = 1; i < vec.size(); i++){
        if (vec[i] > max){max = vec[i];}
    }
    return max;
}

// A function to do counting sort of vec based on the digit represented by exp
// puts integers into "buckets" (similarly to hash tables) and counts # of encounters
void Sorter::countSort(std::vector<int> &vec, int digit){
    int count[10] = {0}; // fill count array with 0s, array size 10 bc 10 digits (0-9)
    int size = vec.size();
    int output[size]; // output array

    // Stores count of occurrences in count[]
    for (int i = 0; i < size; i++){
        // ex. vec[i] = 180, digit = 10
        // (vec[i] / digit) % 10 = (180 / 10) % 10 = 18 % 10 = 8
        // count[8]++;
        count[(vec[i] / digit) % 10]++;
    }

    // Changes count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    // Builds the output vector
    for (int i = size - 1; i >= 0; i--){
        output[count[(vec[i] / digit) % 10] - 1] = vec[i];
        count[(vec[i] / digit) % 10]--;
    }

    // Copies the output vector to vec, so that vec now
    // contains sorted numbers according to current digit
    for (int i = 0; i < size; i++){
        vec[i] = output[i];
    }
}

// The main part of radixSort function to that sorts vec using countSort
void Sorter::radixSort(std::vector<int> &vec){
    // Find the maximum number to know number of digits
    int max = findMax(vec);

    // Do counting sort for every digit where i is current digit number
    for (int digit = 1; max / digit > 0; digit *= 10){
        countSort(vec, digit);
    }
}

// sorts a specific seq type and alg
void Sorter::specificSeqSort(std::ofstream &of, std::string seq, std::string alg, std::vector<int> &vec){
    clock_t start, end;
    double execTime;
    
    // loops through for sequence size 1, 10, 100, ..., 100,000
    // limit is 100,00 because insertionSort is quite slow after this
    for (int i = 1; i <= 100000; i *= 10){
        of << seq << ',' << i << ',';
        
        // generates certain sequence type
        if (seq == "Sorted"){
            generateSorted(vec, i);
        }else if(seq == "Reverse"){
            generateReverse(vec, i);
        }else if(seq == "Random"){
            generateRandom(vec, i);
        }else{//seq == "Partial"
            generatePartial(vec, i);
        }

        start = clock();

        // calls correct user-chosen algorithm
        if (alg == "insert"){insertionSort(vec);}
        else if (alg == "merge"){mergeSort(vec);}
        else if (alg == "quick"){quickSort(vec, 0, i - 1);}
        else if (alg == "radix"){radixSort(vec);}

        end = clock();

        // converts "clock ticks" to milliseconds (ms)
        execTime = double (end - start) / double (CLOCKS_PER_SEC / 1000);
        
        // writes data to given file (with ofstream)
        of << std::fixed << execTime << std::setprecision(8) << "\n";
    }
    of << "\n";
}

// PUBLIC

void Sorter::sort(std::string alg){
    // main will call this method only, and this will run user-specified algorithm with all 4 seq types and write to csv
    // alg: "insert", "radix", "merge", "quickHi", "quickMid"
    
    // checks if input is valid
    if (alg != "insert" && alg != "radix" && alg != "merge" && alg != "quick"){
        std::cout << "Invalid Input\n";
        return;
    }
    
    std::vector<int> vec;
    std::ofstream of;

    // opens correct file to write to
    std::string fileName = alg + "Sort.csv";
    of.open (fileName);

    // writes FILE FORMAT: seq. type, sequence length,execTime (in seconds)
    of << "Sequence Type,Sequence Length,Execution Time\n";

    // call function to write data for all 4 types of sequences, given user's alg
    specificSeqSort(of, "Sorted", alg, vec);

    specificSeqSort(of, "Reverse", alg, vec);

    specificSeqSort(of, "Random", alg, vec);

    specificSeqSort(of, "Partial", alg, vec);

    of.close();
}


