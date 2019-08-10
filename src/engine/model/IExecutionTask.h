//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#ifndef LOG_ENGINE_IEXECUTIONTASK_H
#define LOG_ENGINE_IEXECUTIONTASK_H


#include <task/AsyncExecutionBuffer.h>

class IExecutionTask {
public:
    virtual void run(AsyncExecutionBuffer& asyncExecutionBuffer) = 0;
    virtual void terminate() = 0;
};


#endif //LOG_ENGINE_IEXECUTIONTASK_H
