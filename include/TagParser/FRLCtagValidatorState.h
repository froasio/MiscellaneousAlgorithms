#ifndef FRL_CTAG_VALIDATOR_STATE_H
#define FRL_CTAG_VALIDATOR_STATE_H
#include "FRLValidatorState.h"

class  FRLCtagValidatorState : public FRLValidatorState {
public:
	virtual ~FRLCtagValidatorState();
	void innerProcess(FRLValidatorContext &context);
};


#endif //FRL_CTAG_VALIDATOR_STATE_H