#include "Exception.h"

Exception::Exception()
{
        message = "";
        code = 0;
}

std::string Exception::getMessage() const
{
        return message;
}

void Exception::setMessage(std::string message)
{
        this->message = message;
}

int Exception::getCode() const
{
        return code;
}

void Exception::setCode(int code)
{
        this->code = code;
}
