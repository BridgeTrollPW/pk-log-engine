//
// Created by bt on 30.05.19.
//

#ifndef LOG_ENGINE_TEXTSEARCHPAYLOADSERIALIZER_H
#define LOG_ENGINE_TEXTSEARCHPAYLOADSERIALIZER_H

#include <json.hpp>
#include "TextSearchPayload.h"

void to_json(nlohmann::json &j, const TextSearchPayload &t) {

}

void from_json(const nlohmann::json &j, TextSearchPayload &t) {
    if (j.contains("startTime") && j.contains("endTime")) {
        j.at("startTime").get_to(t.startTime);
        j.at("endTime").get_to(t.endTime);
    } else if (j.contains("lineStart") && j.contains("lineEnd")) {
        j.at("lineStart").get_to(t.startTime);
        j.at("lineEnd").get_to(t.endTime);
    }
    if(j.contains("searchTerms"))
    {
        j.at("searchTerms").get_to(t.searchTerms);
    }
}

#endif //LOG_ENGINE_TEXTSEARCHPAYLOADSERIALIZER_H
