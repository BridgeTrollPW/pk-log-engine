#include <adapter/TextSearch/TextSearchPayload.h>
#include <iostream>
#include <adapter/TextSearch/TextSearch.h>
#include <adapter/Categorization/Categorization.h>
#include "Dispatcher.h"
#include <future>
#include <adapter/STDOutput.h>

Dispatcher::Dispatcher(const EngineInput &eIN) :
        engineInput(eIN) {
    logger = new util::Logger("Dispatcher");
    validate(eIN.payload);
    initEngines();
    run();
    terminate();
}

void Dispatcher::validate(const std::string &payload) {

    logger->info("Validating input");

    if (engineInput.serverLogFile.empty()) {
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
    std::cin.tie(nullptr);

    switch (engineInput.function) {
        case ENGINE_FUNCTION::SEARCH: {
            nlohmann::json jsonPayload = nlohmann::json::parse(engineInput.payload);
            TextSearchPayload stackAllocation;
            stackAllocation.fromJson(jsonPayload);
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
    AsyncExecutionBuffer asyncExecutionBuffer;
    adapter::STDOutput stdOutput;

    /*std::future<void> outputConsumer = std::async(std::launch::async,
                                                  [&asyncExecutionBuffer, &stdOutput]() -> void {
                                                      return stdOutput.run(std::ref(asyncExecutionBuffer));
                                                  });*/
    std::thread outputConsumer(&IEngineAdapter::run, &stdOutput, std::ref(asyncExecutionBuffer));

    /*std::list<std::thread*> threadList;
    for (IEngineAdapter *engine : executionList) {
        logger->info("Running " + engine->getName() + " Engine  Adapter");
        //engine->run();
        /*std::future<void> fExecution = std::async(std::launch::async, [&engine, &asyncExecutionBuffer]() -> void {
            return engine->run(std::ref(asyncExecutionBuffer));
        });
        std::thread executeEngine(&IEngineAdapter::run, engine, std::ref(asyncExecutionBuffer));
        threadList.emplace_back(&executeEngine);
    }
    for (auto &future : threadList) {
        future->join();
    }
    stdOutput.shutdown(); */
    //outputConsumer.join();
}

void Dispatcher::terminate() {
    logger->info("Terminating Engine Routine");
    logger->info("Engine stopped");
}
