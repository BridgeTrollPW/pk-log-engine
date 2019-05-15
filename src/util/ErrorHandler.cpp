#include "ErrorHandler.h"

#include <sstream>
#include <string>
#include <typeinfo>

int ErrorHandler::processException(Exception exception)
{
        std::stringstream ss;
        ss << typeid(exception).name() << " -> " << exception.getMessage();
        logger.error(ss.str());
        return (exception.getCode());
}
