/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * Categorization.h
 *
 *  Created on: 18.05.2019
 *      Author: bt
 */
#ifndef CATEGORIZATION_H
#define CATEGORIZATION_H

#include <list>
#include <string>
#include <interface/IEngineAdapter.h>
#include "Rule.h"


namespace adapter
{
    class Categorization : public IEngineAdapter
    {
    public:
        Categorization();

        ~Categorization() override;

        void run() override;

        int getEngineFunction() const override;

        std::string getName() const override;

        std::map<std::string, Rule> getRules() const
        {
            return (rules);
        }

    private:
        std::map<std::string, Rule> rules;

    };
}

#endif

/**
 * void StartRoutine::prepareRules()
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
 //This is TextSearch Adapter -> TODO move this shit
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

 //This is TextSearch Adapter -> TODO move this shit
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

 */
