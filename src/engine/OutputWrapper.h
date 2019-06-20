//
// Created by bt on 20.06.19.
//

#ifndef LOG_ENGINE_OUTPUTWRAPPER_H
#define LOG_ENGINE_OUTPUTWRAPPER_H


#include <ostream>

class OutputWrapper
{
private:
    bool active;
    std::string buffer{};
public:
    OutputWrapper();
    friend std::ostream& operator<<(std::ostream& os, OutputWrapper& obj);
    void open();
    void push(const std::string &output);
    void close();
};


#endif //LOG_ENGINE_OUTPUTWRAPPER_H
