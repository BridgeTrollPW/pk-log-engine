//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#include "STDOutput.h"
#include <thread>
#include <iostream>

using namespace adapter;

STDOutput::STDOutput() {
    running = true;
}

int STDOutput::getEngineFunction() const {
    return 0;
}

void STDOutput::run(AsyncExecutionBuffer &asyncExecutionBuffer) {
    while(!asyncExecutionBuffer.isEmpty() || running)
    {
        logger.debug("doing output");
        IEngineOutputElement* output = asyncExecutionBuffer.pop();
        std::cout << output->getLineContent() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    logger.debug("STDOutput killed");
}

void STDOutput::shutdown() {
    logger.debug("send shutdown to STDOutput Thread");
    running = false;
}
