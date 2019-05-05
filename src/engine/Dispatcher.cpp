#include "Dispatcher.h"
#include "adapter/Categorisation/Categorisation.h"
#include "adapter/TextSearch/TextSearch.h"

namespace engine
{

Dispatcher::Dispatcher(model::EngineInput eIN) :
        engineInput(eIN)
{
    logger.info("Starting Engine Dispatcher");
    validate();
    execAdapter();
    terminate();
}

void Dispatcher::validate()
{
    logger.info("Validating input");
    std::ifstream i(engineInput.configFile);
    if (i.fail())
    {
        logger.warn("Error loading config file " + engineInput.configFile);
        logger.warn("Trying default config file");
        i = std::ifstream("config.json");
        if (i.fail())
        {
            throw InvalidConfigException("Invalid Config", 0);
        }
    }
    i >> configuration;
    logger.info(
            "Loaded config version "
                    + configuration["version"].get<std::string>());

    if (engineInput.serverLogFile == "")
    {
        logger.error("No log file specified");
        throw InvalidArgumentException(
                "The log file needs to be specified with the -l/-log cli parameter",
                404);
    }
}

void Dispatcher::execAdapter()
{
    logger.info("Executing requested Engine Adapter");
    switch (engineInput.function)
    {
    case ENGINE_FUNCTION::SEARCH:
    {
        executionList.push_back(new adapter::TextSearch());
        break;
    }
    default:
    {
        logger.warn("Engine function " + std::to_string(engineInput.function) + " is not implemented");
        break;
    }
    }
}

void Dispatcher::terminate()
{
    logger.info("Terminating Engine Routine");
    logger.info("Engine stopped");
}
}
;
