#include <stdio.h>

#include "modules/StartRoutine/StartRoutine.h"
#include "util/Exception.h"
#include "util/ErrorHandler.h"

int main(int argc, char **argv)
{
    try {
        StartRoutine s = StartRoutine();
    }
    catch(Exception& e) 
    {
        ErrorHandler handler;
        handler.processException(e);
    }
    return 0;
}
