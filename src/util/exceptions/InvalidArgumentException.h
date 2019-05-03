/* 
 * File:   InvalidArgumentException.h
 * Author: bt
 *
 * Created on 1. Mai 2019, 19:54
 */

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
        message = message;
        code = code;
    }

};

#endif /* INVALIDARGUMENTEXCEPTION_H */

