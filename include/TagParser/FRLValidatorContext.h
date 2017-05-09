#ifndef FRL_VALIDATOR_CONTEXT_H
#define FRL_VALIDATOR_CONTEXT_H
#include <string>
#include <utility>
#include <stack>
#include <fstream>
#include <iostream>
#include "FRLValidatorState.h"

class FRLValidatorContext {

	public:
	    FRLValidatorContext(std::ifstream * in);
	    ~FRLValidatorContext();
	    int getLine();
	    void incrementLine();
	    std::string getTag();
	    void clearTag();
	    void appendToTag(char c);
	    bool isEmptyTagStack();
	    void pushTag(std::pair<std::string,int> pair);
	    std::pair<std::string,int> popTag();
	    char getNextChar();
	    bool isGood();
	    size_t tagSize();
	    bool process();
	    void setState(FRLValidatorState *state);

	private:
	    int line;
	    std::ifstream  &ifs;
	    std::string tag;
	    std::stack<std::pair<std::string,int>> tags;
	    FRLValidatorState *state;

};


#endif //FRL_VALIDATOR_CONTEXT_H
