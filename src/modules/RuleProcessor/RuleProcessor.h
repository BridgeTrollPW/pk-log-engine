/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RuleProcessor.h
 * Author: bt
 *
 * Created on 1. Mai 2019, 23:48
 */

#ifndef RULEPROCESSOR_H
#define RULEPROCESSOR_H

#include <list>
#include <regex>
#include <string>

#include "Rule.h"
#include "Result.h"
#include "Type.h"

class RuleProcessor
{
        private:
                std::list<Rule> rules;

        public:
                RuleProcessor()
                {
                }
                RuleProcessor(std::list<Rule> ruleList) :
                                rules(ruleList)
                {
                }
                void setRules(std::list<Rule> ruleList);

                Type getTypeByRule(Rule rule);
                Result processLine(std::string logLine);

};

#endif /* RULEPROCESSOR_H */
