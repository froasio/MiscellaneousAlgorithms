#include <fstream>
#include <iostream>
#include "MMLValidator.h"

Result MMLValidator::parse(ifstream *ifsp) {

    ifstream &ifs = *ifsp;
    char nextChar = (char) ifs.get();
    while (ifs.good()) {
        // @Todo: Your code here :)...
        nextChar = (char) ifs.get();
        (void)nextChar;
    }

    return Result(100, ErrorType::WRONG_CHAR_IN_TAG_NAME);
}
