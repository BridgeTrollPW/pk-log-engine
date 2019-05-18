/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * Rule.h
 *
 *  Created on: 18.05.2019
 *      Author: bt
 */

#ifndef RULE_H
#define RULE_H

#include <map>
#include <regex>
#include <string>

#include "Result.h"

class Rule
{
    private:
        std::string name;
        std::string regex;
        std::map<int, std::string> groups;

    public:

        Rule(std::string name, std::string regex, std::map<int,
                std::string> matchingGroups) :
                name(name), regex(regex), groups(matchingGroups)
        {
        }

        Rule(const Rule& rule) :
                name(rule.name), regex(rule.regex), groups(rule.groups)
        {
        }

        Rule()
        {
        }

        std::string getRegex()
        {
            return (regex);
        }

        std::string getName()
        {
            return (name);
        }

        std::map<int, std::string> getGroups()
        {
            return (groups);
        }

        Result match(std::string str)
        {
            Result result = Result();
            try
            {
                std::regex regEx(getRegex());
                std::smatch match;

                if (std::regex_search(str, match, regEx) && match.size() > 1)
                {
                    for (auto& keyValue : getGroups())
                    {
                        result.mappings[keyValue.second] = match.str(keyValue.first);
                    }
                    result.type = getName();
                }
            }
            catch (std::regex_error& e)
            {
                // Syntax error in the regular expression
            }
            return (result);
        }
};

#endif /* RULE_H */

