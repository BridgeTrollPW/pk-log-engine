/*
 * File:   Result.h
 * Author: bt
 *
 * Created on 2. Mai 2019, 07:09
 */

#ifndef RESULT_H
#define RESULT_H

#include <map>
#include <string>

#include "../../lib/json.hpp"

class Result
{
    public:
        std::string type;
        std::string raw;
        std::map<std::string, std::string> mappings;

        void to_json(nlohmann::json& j)
        {
            j = nlohmann::json { { "type", type }, { "raw", raw } };
            nlohmann::json j_map(mappings);
            j["mappings"] = j_map;
        }
};

#endif /* RESULT_H */

