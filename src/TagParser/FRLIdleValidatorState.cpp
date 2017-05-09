#include "FRLIdleValidatorState.h"
#include "FRLValidatorContext.h"
#include "FRLTagInitValidatorState.h"
#include "FRLEndFileValidatorState.h"
#include "Result.h"
#include "ErrorType.h"

FRLIdleValidatorState::~FRLIdleValidatorState() {
	
}

void FRLIdleValidatorState::innerProcess(FRLValidatorContext &context) {
	
	context.clearTag();

	if(!context.isGood()) {
		context.setState(new FRLEndFileValidatorState());
		delete this;
		return;
	}

	if( nextChar == '>')
		throw Result(context.getLine(), ErrorType::UNEXPECTED_CLOSING_TAG_CHAR);
	if( nextChar == '<'){
		context.setState(new FRLTagInitValidatorState());
		delete this;
	}

}