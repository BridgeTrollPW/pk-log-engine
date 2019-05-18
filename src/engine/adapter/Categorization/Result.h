/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * Result.h
 *
 *  Created on: 18.05.2019
 *      Author: bt
 */

#ifndef RESULT_H
#define RESULT_H

#include <map>
#include <string>

#include "../../../lib/json.hpp"

class Result
{
    public:
        std::string type;
        std::string raw;
        std::map<std::string, std::string> mappings;

        void to_json(nlohmann::json& j, const Result& r)
        {
            j = nlohmann::json { { "type", r.type }, { "raw", r.raw } };
            nlohmann::json j_map(r.mappings);
            j["mappings"] = j_map;
        }
};

#endif /* RESULT_H */

