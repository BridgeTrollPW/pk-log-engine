#ifndef ERRORCODES_H
#define ERRORCODES_H

#include "Exception.h"
#include "logger/Logger.h"

class ErrorHandler
{
        public:
                int processException(Exception exception);
        private:
                util::Logger logger = util::Logger("ErrorHandler");
};
#endif // ERRORCODES_H

