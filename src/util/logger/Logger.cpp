#include "Logger.h"

#include <bits/types/struct_tm.h>
#include <bits/types/time_t.h>
#include <ctime>
#include <fstream>

using namespace util;

void Logger::log(std::string level, std::string msg)
{
    std::ofstream logFile("/home/bt/checkout/log-engine/resources/" + currentDate() + ".log", std::ios::out | std::ios::app | std::ios::binary);
    if (logFile.is_open())
    {
        logFile << "[" << currentDateTime() << "] [" << level << "] " << "[" << className << "]" << " :: " << msg << "\n";
    }
    else
    {

    }
    logFile.close();
}

void Logger::debug(std::string msg)
{
    log(Logger::LEVEL_DEBUG, msg);
}

void Logger::error(std::string msg)
{
    log(Logger::LEVEL_ERROR, msg);
}

void Logger::info(std::string msg)
{
    log(Logger::LEVEL_INFO, msg);
}

void Logger::warn(std::string msg)
{
    log(Logger::LEVEL_WARN, msg);
}

std::string Logger::currentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y.%m.%d - %X", &tstruct);

    return (buf);
}

std::string Logger::currentDate()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y.%m.%d", &tstruct);

    return (buf);
}
