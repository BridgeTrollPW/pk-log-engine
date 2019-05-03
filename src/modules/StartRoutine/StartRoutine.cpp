#include <iostream>
#include <fstream>
#include <list>
#include <limits>
#include <string>
#include <chrono>

#include "../header/StartRoutine.h"
#include "../../../util/exceptions/InvalidConfigException.h"
#include "../../../util/exceptions/InvalidArgumentException.h"
#include "../../RuleProcessor/header/Rule.h"

#include "../../core/Engine.h"
#include "../../core/model/EngineInput.h"

using json = nlohmann::json;
using core::Engine;
using core::model::EngineInput;

StartRoutine::StartRoutine(int argc, char **argv)
{
    EngineInput eIN;


    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-help" || std::string(argv[i]) == "-h" || std::string(argv[i]) == "-?") {
            std::cout << "" << std::endl;
        }
        else if (std::string(argv[i]) == "-function" || std::string(argv[i]) == "-f") {
            if (i + 1 < argc) {
                eIN.function = std::stoi(argv[++i]);
            }
            else {
                throw InvalidArgumentException("-config/-c option requires one argument.", 1);
            }
        }
        else if (std::string(argv[i]) == "-config" || std::string(argv[i]) == "-c") {
            if (i + 1 < argc) {
                eIN.configFile = argv[++i];
            }
            else {
                throw InvalidArgumentException("-config/-c option requires one argument.", 1);
            }
        }
        else if (std::string(argv[i]) == "-log" || std::string(argv[i]) == "-l") {
            if (i + 1 < argc) {
                eIN.serverLogFile = argv[++i];
            }
            else {
                throw InvalidArgumentException("-log/-l option requires one argument.", 1);
            }
        }
        else if (std::string(argv[i]) == "-search" || std::string(argv[i]) == "-s") {
            if (i + 1 < argc) {
                eIN.searchStrings = argv[++i];
            }
            else {
                throw InvalidArgumentException("-search/-s option requires one argument.", 1);
            }
        }
        else if (std::string(argv[i]) == "-lines" || std::string(argv[i]) == "-ls") {
            if (i + 1 < argc) {
                eIN.linePairs = argv[++i];
            }
            else {
                throw InvalidArgumentException("-lines/-ls option requires one argument.", 1);
            }
        }
        else if (std::string(argv[i]) == "-pretty-printing" || std::string(argv[i]) == "-p") {
            eIN.prettyPrinting = true;
        }
    }


    Engine engine = Engine(eIN);
    /*logger.info("Starting ...");
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


        logger.info("Preparing rules...");
    prepareRules();
    logger.info("Loading log file");
    logFileHND = std::ifstream(serverLogFile);
    if (logFileHND.fail()) {
        logger.error("error reading server log file " + serverLogFile);
    }
    logger.info("Starting to parse logs");
    parseLogs(searchString);
    logger.info("Shutdown...");*/
}

void StartRoutine::prepareRules()
{
    std::list<Rule> rules;

    for (auto& el : configuration.at("rules").items()) {
        std::map<int, std::string> matchings;

        for (auto& group : el.value().at("groups").items()) {
            int key;
            group.value().at(0).get_to(key);
            matchings[key] = group.value().at(1);
        }


        //for(auto& matching : el.value().at("groups").items())
        //{
        //    matchings[std::stoi(matching.key())] = matching.value();
        //}

        Rule rule = Rule(
                         el.value().at("name"),
                         el.value().at("regex"),
                         matchings
                         );
        rules.push_back(rule);
    }
    ruleProcessor.setRules(rules);

    logger.info("Rules loaded from config");
}

void StartRoutine::parseLogs(std::string searchString)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int lineStart = 0;
    logger.info("checking for search " + searchString);
    if (!searchString.empty()) {
        int curLine = 0;
        std::string line;
        while (getline(logFileHND, line)) { // I changed this, see below
            curLine++;
            if (line.find(searchString, 0) != std::string::npos) {
                lineStart = curLine;
                logger.info("found search string @ " + curLine);
                break;
            }
        }
    }

    logFileHND.seekg(std::ios::beg);
    logger.info("starting parser @ " + std::to_string(lineStart));
    for (int i = 0; i < lineStart - 1; ++i) {
        logFileHND.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string line;
    json out;
    std::list<json> output;
    while (std::getline(logFileHND, line)) {
        Result r = ruleProcessor.processLine(line);
        json j;
        r.to_json(j);
        //output.push_back(j);
        std::cout << j << std::endl;
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    logger.info("parsed " + std::to_string(output.size()) + " log entries within " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()) + " ms");
    json json_list(output);
    if (prettyPrinting) {
        std::cout << json_list.dump(4) << std::endl;
    }
    else {
        std::cout << json_list;
    }
}