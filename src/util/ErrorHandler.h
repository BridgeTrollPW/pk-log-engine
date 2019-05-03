#ifndef ERRORCODES_H
#define ERRORCODES_H

#include "logger/Logger.h"
#include "Exception.h"

class ErrorHandler 
{
public:
    int processException(Exception exception);
private:
    util::Logger logger;
};
#endif // ERRORCODES_H

