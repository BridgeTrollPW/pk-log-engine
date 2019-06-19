#ifndef ENGINEINPUT_H
#define ENGINEINPUT_H

#include <string>

struct EngineInput
{
public:
    int function = -1;
    std::string serverLogFile = "";
    std::string payload;
    std::string configPath = "";
    bool prettyPrinting = false;
};
#endif /* ENGINEINPUT_H */