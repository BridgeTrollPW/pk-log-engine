#include "ErrorHandler.h"

#include <sstream>
#include <string>
#include <typeinfo>

int ErrorHandler::processException(std::system_error exception)
{
        std::stringstream ss;
        ss << typeid(exception).name() << " -> " << exception.what();
        logger.error(ss.str());
        return exception.code().value();
}
