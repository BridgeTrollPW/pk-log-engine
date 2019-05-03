#include "Engine.h"

namespace engine
{

    Engine::Engine(model::EngineInput eIN): engineInput(eIN)
    {
        validate();
    }
    
    bool Engine::validate()
    {
        //TODO Validate Input
        logger.info("Starting ...");
    std::ifstream i(configFile);
    if (i.fail()) {
        logger.warn("Error loading config file " + configFile);
        logger.warn("Trying default config file");
        i = std::ifstream("config.json");
        if (i.fail()) {
            throw InvalidConfigException("Invalid Config", 0);
        }
    }

    i >> configuration;
    logger.info("Loaded config version " + configuration["version"].get<std::string>());

    }
}
