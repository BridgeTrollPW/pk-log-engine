#include "Dispatcher.h"

#include <fstream>
#include <string>

#include "../util/exceptions/InvalidArgumentException.h"
#include "../util/exceptions/InvalidConfigException.h"
#include "adapter/TextSearch/TextSearch.h"

namespace engine
{

    Dispatcher::Dispatcher(model::EngineInput eIN) :
            engineInput(eIN)
    {
        logger.info("Starting Engine Dispatcher");
        validate();
        initEngines();
        run();
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
        logger.info("Loaded config version " + configuration["version"].get<
                std::string>());

        if (engineInput.serverLogFile == "")
        {
            logger.error("No log file specified");
            throw InvalidArgumentException("The log file needs to be specified with the -l/-log CLI parameter", 404);
        }

        if (engineInput.function == -1)
        {
            logger.error("No function was specified to be executed!");
            throw InvalidArgumentException("The engine function has to be specified by using the -f/-function CLI parameter", 404);
        }
    }

    void Dispatcher::initEngines()
    {
        logger.info("Initializing requested Engine Adapter");
        switch (engineInput.function)
        {
            case ENGINE_FUNCTION::SEARCH:
            {
                executionList.push_back(new adapter::TextSearch(engineInput.serverLogFile, engineInput.searchStrings));
                break;
            }
            default:
            {
                logger.warn("Engine function " + std::to_string(engineInput.function) + " is not implemented");
                break;
            }
        }

        for (IEngineAdapter* engine : executionList)
        {
            logger.info("Loaded " + engine->getName() + " into executionList");
        }
    }

    void Dispatcher::run()
    {
        for (IEngineAdapter* engine : executionList)
        {
            logger.info("Running " + engine->getName() + " Engine  Adapter");
            engine->run();
        }
    }

    void Dispatcher::terminate()
    {
        logger.info("Terminating Engine Routine");
        logger.info("Engine stopped");
    }
}
;
