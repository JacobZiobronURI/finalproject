#include <iostream>
#include "sorter.h"

int main(int argc, char *argv[]){
    if (argc != 2) {
        std::cout << "Usage: ./sort <sortName\n";
        std::cout << "\t<sortName\talgorithm to be used (insert, merge, quickHi, quickMid, radix)\n";
        return 0;
    }
    std::string alg(argv[1]);

    Sorter name;
    name.sort(alg);

}