//
// Created by bt on 25.05.19.
//

#ifndef LOG_ENGINE_CONFIG_H
#define LOG_ENGINE_CONFIG_H

#include <string>
#include <json.hpp>
#include <fstream>

class Config {
private:
    static nlohmann::json json;
public:
    explicit Config(const std::string &filePath) {
        std::ifstream cfgFile(filePath, std::ifstream::in);
        if (!cfgFile.is_open()) {
            throw std::system_error(std::error_code(404, std::system_category()), "Config cannot be loaded");
        }
        cfgFile >> json;
    }

    static nlohmann::json getConfig() {
        return json;
    }
};

#endif //LOG_ENGINE_CONFIG_H
