//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#ifndef LOG_ENGINE_IENGINEOUTPUTELEMENT_H
#define LOG_ENGINE_IENGINEOUTPUTELEMENT_H

#include <string>

class IEngineOutputElement {
public:
    virtual std::string toJson() = 0;
    virtual std::string getLineContent() = 0;
    virtual int getLineNumber() = 0;

    //Ready for output?
    virtual void setStaleness(const bool &staleness) = 0;
    virtual bool isElementStale() = 0;
};

#endif //LOG_ENGINE_IENGINEOUTPUTELEMENT_H
