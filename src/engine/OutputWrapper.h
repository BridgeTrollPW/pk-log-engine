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
public:
    OutputWrapper();
    friend std::ostream& operator<<(std::ostream& os, OutputWrapper& obj);
    void open();
    void push(std::string);
    void close(bool removeLastChar);
};


#endif //LOG_ENGINE_OUTPUTWRAPPER_H
