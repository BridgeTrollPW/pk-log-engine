#include <iostream>

#include "modules/StartRoutine/StartRoutine.h"
#include "util/ErrorHandler.h"

int main(int argc, char **argv)
{
    try
    {
        StartRoutine s(argc, argv);
    }
    catch (std::system_error& e)
    {
        ErrorHandler handler;
        return (handler.processException(e));
    }
    return (0);
}
