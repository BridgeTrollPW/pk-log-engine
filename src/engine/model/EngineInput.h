/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EngineInput.h
 * Author: bt
 *
 * Created on 3. Mai 2019, 17:34
 */

#ifndef ENGINEINPUT_H
#define ENGINEINPUT_H

#include <string>
namespace core
{
    namespace model
    {

        struct EngineInput
        {
        public:
            int function = 0;
            std::string configFile = "";
            std::string serverLogFile = "";
            std::string searchStrings = "";
            std::string linePairs = "";
            bool prettyPrinting = false;
        };
    }
}
#endif /* ENGINEINPUT_H */

