//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#ifndef LOG_ENGINE_TASKSCHEDULER_H
#define LOG_ENGINE_TASKSCHEDULER_H


#include <model/IExecutionTask.h>
#include <list>
#include <thread>
#include "AsyncExecutionBuffer.h"

class TaskScheduler {
private:
    AsyncExecutionBuffer *asyncExecutionBuffer = nullptr;

    std::condition_variable conditionVariable;
    std::mutex mutex;

    std::list<IExecutionTask *> executionList;
    std::list<std::thread> threadList;

    util::Logger logger = util::Logger("TaskScheduler");

public:
    explicit TaskScheduler();

    void registerTask(IExecutionTask *const &executionTask);

    void start();
};


#endif //LOG_ENGINE_TASKSCHEDULER_H
