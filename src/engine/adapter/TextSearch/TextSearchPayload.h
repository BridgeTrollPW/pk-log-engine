//
// Created by bt on 30.05.19.
//

#ifndef LOG_ENGINE_TEXTSEARCHPAYLOAD_H
#define LOG_ENGINE_TEXTSEARCHPAYLOAD_H

#include <vector>
#include <interface/IJsonSerializable.h>
#include "Payload.h"

class TextSearchPayload : public IJsonSerializable
{
public:
    std::string startTime, endTime;
    int lineStart = 0, lineEnd = 0;
    std::vector<std::string> searchTerms;

    void fromJson(const nlohmann::json &json) override
    {
        if (json.contains("startTime") && json.contains("endTime"))
        {
            json.at("startTime").get_to(startTime);
            json.at("endTime").get_to(endTime);
        }
        else if (json.contains("lineStart") && json.contains("lineEnd"))
        {
            json.at("lineStart").get_to(startTime);
            json.at("lineEnd").get_to(endTime);
        }
        if (json.contains("searchTerms"))
        {
            json.at("searchTerms").get_to(searchTerms);
        }

    }
};

#endif //LOG_ENGINE_TEXTSEARCHPAYLOAD_H
