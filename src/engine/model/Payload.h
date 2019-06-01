//
// Created by bt on 30.05.19.
//

#ifndef LOG_ENGINE_PAYLOAD_H
#define LOG_ENGINE_PAYLOAD_H


#include <string>
#include <json.hpp>

//template<typename T>
class Payload {
private:
    nlohmann::json payload;
public:
    Payload(std::string jsonString) {
        payload = nlohmann::json::parse(jsonString);
    }

    Payload(){}

    nlohmann::json getPayloadJSON()
    {
        return payload;
    }



    virtual void to_json(nlohmann::json& j, Payload*& t) = 0;
    virtual void from_json(nlohmann::json& j, Payload*& t) = 0;
};


#endif //LOG_ENGINE_PAYLOAD_H
