
#ifndef RULEPROCESSOR_H
#define RULEPROCESSOR_H

#include <list>
#include <string>

#include "Rule.h"
#include "Type.h"
#include "Result.h"

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
