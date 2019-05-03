#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

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
