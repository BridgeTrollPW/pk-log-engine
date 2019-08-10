//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#ifndef LOG_ENGINE_ASYNCEXECUTIONBUFFER_H
#define LOG_ENGINE_ASYNCEXECUTIONBUFFER_H


#include <interface/IEngineOutputElement.h>
#include <list>
#include <logger/Logger.h>
#include <mutex>
#include <condition_variable>

class AsyncExecutionBuffer {
private:
    std::list<IEngineOutputElement *> buffer;
    util::Logger logger = util::Logger("AsyncExecutionBuffer");
    std::mutex mtx;
    std::condition_variable conditionVariable;
public:
    explicit AsyncExecutionBuffer(std::condition_variable &conditionVariable);

    void push(IEngineOutputElement *bufferInput);

    IEngineOutputElement *pop();

    bool isEmpty();
};


#endif //LOG_ENGINE_ASYNCEXECUTIONBUFFER_H
