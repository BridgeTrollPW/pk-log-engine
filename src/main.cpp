#include <iostream>

#include "modules/StartRoutine/StartRoutine.h"
#include "util/ErrorHandler.h"

int main(int argc, char **argv)
{
    std::istreambuf_iterator<char> begin(std::cin), end;
    std::string rawInput(begin, end);
    try
    {
        StartRoutine s(rawInput);
    }
    catch (std::system_error &e)
    {
        ErrorHandler handler;
        return (handler.processException(e));
    }
    return 0;
}
