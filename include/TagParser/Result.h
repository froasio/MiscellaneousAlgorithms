
#ifndef FRL_RESULT_H
#define FRL_RESULT_H

#include <string>
#include "ErrorType.h"

using namespace std;

class Result {
private:
    bool is_successful;
    int line_number;
    ErrorType type;
public:
    Result(); // Successfully result
    Result(int line_number, ErrorType type); // Error with line number
    Result(string json);
    bool isValid();
    int getLineError();
    ErrorType getErrorType();
    string toJson();
};


#endif //FRL_RESULT_H
