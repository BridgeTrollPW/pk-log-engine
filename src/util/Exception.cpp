#include "Exception.h"

Exception::Exception()
{
    message = "";
    code = 0;
}

std::string Exception::getMessage()
{
    return message;
}

void Exception::setMessage(std::string message)
{
    message = message;
}

int Exception::getCode()
{
    return code;
}

void Exception::setCode(int code)
{
    code = code;
}