#ifndef FRL_OPEN_TAG_VALIDATOR_STATE_H
#define FRL_OPEN_TAG_VALIDATOR_STATE_H
#include "FRLValidatorState.h"

class  FRLOpenTagValidatorState : public FRLValidatorState {
public:
	virtual ~FRLOpenTagValidatorState();
	void innerProcess(FRLValidatorContext &context);
};


#endif //FRL_OPEN_TAG_VALIDATOR_STATE_H