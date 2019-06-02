#include <adapter/TextSearch/TextSearchPayload.h>
#include <adapter/TextSearch/TextSearchPayloadSerializer.h>
#include <adapter/TextSearch/TextSearch.h>
#include <adapter/Categorization/Categorization.h>
#include <iostream>
#include "Dispatcher.h"

namespace engine {

    Dispatcher::Dispatcher(model::EngineInput eIN, std::string payload) :
            engineInput(eIN) {
        logger = new util::Logger("Dispatcher");
        validate(payload);
        initEngines();
        run();
        terminate();
    }

    void Dispatcher::validate(std::string payload) {

        logger->info("Validating input");

        if (engineInput.serverLogFile == "") {
            logger->error("No log file specified");
            throw std::system_error(std::error_code(404, std::system_category()),
                                    "The log file needs to be specified with the -l/-log CLI parameter");
        }

        if (engineInput.function == -1) {
            logger->error("No function was specified to be executed!");
            throw std::system_error(std::error_code(404, std::system_category()),
                                    "The engine function has to be specified by using the -f/-function CLI parameter");
        }
        engineInput.payload = payload;
    }

    void Dispatcher::initEngines() {
        logger->info("Initializing requested Engine Adapter");
        //executionList.push_back(new adapter::OptimizeMe());
        //optimize, do not sync standard input output
        std::ios_base::sync_with_stdio(false);
        //optimize, detach console input
        std::cin.tie(NULL);

        switch (engineInput.function) {
            case ENGINE_FUNCTION::SEARCH: {
                nlohmann::json jsonPayload = nlohmann::json::parse(engineInput.payload);
                TextSearchPayload stackAllocation = jsonPayload.get<TextSearchPayload>();
                executionList.push_back(new adapter::TextSearch(engineInput.serverLogFile, stackAllocation));
                break;
            }
            case ENGINE_FUNCTION::SEARCH_AND_CATEGORIZE: {
                executionList.push_back(new adapter::Categorization());
                break;
            }
            case ENGINE_FUNCTION::CLIENT_UPTIME: {
                //executionList.push_back(new adapter::ClientUpTime(engineInput.serverLogFile, engineInput.searchStrings));
                break;
            }
            default: {
                logger->warn("Engine function " + std::to_string(engineInput.function) + " is not implemented");
                break;
            }
        }

        for (IEngineAdapter *engine : executionList) {
            logger->info("Loaded " + engine->getName() + " into executionList");
        }
    }

    void Dispatcher::run() {
        for (IEngineAdapter *engine : executionList) {
            logger->info("Running " + engine->getName() + " Engine  Adapter");
            engine->run();
        }
    }

    void Dispatcher::terminate() {
        logger->info("Terminating Engine Routine");
        logger->info("Engine stopped");
    }
};
