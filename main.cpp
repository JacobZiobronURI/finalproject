#include <iostream>
#include "sort.h"

int main(int argc, char *argv[]){
    // checks for correct input - outputs instructions
    if (argc != 2 && argc != 3) {
        std::cout << "To write CSV datafile:\n\t";
        std::cout << "Usage: ./sort <sortName>\n";
        std::cout << "\t\t<sortName>: algorithm to be used (insert, merge, quick, radix)\n";

        std::cout << "To see an example:\n\t";
        std::cout << "Usage: ./sort <sortNameEx> <seqType>\n";
        std::cout << "\t\t<sortNameEx>: algorithm to be used (insertEx, mergeEx, quickEx, radixEx)\n";
        std::cout << "\t\t<seqType>: sequence type to be generated (sorted, reverse, random, partial)\n";
        return 0;
    }

    std::string alg(argv[1]);
    std::string seq;
    if (argc == 3){
        seq = argv[2];
    }

    Sorter name;

    // write to CSV file or shows an example
    if ((alg == "insert" || alg == "merge" || alg == "quick" || alg == "radix") && (seq == "")){
        name.sort(alg);
    }else{ // alg == <sort>Ex
        name.example(alg, seq);
    }
}
