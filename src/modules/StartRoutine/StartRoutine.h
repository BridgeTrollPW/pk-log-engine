#ifndef STARTROUTINE_H
#define STARTROUTINE_H

#include <fstream>

#include "../../util/logger/Logger.h"
#include "../../util/ErrorHandler.h"
#include "../../lib/json.hpp"
#include "../RuleProcessor/RuleProcessor.h"

using namespace util;
using namespace nlohmann;

class StartRoutine
{
public:
    StartRoutine(int argc, char **argv);
private:
    Logger logger = Logger("StartRoutine");
};

#endif /* STARTROUTINE_H */

