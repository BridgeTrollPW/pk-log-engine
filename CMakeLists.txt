cmake_minimum_required(VERSION 3.10)
project(log_engine)

set(CMAKE_CXX_STANDARD 14)
add_compile_options("-fno-omit-frame-pointer")
add_compile_options("-Wall")
add_compile_options("-fsanitize=address")
add_compile_options("-O1")
add_compile_options("-pthread")
#No, don't do it, don't do it!
#add_compile_options("-v")

include_directories(src/engine)
include_directories(src/engine/adapter/Categorization)
include_directories(src/engine/adapter/ClientUpTime)
include_directories(src/engine/adapter/MultiIPChecker)
include_directories(src/engine/adapter/OptimizeMe)
include_directories(src/engine/adapter/TextSearch)
include_directories(src/engine/model)
include_directories(src/lib)
include_directories(src/modules/StartRoutine)
include_directories(src/util)
include_directories(src/util/exceptions)
include_directories(src/util/logger)

add_executable(log_engine
        src/engine/adapter/Categorization/Categorization.cpp
        src/engine/adapter/Categorization/Categorization.h
        src/engine/adapter/Categorization/Result.h
        src/engine/adapter/Categorization/Rule.h
        src/engine/adapter/TextSearch/TextSearch.cpp
        src/engine/adapter/TextSearch/TextSearch.h
        src/engine/model/EngineInput.h
        src/engine/Dispatcher.cpp
        src/engine/Dispatcher.h
        src/engine/interface/IEngineAdapter.h
        src/lib/json.hpp
        src/lib/MBLib.h
        src/modules/StartRoutine/StartRoutine.cpp
        src/modules/StartRoutine/StartRoutine.h
        src/util/logger/Logger.cpp
        src/util/logger/Logger.h
        src/util/ErrorHandler.cpp
        src/util/ErrorHandler.h
        src/main.cpp
        src/util/Config.h
        src/util/Config.cpp
        src/engine/model/Payload.h
        src/engine/adapter/TextSearch/TextSearchPayload.h
        src/engine/OutputWrapper.cpp
        src/engine/OutputWrapper.h
        src/engine/interface/IJsonSerializable.h
        src/engine/task/AsyncExecutionBuffer.cpp
        src/engine/task/AsyncExecutionBuffer.h
        src/engine/interface/IEngineOutputElement.h
        src/engine/adapter/TextSearch/TextSearchBufferElement.h
        src/engine/adapter/STDOutput.cpp
        src/engine/adapter/STDOutput.h
        src/engine/task/TaskScheduler.cpp
        src/engine/task/TaskScheduler.h
        src/engine/model/IExecutionTask.h)

target_link_libraries(log_engine
        -fsanitize=address
        )