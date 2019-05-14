#include <iostream>

#include "modules/StartRoutine/StartRoutine.h"
#include "util/ErrorHandler.h"
#include "util/Exception.h"

int main(int argc, char **argv)
{
    try
    {
        StartRoutine s(argc, argv);
    }
    catch (Exception& e)
    {
        ErrorHandler handler;
        return (handler.processException(e));
    }
    return (0);
}
