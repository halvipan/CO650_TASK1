#ifndef CO650_TASK1_MEMBERVARIABLEUNSETEXCEPTION_H
#define CO650_TASK1_MEMBERVARIABLEUNSETEXCEPTION_H


#include <exception>
#include <string>

using namespace std;

class MemberVariableUnsetException : public exception {
public:
    MemberVariableUnsetException() = default;
    MemberVariableUnsetException(const char* memberVariable);
    const char* what() const noexcept override;
    const char* memberVariable;
};


#endif //CO650_TASK1_MEMBERVARIABLEUNSETEXCEPTION_H
