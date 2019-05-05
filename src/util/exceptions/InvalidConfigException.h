#ifndef INVALIDCONFIGEXCEPTION_H
#define INVALIDCONFIGEXCEPTION_H

#include "../Exception.h"

class InvalidConfigException : public Exception
{
private:
    std::string message;
    int code;
public:

    InvalidConfigException(std::string message, int code) :
    Exception(message, code)
    {
        this->message = message;
        this->code = code;
    }

};

#endif /* INVALIDCONFIGEXCEPTION_H */

