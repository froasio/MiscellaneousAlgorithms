#include "FRLValidatorState.h"
#include "FRLValidatorContext.h"

FRLValidatorState::~FRLValidatorState() {

}

bool FRLValidatorState::process(FRLValidatorContext &context) {
   	nextChar = context.getNextChar();

    if( nextChar == '\n' )
    	context.incrementLine();

    innerProcess(context);
    return context.isGood();	
}

bool FRLValidatorState::isValidCharacter(char c) {
	return c >= 'A' and c <= 'Z';
}

