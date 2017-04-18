#ifndef FRL_ABSTRACTPARSER_H
#define FRL_ABSTRACTPARSER_H


#include "Result.h"

class  FRLValidator {
public:
    Result parse(ifstream* in);
};


#endif //FRL_ABSTRACTPARSER_H
