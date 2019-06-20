//
// Created by bt on 20.06.19.
//

#ifndef LOG_ENGINE_IJSONSERIALIZABLE_H
#define LOG_ENGINE_IJSONSERIALIZABLE_H

#include <json.hpp>

class IJsonSerializable
{
public:
    virtual void fromJson(const nlohmann::json &json) = 0;
};

#endif //LOG_ENGINE_IJSONSERIALIZABLE_H
