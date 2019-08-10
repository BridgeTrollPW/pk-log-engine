/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * IEngine.h
 * Interface for Engine Adapters. These can be executed by the Dispatcher
 *
 *  Created on: 13.05.2019
 *      Author: bt
 */
#ifndef IENGINE_H
#define IENGINE_H

#include <chrono>
#include <fstream>
#include <string>
#include <AsyncExecutionBuffer.h>


using engineTime = std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>;

class IEngineAdapter
{
public:
    virtual int getEngineFunction() const = 0;

    virtual void run(AsyncExecutionBuffer &asyncExecutionBuffer) = 0;

    virtual std::string getName() const = 0;

protected:
    virtual ~IEngineAdapter() = default;

    static std::ifstream getFileInputStream(std::string filePath)
    {
        std::ifstream filePtr(filePath, std::ifstream::in);
        if (!filePtr.is_open())
        {
            throw std::system_error(std::error_code(404, std::system_category()),
                                    "File " + filePath + " cannot be opened");
        }
        else
        {
            return (filePtr);
        }
    }

    static engineTime getEngineTime()
    {
        return (std::chrono::high_resolution_clock::now());
    }

    static std::string getDurationMS(engineTime start, engineTime end)
    {
        return (std::to_string(std::chrono::duration_cast<
                std::chrono::milliseconds>(end - start).count()));
    }
};


#endif
