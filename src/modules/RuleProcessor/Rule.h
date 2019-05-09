/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rule.h
 * Author: bt
 *
 * Created on 1. Mai 2019, 23:47
 */

#ifndef RULE_H
#define RULE_H

#include <string>
#include <map>

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

                std::string getRegex()
                {
                        return regex;
                }

                std::string getName()
                {
                        return name;
                }

                std::map<int, std::string> getGroups()
                {
                        return groups;
                }
};

#endif /* RULE_H */

