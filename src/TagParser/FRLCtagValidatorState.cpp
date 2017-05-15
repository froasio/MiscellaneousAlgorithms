#include "FRLCtagValidatorState.h"
#include "FRLValidatorContext.h"
#include "FRLIdleValidatorState.h"
#include "Result.h"
#include "ErrorType.h"

FRLCtagValidatorState::~FRLCtagValidatorState() {
	
}

void FRLCtagValidatorState::innerProcess(FRLValidatorContext &context) {

	if(!context.isGood())
		throw Result(context.getLine(), ErrorType::UNEXPECTED_END_OF_STREAM);

	if( nextChar == '>' ){
		context.setState(new FRLIdleValidatorState());	
			
	}
	
}