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

void OutputWrapper::close(bool removeLastChar)
{
    std::cout << "]";
}

