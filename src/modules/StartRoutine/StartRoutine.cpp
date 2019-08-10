#include "StartRoutine.h"

#include <iostream>
#include <string>
#include <Dispatcher.h>

void from_json(const nlohmann::json &j, EngineInput &e)
{
    j.at("function").get_to(e.function);
    j.at("serverLogFile").get_to(e.serverLogFile);
    j.at("configFile").get_to(e.configPath);
    e.payload = j.value("payload", "");
    e.prettyPrinting = j.value("prettyPrinting", false);
}

StartRoutine::StartRoutine(const std::string &stdInput)
{
    nlohmann::json jsonHND = nlohmann::json::parse(stdInput);
    EngineInput eIN = jsonHND.get<EngineInput>();
    new Config(eIN.configPath);

    Dispatcher d = Dispatcher(eIN);
}
