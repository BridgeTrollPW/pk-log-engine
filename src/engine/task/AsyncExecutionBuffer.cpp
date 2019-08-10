//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#include "AsyncExecutionBuffer.h"

AsyncExecutionBuffer::AsyncExecutionBuffer(std::condition_variable &conditionVariable) {
    logger.info("AsyncExecutionBuffer is initialized");
}

void AsyncExecutionBuffer::push(IEngineOutputElement *bufferInput) {
    {
        std::lock_guard<std::mutex> guard(mtx); //RAII
        buffer.emplace_back(bufferInput);
        logger.debug("perform write to execution buffer. new size " + std::to_string(buffer.size()));
    }

}

bool AsyncExecutionBuffer::isEmpty() {
    return buffer.empty();
}

IEngineOutputElement *AsyncExecutionBuffer::pop() {
    std::lock_guard<std::mutex> guard(mtx);
    IEngineOutputElement *firstElement = buffer.front();
    buffer.pop_front();
    logger.debug("perform pop to execution buffer. new size " + std::to_string(buffer.size()));
    return firstElement;
}
