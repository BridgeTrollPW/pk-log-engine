/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RuleProcessor.cpp
 * Author: bt
 * 
 * Created on 1. Mai 2019, 23:48
 */

#include "../header/RuleProcessor.h"

void RuleProcessor::setRules(std::list<Rule> ruleList)
{
    rules = ruleList;
}

Result RuleProcessor::processLine(std::string logLine)
{
    Result result;
    for (Rule r : rules) {
        
        try {
            std::regex regEx(r.getRegex());
            std::smatch match;
            
            if (std::regex_search(logLine, match, regEx) && match.size() > 1) {
                for(auto& keyValue : r.getGroups())
                {
                    result.mappings[keyValue.second] = match.str(keyValue.first);
                }
                result.type = r.getName();
                break;
            }
        }
        catch (std::regex_error& e) {
            // Syntax error in the regular expression
        }
    }
    
    return result;
}