//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#include <adapter/STDOutput.h>
#include "TaskScheduler.h"

TaskScheduler::TaskScheduler() {
    asyncExecutionBuffer = new AsyncExecutionBuffer(conditionVariable);
}

void TaskScheduler::registerTask(IExecutionTask *const &executionTask) {
    executionList.push_back(executionTask);
}

void TaskScheduler::start() {
    adapter::STDOutput stdOutput(conditionVariable);
    std::thread outputThread([&stdOutput, this]() -> void {
        stdOutput.run(*asyncExecutionBuffer);
    });

    for (auto &execution : executionList) {
        threadList.emplace_back(std::thread([execution, this]() -> void {
            execution->run(*this->asyncExecutionBuffer);
        }));
    }

    for (auto &thread: threadList) {
        thread.join();
    }
    stdOutput.terminate();
    outputThread.join();
}


