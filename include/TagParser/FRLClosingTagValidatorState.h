#ifndef FRL_CLOSING_TAG_VALIDATOR_STATE_H
#define FRL_CLOSING_TAG_VALIDATOR_STATE_H
#include "FRLValidatorState.h"

class  FRLClosingTagValidatorState : public FRLValidatorState {
public:
	virtual ~FRLClosingTagValidatorState();
	void innerProcess(FRLValidatorContext &context);
};


#endif //FRL_CLOSING_TAG_VALIDATOR_STATE_H