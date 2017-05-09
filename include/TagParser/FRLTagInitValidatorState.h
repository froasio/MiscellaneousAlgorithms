#ifndef FRL_TAG_INIT_VALIDATOR_STATE_H
#define FRL_TAG_INIT_VALIDATOR_STATE_H
#include "FRLValidatorState.h"

class  FRLTagInitValidatorState : public FRLValidatorState {
public:
	~FRLTagInitValidatorState();
	void innerProcess(FRLValidatorContext &context);
};


#endif //FRL_TAG_INIT_VALIDATOR_STATE_H
