#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <fstream>

namespace util {

    class Logger {
    public:
        const std::string LEVEL_ERROR = "ERROR";
        const std::string LEVEL_WARN = "WARN";
        const std::string LEVEL_DEBUG = "DEBUG";
        const std::string LEVEL_INFO = "INFO";

        void error(std::string msg);
        void warn(std::string msg);
        void debug(std::string msg);
        void info(std::string msg);

    private:
        void log(std::string level, std::string msg);
        std::string currentDateTime();
        std::string currentDate();
    };
}
#endif /* LOGGER_H */

