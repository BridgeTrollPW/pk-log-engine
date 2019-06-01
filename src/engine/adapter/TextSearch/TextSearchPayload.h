//
// Created by bt on 30.05.19.
//

#ifndef LOG_ENGINE_TEXTSEARCHPAYLOAD_H
#define LOG_ENGINE_TEXTSEARCHPAYLOAD_H

#include <vector>
#include "Payload.h"

class TextSearchPayload : public Payload {
public:
    std::string startTime, endTime;
    int lineStart = 0, lineEnd = 0;
    std::vector<std::string> searchTerms;

    void to_json(nlohmann::json &j, Payload *&t) override {

    }

    void from_json(nlohmann::json &j, Payload *&t) override {

    }
};

#endif //LOG_ENGINE_TEXTSEARCHPAYLOAD_H
