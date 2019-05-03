/* 
 * File:   InvalidConfigException.h
 * Author: bt
 *
 * Created on 1. Mai 2019, 19:54
 */

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
        message = message;
        code = code;
    }

};

#endif /* INVALIDCONFIGEXCEPTION_H */

