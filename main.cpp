#include <iostream>
#include "sort.h"

int main(int argc, char *argv[]){
    // checks for correct input - outputs instructions
    if (argc != 2) {
        std::cout << "To write CSV datafile:\n\t";
        std::cout << "Usage: ./sort <sortName>\n";
        std::cout << "\t\t<sortName>: algorithm to be used (insert, merge, quick, radix)\n";

        std::cout << "To see an example:\n\t";
        std::cout << "Usage: ./sort <sortNameEx>\n";
        std::cout << "\t\t<sortNameEx>: algorithm to be used (insertEx, mergeEx, quickEx, radixEx)\n";
        return 0;
    }
    
    std::string alg(argv[1]);

    Sorter name;
    
    // write to CSV file or shows an example
    if (alg == "insert" || alg == "merge" || alg == "quick" || alg == "radix"){
         name.sort(alg);
    }else{ // alg == <sort>Ex
        name.example(alg);
    }
}
