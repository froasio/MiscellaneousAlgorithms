#ifndef FRL_IDLE_VALIDATOR_STATE_H
#define FRL_IDLE_VALIDATOR_STATE_H
#include "FRLValidatorState.h"

class  FRLIdleValidatorState : public FRLValidatorState {
public:
	virtual ~FRLIdleValidatorState();
	void innerProcess(FRLValidatorContext &context);
};


#endif //FRL_IDLE_VALIDATOR_STATE_H
