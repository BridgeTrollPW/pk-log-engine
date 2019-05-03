#include <string>
/* 
 * File:   Exception.h
 * Author: bt
 *
 * Created on 1. Mai 2019, 19:47
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
private:
    std::string message;
    int code;

public:
    Exception();
    Exception(std::string message);
    Exception(std::string message, int code): message(message), code(code) {};

    std::string getMessage();
    void setMessage(std::string) ;

    int getCode();
    void setCode(int code);

};

#endif /* EXCEPTION_H */