#ifndef INVALIDARGUMENTEXCEPTION_H
#define INVALIDARGUMENTEXCEPTION_H

#include "../Exception.h"

class InvalidArgumentException : public Exception
{
private:
    std::string message;
    int code;
public:

    InvalidArgumentException(std::string message, int code) :
    Exception(message, code)
    {
        this->message = message;
        this->code = code;
    }

};

#endif /* INVALIDARGUMENTEXCEPTION_H */

