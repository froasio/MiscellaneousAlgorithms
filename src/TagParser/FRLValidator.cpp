#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include "FRLValidator.h"
#include "FRLValidatorContext.h"
#include "FRLIdleValidatorState.h"

bool FRLValidator::isValidCharacter(char c) {
	return c >= 'A' and c <= 'Z';
}

Result FRLValidator::parse(ifstream *ifsp) {

    FRLValidatorContext context(ifsp);
    context.setState(new FRLIdleValidatorState());

    try {
    
      while(context.process());
    
    } catch (Result result) {
    
      return result;
    
    }
      
    return Result();
}
