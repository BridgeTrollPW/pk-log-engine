//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#ifndef LOG_ENGINE_TEXTSEARCHBUFFERELEMENT_H
#define LOG_ENGINE_TEXTSEARCHBUFFERELEMENT_H

#include <interface/IEngineOutputElement.h>
#include <json.hpp>

class TextSearchBufferElement : public IEngineOutputElement {
private:
    int lineNumber;
    std::string lineContent;
    bool stale;
public:

    TextSearchBufferElement(const int lineNumber, const std::string &lineContent) {
        TextSearchBufferElement::lineNumber = lineNumber;
        TextSearchBufferElement::lineContent = lineContent;
        TextSearchBufferElement::stale = false;
    }

    std::string toJson() override {
        nlohmann::json o;
        o["lineNumber"] = lineNumber;
        o["string"] = lineContent;
        return o.dump();
    }

    std::string getLineContent() override {
        return lineContent;
    }

    int getLineNumber() override {
        return lineNumber;
    }

    void setStaleness(const bool &staleness) override {
        TextSearchBufferElement::stale = staleness;
    }

    bool isElementStale() override {
        return stale;
    }
};

#endif //LOG_ENGINE_TEXTSEARCHBUFFERELEMENT_H
