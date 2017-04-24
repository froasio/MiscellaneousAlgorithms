#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include "FRLValidator.h"
#include "FRLValidatorContext.h"

bool FRLValidator::isValidCharacter(char c) {
	return c >= 'A' and c <= 'Z';
}

Result FRLValidator::parse(ifstream *ifsp) {
	  ValidatorState state = IDLE;
    FRLValidatorContext context(ifsp);

    char nextChar;

    while (context.isGood()) {
       
    	nextChar = context.getNextChar();

        if( nextChar == '\n' )
        	context.incrementLine();

        switch( state ) {
        	case IDLE:
        		context.clearTag();
        		if( nextChar == '>')
        			return Result(context.getLine(), ErrorType::UNEXPECTED_CLOSING_TAG_CHAR);
        		if( nextChar == '<')
        			state = FRLValidator::TAG_INIT;
        	break;
       		case TAG_INIT:
       			if(!context.isGood())
       				return Result(context.getLine(), ErrorType::UNCLOSED_TAG);
       			if( nextChar == '/')
       				state = CLOSING_TAG;
       			else if ( nextChar == '!')
       				state = CTAG;
       			else if( nextChar == '>')
       				return Result(context.getLine(), ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
       			else if(isValidCharacter(nextChar)) {
	       			state = FRLValidator::OPEN_TAG;
	       			context.appendToTag(nextChar);
       			} else {
       				return Result(context.getLine(), ErrorType::WRONG_CHAR_IN_TAG_NAME);
       			}
       		break;
       		case OPEN_TAG:
       			if(!context.isGood())
       				return Result(context.getLine(), ErrorType::UNCLOSED_TAG);
       			if( nextChar == '>' ) {
       				if(context.tagSize() >= 1 and context.tagSize() <= 10) {
       					state = IDLE;
                context.pushTag(make_pair(context.getTag(),context.getLine()));
       				}
       				else
       					return Result(context.getLine(), ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
       			} else if(isValidCharacter(nextChar)) {
	       			context.appendToTag(nextChar);
       			} else {
       				return Result(context.getLine(), ErrorType::WRONG_CHAR_IN_TAG_NAME);
       			}
       		break;
       		case CLOSING_TAG:
       			if(!context.isGood())
       				return Result(context.getLine(), ErrorType::UNCLOSED_TAG);
       			if( nextChar == '>' ) {
       				if(context.tagSize() >= 1 and context.tagSize() <= 10) {
       					state = IDLE;
       					std::pair<string,int> tagp = context.popTag();
       					if(tagp.first != context.getTag()) {
       						return Result(context.getLine(), ErrorType::UNBALANCED_TAG);
       					}
       				}
       				else
       					return Result(context.getLine(), ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
       			} else if(isValidCharacter(nextChar)) {
	       			context.appendToTag(nextChar);
       			} else {
       				return Result(context.getLine(), ErrorType::WRONG_CHAR_IN_TAG_NAME);       		
       			}
       		break;
       		case CTAG:
       			if(!context.isGood())
       				return Result(context.getLine(), ErrorType::UNEXPECTED_END_OF_STREAM);
       			if( nextChar == '>' )
       					state = IDLE;
       		break;
       		default:
       			return Result();
        }
    }

    if(!context.isEmptyTagStack()) {
  		std::pair<string,int> tagp = context.popTag();
  		return Result(tagp.second, ErrorType::UNBALANCED_TAG);
    }

    return Result();
}
