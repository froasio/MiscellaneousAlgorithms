#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <utility>      // std::pair
#include "FRLValidator.h"

bool FRLValidator::isValidCharacter(char c) {
	return c >= 'A' and c <= 'Z';
}

Result FRLValidator::parse(ifstream *ifsp) {
	ValidatorState state = IDLE;
	int line = 1;
    ifstream &ifs = *ifsp;
    char nextChar;
    std::string tag;
    std::stack<pair<string,int>> tags;

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
       			if( nextChar == '/')
       				state = CLOSING_TAG;
       			else if ( nextChar == '!')
       				state = CTAG;
       			else if( nextChar == '>')
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
       				if(tag.size() >= 1 and tag.size() <= 10) {
       					state = IDLE;
       					tags.push(make_pair(tag,line));
       				}
       				else
       					return Result(line, ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
       			} else if(isValidCharacter(nextChar)) {
	       			tag += nextChar;
       			} else {
       				return Result(line, ErrorType::WRONG_CHAR_IN_TAG_NAME);
       			}
       		break;
       		case CLOSING_TAG:
       			if(!ifs.good())
       				return Result(line, ErrorType::UNCLOSED_TAG);
       			if( nextChar == '>' ) {
       				if(tag.size() >= 1 and tag.size() <= 10) {
       					state = IDLE;
       					std::pair<string,int> tagp = tags.top();
       					tags.pop();
       					if(tagp.first != tag) {
       						return Result(line, ErrorType::UNBALANCED_TAG);
       					}
       				}
       				else
       					return Result(line, ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
       			} else if(isValidCharacter(nextChar)) {
	       			tag += nextChar;
       			} else {
       				return Result(line, ErrorType::WRONG_CHAR_IN_TAG_NAME);       		
       			}
       		break;
       		case CTAG:
       			if(!ifs.good())
       				return Result(line, ErrorType::UNEXPECTED_END_OF_STREAM);
       			if( nextChar == '>' )
       					state = IDLE;
       		break;
       		default:
       			return Result();
        }
    }

    if(!tags.empty()) {
		std::pair<string,int> tagp = tags.top();
		return Result(tagp.second, ErrorType::UNBALANCED_TAG);
    }

    return Result();
}
