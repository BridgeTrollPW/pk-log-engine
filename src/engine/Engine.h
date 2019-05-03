#ifndef ENGINE_H
#define ENGINE_H
#include "model/EngineInput.h"
#include "../util/Exception.h"
#include "../util/logger/Logger.h"

namespace engine
{

    class Engine
    {
    private:
        model::EngineInput engineInput;
        util::Logger logger;
        
        bool validate();

    public:
        Engine(model::EngineInput eIN);

        enum ENGINE_FUNCTION
        {
            SEARCH = 0,
            SEARCH_AND_CATEGORIZE = 1,
            RETURN_RAW = 2
        };
    };
}
#endif /* ENGINE_H */
