#include "Logger.h"

#include <bits/types/struct_tm.h>
#include <bits/types/time_t.h>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <iostream>

using namespace util;

void Logger::log(const std::string &level, const std::string &msg)
{
    std::string logPath{""};
    if (Config::getConfig().contains("core"))
    {
        logPath = Config::getConfig().at("core")["logPath"];
    }
    else
    {
        char buff[FILENAME_MAX];
        getcwd(buff, FILENAME_MAX);
        logPath = std::string{buff};
    }

    std::ofstream logFile(logPath + "/engine" + currentDate() + ".log",
                          std::ios::out | std::ios::app | std::ios::binary);
    if (logFile.is_open())
    {
        logFile << "[" << currentDateTime() << "] [" << level << "] " << "[" << className << "]" << " :: " << msg
                << "\n";
    }
    else
    {

    }
    logFile.close();
}

void Logger::debug(const std::string &msg)
{
    log(Logger::LEVEL_DEBUG, msg);
}

void Logger::error(const std::string &msg)
{
    log(Logger::LEVEL_ERROR, msg);
}

void Logger::info(const std::string &msg)
{
    log(Logger::LEVEL_INFO, msg);
}

void Logger::warn(const std::string &msg)
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
    struct tm tstruct{};
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y.%m.%d", &tstruct);

    return (buf);
}
