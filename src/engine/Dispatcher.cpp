#include "Dispatcher.h"

#include <fstream>
#include <string>

#include "../util/exceptions/InvalidArgumentException.h"
#include "../util/exceptions/InvalidConfigException.h"
#include "adapter/ClientUpTime/ClientUpTime.h"
#include "adapter/OptimizeMe/OptimizeMe.h"
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
        //executionList.push_back(new adapter::OptimizeMe());
        //optimize, do not sync standard input output
        std::ios_base::sync_with_stdio(false);
        //optimize, detach console input
        std::cin.tie(NULL);

        switch (engineInput.function)
        {
            case ENGINE_FUNCTION::SEARCH:
                {
                executionList.push_back(new adapter::TextSearch(engineInput.serverLogFile, engineInput.searchStrings));
                break;
            }
            case ENGINE_FUNCTION::CLIENT_UPTIME:
                {
                executionList.push_back(new adapter::ClientUpTime(engineInput.serverLogFile, engineInput.searchStrings));
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
