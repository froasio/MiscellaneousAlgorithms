#ifndef FRL_VALIDATOR_STATE_H
#define FRL_VALIDATOR_STATE_H

class FRLValidatorContext;
class FRLValidatorState {

public:
    bool process(FRLValidatorContext &context);
	char nextChar;
	bool isValidCharacter(char c);
	virtual void innerProcess(FRLValidatorContext &context) = 0;
	virtual ~FRLValidatorState();
};


#endif //FRL_VALIDATOR_STATE_H
