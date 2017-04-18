#include <fstream>
#include <iostream>
#include "FRLValidator.h"

Result FRLValidator::parse(ifstream *ifsp) {

    ifstream &ifs = *ifsp;
    char nextChar = (char) ifs.get();
    while (ifs.good()) {
        // @Todo: Your code here :)...
        nextChar = (char) ifs.get();
        (void)nextChar;
    }

    return Result();
}
