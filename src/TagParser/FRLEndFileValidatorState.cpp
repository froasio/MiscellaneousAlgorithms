#include "FRLEndFileValidatorState.h"
#include "FRLValidatorContext.h"
#include "Result.h"
#include "ErrorType.h"

FRLEndFileValidatorState::~FRLEndFileValidatorState() {
	
}

void FRLEndFileValidatorState::innerProcess(FRLValidatorContext &context) {

    if(!context.isEmptyTagStack()) {
  		std::pair<string,int> tagp = context.popTag();
  		throw Result(tagp.second, ErrorType::UNBALANCED_TAG);
    }
    delete this;
}