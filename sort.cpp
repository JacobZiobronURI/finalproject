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
    srand (time(NULL));
    for (int i = 0; i < length; i++){
        // rand() % 100 -> random # between 0 and 99
        vec.push_back(rand() % 100);
    }
}

void Sorter::generatePartialSort(std::vector<int> &vec, int length){
    // initialize random seed
    srand (time(NULL));
    vec.clear();

    // generate completely sorted array
    generateSorted(vec, length);
    int index;

    // loop to swap % of sorted vec - ~10% currently
    for (int i = 0; i < (length / 10); i++){
        index = rand() % length;
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

// QUICK SORT - Mid Pivot Partition Implementation
void Sorter::quickSort(std::vector<int> &vec, int left, int right){
    if(left >= right){return;}
    
    int i = left;
    int j = right;

    // partitions vec based on middle pivot position
    int pivot = vec[left + ((right - left) / 2)];

    while(i <= j){
        while(vec[i] < pivot){i++;}
        while(vec[j] > pivot){j--;}
        if(i <= j){
            std::swap(vec[i], vec[j]);
            i++;
            j--;
        }
    }

    // recursively sorts subvectors
    if (left < j){
        quickSort(vec, left, j);
    }

    if(i < right){
        quickSort(vec, i, right);
    }
}

// MERGE SORT

//mergeSort function will work through recursively to establish a left and right subsequence of original sequence
//inside mergeSort function, it will call on the merge function in order to create a combined, sorted sequence of the two subsequences
std::vector<int> Sorter::merge(std::vector<int> left, std::vector<int> right)
{
    //result will be finished array where the two subsequences will be combined
    std::vector<int> result;
    
    //loops through while there are still elements in the sequences
    while ((int)left.size() > 0 || (int)right.size() > 0) {
        
        //start here if elements are present in both lists
        if ((int)left.size() > 0 && (int)right.size() > 0) {
            
            //checks which element out of the two lists is smaller or greater
            if ((int)left.front() <= (int)right.front()) {
                
                //places it in appropriate index
                result.push_back((int)left.front());
                
                //removes elements that have been looked at/sorted
                //begin() returns an iterator pointing to the first element of the vector container
                left.erase(left.begin());
                
            }else{   //if there are no more elements present in the left subsequence, move onto putting right sequence elements into result vector
                result.push_back((int)right.front());
                right.erase(right.begin());
         }

      //end of first if statement conditional

        }else if ((int)left.size() > 0) { //start here if right sequence contains no elements
            for (int i = 0; i < (int)left.size(); i++)
                result.push_back(left[i]);
            break;
            
        }else if ((int)right.size() > 0) { //vice versa
            for (int i = 0; i < (int)right.size(); i++)
                result.push_back(right[i]);
            break;
        }
    }
    
    //return finished vector
    return result;
}

void Sorter::mergeSort(std::vector<int> &m)
{
    //if no more elements, return vector
    if (m.size() <= 1)
        return;

    //indicates what part of the list is being worked on
    std::vector<int> left, right, result;

    //finds middle spot of the vector
    int middle = ((int)m.size()+ 1) / 2;

    //loops through to create a left list
    for (int i = 0; i < middle; i++) {
        left.push_back(m[i]);
    }

    //loops through to create a right list
    for (int i = middle; i < (int)m.size(); i++) {
        right.push_back(m[i]);
    }

    //recursive calls to establish what will be in the two lists
    mergeSort(left);
    mergeSort(right);

    //call to merge the two
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
            generatePartialSort(vec, i);
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

void Sorter::printArr(std::vector<int> &vec){
    for (unsigned int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}

/*
    PUBLIC
*/

void Sorter::sort(std::string alg){
    // this will run user-specified algorithm with all 4 seq types and write to csv
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

void Sorter::example(std::string alg, std::string seq){
    // checks for correct input
    if (alg != "insertEx" && alg != "radixEx" && alg != "mergeEx" && alg != "quickEx"){
        std::cout << "Invalid Input. For instructions, run \"./sort\"\n";
        return;
    }
    if (seq != "sorted" && seq != "reverse" && seq != "random" && seq != "partial"){
        std::cout << "Invalid Input. For instructions, run \"./sort\"\n";
        return;
    }

    // initialize necessary variables
    std::vector<int> vec;
    clock_t start, end;
    double execTime;
    int size = 30;

    // create vector as an example
    if (seq == "sorted"){
        generateSorted(vec, size);
    }else if(seq == "reverse"){
        generateReverse(vec, size);
    }else if(seq == "random"){
        generateRandom(vec, size);
    }else{//seq == "partial"
        generatePartialSort(vec, size);
    }

    // print unsorted array
    std::cout << "Unsorted: ";
    printArr(vec);

    // start clock & run correct algorithm
    start = clock();

    if (alg == "insertEx"){insertionSort(vec);}
    else if (alg == "mergeEx"){mergeSort(vec);}
    else if (alg == "quickEx"){quickSort(vec, 0, 29);}
    else if (alg == "radixEx"){radixSort(vec);}

    end = clock();

    // print sorted array
    std::cout << "Sorted: ";
    printArr(vec);

    // calculate and print execTime
    execTime = double (end - start) / double (CLOCKS_PER_SEC / 1000);
    std::cout << "Execution time: " << execTime << " ms\n";
}
