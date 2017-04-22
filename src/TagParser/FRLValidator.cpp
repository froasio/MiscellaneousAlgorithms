#include <fstream>
#include <iostream>
#include <string>
#include "FRLValidator.h"

bool FRLValidator::isValidCharacter(char c) {
	return c >= 'A' and c <= 'Z';
}

Result FRLValidator::parse(ifstream *ifsp) {
	std::cout << "----------------------" << std::endl;
	ValidatorState state = IDLE;
	int line = 1;
    ifstream &ifs = *ifsp;
    char nextChar;
    std::string tag;
    
    while (ifs.good()) {
       
    	nextChar = (char) ifs.get();

        if( nextChar == '\n' )
        	line++;

        switch( state ) {
        	case IDLE:
        		tag.erase();
        		if( nextChar == '>')
        			return Result(line, ErrorType::UNEXPECTED_CLOSING_TAG_CHAR);
        		if( nextChar == '<')
        			state = FRLValidator::TAG_INIT;
        	break;
       		case TAG_INIT:
       			if(!ifs.good())
       				return Result(line, ErrorType::UNCLOSED_TAG);
       			if( nextChar == '/') {
       				state = CLOSING_TAG;
       			} else if( nextChar == '>')
       				return Result(line, ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
       			else if(isValidCharacter(nextChar)) {
	       			state = FRLValidator::OPEN_TAG;
	       			tag += nextChar;
       			} else {
       				return Result(line, ErrorType::WRONG_CHAR_IN_TAG_NAME);
       			}
       		break;
       		case OPEN_TAG:
       			if(!ifs.good())
       				return Result(line, ErrorType::UNCLOSED_TAG);
       			if( nextChar == '>' ) {
       				if(tag.size() >= 1 and tag.size() <= 10)
       					state = IDLE;
       				else
       					return Result(line, ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
       			} else if(isValidCharacter(nextChar)) {
	       			tag += nextChar;
	       			std::cout << "Tag: " << tag << std::endl;
       			} else {
       				return Result(line, ErrorType::WRONG_CHAR_IN_TAG_NAME);
       			}
       		break;
       		case CLOSING_TAG:
       			if(!ifs.good())
       				return Result(line, ErrorType::UNCLOSED_TAG);
       			if( nextChar == '>' ) {
       				if(tag.size() >= 1 and tag.size() <= 10)
       					state = IDLE;
       				else
       					return Result(line, ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
       			} else if(isValidCharacter(nextChar)) {
	       			tag += nextChar;
       			} else {
       				return Result(line, ErrorType::WRONG_CHAR_IN_TAG_NAME);       		
       			}
       		break;
       		default:
       			return Result();
        }
    }

    return Result();
}
