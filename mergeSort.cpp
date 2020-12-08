#include <iostream>
#include <vector>
#include <stdlib.h> // rand, srand
#include <time.h> // time

/* How it works:
    - DIVIDE & CONQUER:
    - repeatedly (recursively) breaks down the list/array/vector into smaller sublists
      until sublists contain a single element
    - then merges them in such a way that they are sorted
*/

void print(std::vector<int> v)
{
    //prints vector
    for(unsigned int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}

//mergeSort function will work through recursively to establish a left and right subsequence of original sequence
//inside mergeSort function, it will call on the merge function in order to create a combined, sorted sequence of the two subsequences 
std::vector<int> merge(std::vector<int> left, std::vector<int> right)
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

void mergeSort(std::vector<int> &m)
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

int main()
{
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

    std::cout << "Unsorted: " << '\n';
    print(vec);
     
    std::cout << "Sorted: " << '\n';
    mergeSort(vec);
    print(vec);
}
