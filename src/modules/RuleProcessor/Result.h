/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Result.h
 * Author: bt
 *
 * Created on 2. Mai 2019, 07:09
 */

#ifndef RESULT_H
#define RESULT_H

#include "Type.h"
#include "../../../lib/json.hpp"

using namespace nlohmann;

class Result
{
public:
    std::string type;
    std::string raw;
    std::map<std::string, std::string> mappings;

    void to_json(json& j)
    {
        j = json{
            {"type", type},
            {"raw", raw}
        };
        json j_map(mappings);
        j["mappings"] = j_map;
    }
};

#endif /* RESULT_H */

