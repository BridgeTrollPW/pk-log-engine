//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#include "STDOutput.h"
#include <thread>
#include <iostream>

using namespace adapter;

STDOutput::STDOutput(std::condition_variable &conditionVariable) {
    running = true;
}

int STDOutput::getEngineFunction() const {
    return 0;
}

void STDOutput::run(AsyncExecutionBuffer &asyncExecutionBuffer) {
    while (shouldRun(asyncExecutionBuffer)) {
        if (!asyncExecutionBuffer.isEmpty()) {
            logger.debug("doing output");
            IEngineOutputElement *output = asyncExecutionBuffer.pop();
            std::cout << output->getLineContent() << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    logger.debug("STDOutput killed");
}

void STDOutput::terminate() {
    logger.debug("send shutdown to STDOutput Thread");
    running = false;
}

bool STDOutput::shouldRun(AsyncExecutionBuffer &asyncExecutionBuffer) {
    if (running && !asyncExecutionBuffer.isEmpty()) { return true; }
    else if (!running && !asyncExecutionBuffer.isEmpty()) { return true; }
    else if (running && asyncExecutionBuffer.isEmpty()) { return true; }
    else if (!running && asyncExecutionBuffer.isEmpty()) { return false; }
    return false;
}
