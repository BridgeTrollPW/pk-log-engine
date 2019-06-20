//
// Created by bt on 20.06.19.
//

#include <iostream>
#include "OutputWrapper.h"

OutputWrapper::OutputWrapper()
{
    active = false;
}

void OutputWrapper::open()
{
    active = true;
}

std::ostream &operator<<(std::ostream &os, OutputWrapper &obj)
{
    obj.open();
    std::cout << "[";
    return os;
}

void OutputWrapper::close()
{
    std::cout << "]";
    active = false;
}

void OutputWrapper::push(const std::string &output)
{
    //Empty buffer is interpreted as that the current output stream is still used by a json element that did
    // not fit (or similar) into one stream ouptu
    if (!buffer.empty())
    {
        std::cout << ',';
    }
    std::cout << buffer;
    buffer = output;
}
