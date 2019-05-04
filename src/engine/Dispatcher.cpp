#include "Dispatcher.h"
#include "adapter/Categorisation/Categorisation.h"
#include "adapter/TextSearch/TextSearch.h"

namespace engine
{

    Dispatcher::Dispatcher(model::EngineInput eIN): engineInput(eIN)
    {
        validate();
        execAdapter();
    }
    
    bool Dispatcher::validate()
    {
        logger.info("Starting ...");
        std::ifstream i(engineInput.configFile);
        if (i.fail()) {
        logger.warn("Error loading config file " + engineInput.configFile);
        logger.warn("Trying default config file");
        i = std::ifstream("config.json");
        if (i.fail()) 
            {
                throw InvalidConfigException("Invalid Config", 0);
            }
        }
        i >> configuration;
        logger.info("Loaded config version " + configuration["version"].get<std::string>());
    }
    
    void Dispatcher::execAdapter()
    {
        
        switch(engineInput.function)
        {
            case ENGINE_FUNCTION::SEARCH:
                executionList.push_back(adapter::TextSearch());
            break;
            case ENGINE_FUNCTION::SEARCH_AND_CATEGORIZE:
                executionList.push_back(TextSearch());
                executionList.push_back(Categorisation());
            break;
            case ENGINE_FUNCTION::RETURN_RAW
            break;
            default:
            break;
        }
    }
}
