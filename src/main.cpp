#include <stdio.h>

#include "src/modules/StartRoutine/StartRoutine.h"
#include "util/Exception.h"
#include "util/ErrorHandler.h"

int main(int argc, char **argv)
{
    try {
        StartRoutine s(argc, argv);
    }
    catch(Exception& e) 
    {
        ErrorHandler handler;
        handler.processException(e);
    }
    return 0;
}
