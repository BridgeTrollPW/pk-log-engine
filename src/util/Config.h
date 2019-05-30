//
// Created by bt on 25.05.19.
//

#ifndef LOG_ENGINE_CONFIG_H
#define LOG_ENGINE_CONFIG_H

#include <string>
#include <json.hpp>
#include <fstream>
#include "Exception.h"

class Config {
private:
    static nlohmann::json json;
public:
    Config(std::string filePath) {
        std::ifstream cfgFile(filePath, std::ifstream::in);
        if (!cfgFile.is_open()) {
            throw Exception("Config cannot be loaded", Exception::ExceptionCode::INVALID_LOG_FILE);
        }
        cfgFile >> json;
    }

    static nlohmann::json getConfig()
    {
        return json;
    }
};

#endif //LOG_ENGINE_CONFIG_H
