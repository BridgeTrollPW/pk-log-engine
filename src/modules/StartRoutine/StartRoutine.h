#ifndef STARTROUTINE_H
#define STARTROUTINE_H

#include "../../util/logger/Logger.h"

using namespace util;

class StartRoutine
{
        public:
                StartRoutine(int argc, char **argv);
        private:
                Logger logger = Logger("StartRoutine");
};

#endif /* STARTROUTINE_H */

