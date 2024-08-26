using namespace std;

#include "MemberVariableUnsetException.h"

MemberVariableUnsetException::MemberVariableUnsetException(const char* memberVariable) : memberVariable(memberVariable) {}

const char *MemberVariableUnsetException::what() const noexcept {
    return "Member Variable Unset";
}
