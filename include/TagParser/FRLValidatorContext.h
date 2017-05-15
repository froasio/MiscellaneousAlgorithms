#ifndef FRL_VALIDATOR_CONTEXT_H
#define FRL_VALIDATOR_CONTEXT_H
#include <string>
#include <utility>
#include <stack>
#include <fstream>
#include <iostream>
#include <memory>
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
	    void setState(std::unique_ptr<FRLValidatorState> st);

	private:
	    int line;
	    std::ifstream  &ifs;
	    std::string tag;
	    std::stack<std::pair<std::string,int>> tags;
	    std::unique_ptr<FRLValidatorState> state;

};


#endif //FRL_VALIDATOR_CONTEXT_H
