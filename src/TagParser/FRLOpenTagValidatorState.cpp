#include "FRLOpenTagValidatorState.h"
#include "FRLValidatorContext.h"
#include "FRLIdleValidatorState.h"
#include "Result.h"
#include "ErrorType.h"

FRLOpenTagValidatorState::~FRLOpenTagValidatorState() {
	
}

void FRLOpenTagValidatorState::innerProcess(FRLValidatorContext &context) {

	if(!context.isGood())
		throw Result(context.getLine(), ErrorType::UNCLOSED_TAG);

	if(context.tagSize() < 1 or context.tagSize() > 10)
		throw Result(context.getLine(), ErrorType::WRONG_NUMBER_CHARS_IN_TAG);

	if( nextChar == '>' ) {

	    context.pushTag(make_pair(context.getTag(),context.getLine()));
		context.setState(std::unique_ptr<FRLIdleValidatorState>(new FRLIdleValidatorState()));
		
		
	} else if(isValidCharacter(nextChar)) {
	
		context.appendToTag(nextChar);
	
	} else {
	
		throw Result(context.getLine(), ErrorType::WRONG_CHAR_IN_TAG_NAME);
	
	}	
	
}
