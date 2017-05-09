#ifndef FRL_END_FILE_VALIDATOR_STATE_H
#define FRL_END_FILE_VALIDATOR_STATE_H
#include "FRLValidatorState.h"

class  FRLEndFileValidatorState : public FRLValidatorState {
public:
	virtual ~FRLEndFileValidatorState();
	void innerProcess(FRLValidatorContext &context);
};


#endif //FRL_END_FILE_VALIDATOR_STATE_H