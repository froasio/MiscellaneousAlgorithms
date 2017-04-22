#ifndef FRL_ABSTRACTPARSER_H
#define FRL_ABSTRACTPARSER_H
#include "Result.h"


class  FRLValidator {
public:
    Result parse(ifstream* in);
private:
	bool isValidCharacter(char c);
	enum ValidatorState {IDLE, TAG_INIT, OPEN_TAG, CLOSING_TAG, CTAG};
};


#endif //FRL_ABSTRACTPARSER_H
