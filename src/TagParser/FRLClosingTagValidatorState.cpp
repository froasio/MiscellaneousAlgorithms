#include "FRLClosingTagValidatorState.h"
#include "FRLValidatorContext.h"
#include "FRLIdleValidatorState.h"
#include "Result.h"
#include "ErrorType.h"

FRLClosingTagValidatorState::~FRLClosingTagValidatorState() {
	
}

void FRLClosingTagValidatorState::innerProcess(FRLValidatorContext &context) {

	if(!context.isGood())
		throw Result(context.getLine(), ErrorType::UNCLOSED_TAG);
	if(context.tagSize() > 10)
		throw Result(context.getLine(), ErrorType::WRONG_NUMBER_CHARS_IN_TAG);

	if( nextChar == '>' ) {
		
		std::pair<string,int> tagp = context.popTag();
		if(tagp.first != context.getTag()) {
			throw Result(context.getLine(), ErrorType::UNBALANCED_TAG);
		}
		context.setState(new FRLIdleValidatorState());
		delete this;
		
	} else if(isValidCharacter(nextChar)) {
	
		context.appendToTag(nextChar);
	
	} else {
	
		throw Result(context.getLine(), ErrorType::WRONG_CHAR_IN_TAG_NAME);
	
	}	

}
