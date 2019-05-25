/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * Categorization.cpp
 *
 *  Created on: 18.05.2019
 *      Author: bt
 */

#include "Categorization.h"

#include <iostream>
#include <map>

#include "../../../lib/json.hpp"

using namespace engine::adapter;

Categorization::Categorization()
{
    //load rules from fileStream into JSON object
    nlohmann::json tempRules;
    getFileInputStream("resources/rules.json") >> tempRules;

    for (auto el : tempRules.items())
    {
        //Rule r = Rule();
        std::string n = el.key();
        std::string r = el.value().at("regex").get<std::string>();
        std::map<int, std::string> groups;
        for (auto g : el.value().at("groups").items())
        {
            groups[g.value()[0]] = g.value()[1];
        };
        rules[n] = Rule(n, r, groups);
    }

}

Categorization::~Categorization()
{
}

void Categorization::run()
{
}
