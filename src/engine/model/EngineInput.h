#ifndef ENGINEINPUT_H
#define ENGINEINPUT_H

#include <string>
#include "Payload.h"

namespace engine
{
    namespace model
    {

        struct EngineInput
        {
            public:
                int function = -1;
                std::string serverLogFile = "";
                std::string payload;
                bool prettyPrinting = false;
        };
    }
}
#endif /* ENGINEINPUT_H */

