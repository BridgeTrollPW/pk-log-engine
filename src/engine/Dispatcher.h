#ifndef ENGINE_H
#define ENGINE_H
#include <list>

#include "model/EngineInput.h"
#include "../util/Exception.h"
#include "../util/exceptions/InvalidConfigException.h"
#include "../util/exceptions/InvalidArgumentException.h"
#include "../util/logger/Logger.h"
#include "../lib/json.hpp"
#include "IEngine.h"

namespace engine
{

    class Dispatcher
    {
    private:
        model::EngineInput engineInput;
        util::Logger logger;
        nlohmann::json configuration;
        
        std::list<IEngine*> executionList;
        
        void validate();
        void execAdapter();

    public:
        Dispatcher(model::EngineInput eIN);

        enum ENGINE_FUNCTION
        {
            SEARCH = 0,
            SEARCH_AND_CATEGORIZE = 1,
            RETURN_RAW = 2
        };
    };
}
#endif /* ENGINE_H */
