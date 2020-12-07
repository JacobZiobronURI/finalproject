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
    for(unsigned int i = 0; i < v.size(); i++)
  std::cout << v[i] << " ";
  std::cout << '\n';
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
   std::vector<int> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
          //checks which element out of the two lists is smaller or greater
         if ((int)left.front() <= (int)right.front()) {
             //places it in appropriate index
            result.push_back((int)left.front());
             //erases elements that have been looked at
            left.erase(left.begin());
         }
   else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) { //if right list is already finished continue looking at left
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) { //vice versa
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
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

   //loops through to create a sorted left list
    for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   //loops through to create a sorted right list
    for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }

   //recursive calls to sort the two lists
   mergeSort(left);
   mergeSort(right);

    //call to merge the two
   m = merge(left, right);
}

int main()
{
   //ex.
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
