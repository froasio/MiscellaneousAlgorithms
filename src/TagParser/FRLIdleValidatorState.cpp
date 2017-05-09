#include "FRLIdleValidatorState.h"
#include "FRLValidatorContext.h"
#include "FRLTagInitValidatorState.h"
#include "Result.h"
#include "ErrorType.h"

FRLIdleValidatorState::~FRLIdleValidatorState() {
	
}

void FRLIdleValidatorState::innerProcess(FRLValidatorContext &context) {
	
	context.clearTag();
	
	if(!context.isGood() and !context.isEmptyTagStack()) {
  		std::pair<string,int> tagp = context.popTag();
  		throw Result(tagp.second, ErrorType::UNBALANCED_TAG);
	}

	if( nextChar == '>')
		throw Result(context.getLine(), ErrorType::UNEXPECTED_CLOSING_TAG_CHAR);
	if( nextChar == '<'){
		context.setState(new FRLTagInitValidatorState());
		delete this;
	}

}