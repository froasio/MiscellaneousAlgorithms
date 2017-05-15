#include "FRLTagInitValidatorState.h"
#include "FRLValidatorContext.h"
#include "FRLClosingTagValidatorState.h"
#include "FRLCtagValidatorState.h"
#include "FRLOpenTagValidatorState.h"
#include "Result.h"
#include "ErrorType.h"

FRLTagInitValidatorState::~FRLTagInitValidatorState() {

}

void FRLTagInitValidatorState::innerProcess(FRLValidatorContext &context) {
	
	if(!context.isGood())
		throw Result(context.getLine(), ErrorType::UNCLOSED_TAG);
	
	if( nextChar == '>' )
		throw Result(context.getLine(), ErrorType::WRONG_NUMBER_CHARS_IN_TAG);
	
	else if( nextChar == '/' ) {
		context.setState(new FRLClosingTagValidatorState());
		
	}

	else if ( nextChar == '!' ) {
		context.setState(new FRLCtagValidatorState());
		
	}
	
	else if(isValidCharacter(nextChar)) {
		context.appendToTag(nextChar);
		context.setState(new FRLOpenTagValidatorState());
		
	} else {
		throw Result(context.getLine(), ErrorType::WRONG_CHAR_IN_TAG_NAME);
	}

}
