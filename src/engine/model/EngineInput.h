#ifndef ENGINEINPUT_H
#define ENGINEINPUT_H

#include <string>

namespace engine
{
    namespace model
    {

        struct EngineInput
        {
            public:
                int function = -1;
                Config* config;
                std::string serverLogFile = "";
                std::string searchStrings = "";
                std::string linePairs = "";
                bool prettyPrinting = false;
        };
    }
}
#endif /* ENGINEINPUT_H */

