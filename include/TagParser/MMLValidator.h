#ifndef MML_ABSTRACTPARSER_H
#define MML_ABSTRACTPARSER_H


#include "Result.h"

class  MMLValidator {
public:
    Result parse(ifstream* in);
};


#endif //MML_ABSTRACTPARSER_H
