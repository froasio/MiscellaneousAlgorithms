#include "FRLValidatorContext.h"

FRLValidatorContext::FRLValidatorContext(std::ifstream *in) : ifs(*in) {

	line = 1;
	state = NULL;

}

FRLValidatorContext::~FRLValidatorContext() {

	delete state;

}

int FRLValidatorContext::getLine() {

	return line;

}

void FRLValidatorContext::incrementLine() {

	line++;

}

std::string FRLValidatorContext::getTag() {

	return tag;

}

void FRLValidatorContext::clearTag() {

	tag.erase();

}

void FRLValidatorContext::appendToTag(char c) {

	tag+=c;

}

bool FRLValidatorContext::isEmptyTagStack() {

	return tags.empty();

}

void FRLValidatorContext::pushTag(std::pair<std::string,int> p) {

	tags.push(p);

}

std::pair<std::string,int> FRLValidatorContext::popTag() {

	std::pair<std::string,int> p = tags.top();
	tags.pop();
	return p;

}

char FRLValidatorContext::getNextChar() {

	return (char)ifs.get();

}

bool FRLValidatorContext::isGood(){

	return ifs.good();

}

size_t FRLValidatorContext::tagSize() {
	return tag.size();
}

bool FRLValidatorContext::process() {
	return state->process(*this);
}

void FRLValidatorContext::setState(FRLValidatorState *st) {
	delete state;
	state = st;
}