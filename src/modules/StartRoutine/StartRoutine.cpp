#include "StartRoutine.h"

#include <iostream>
#include <string>
#include <Config.h>

#include "../../engine/Dispatcher.h"
#include "../../engine/model/EngineInput.h"
#include "../../lib/json.hpp"
#include "../../util/exceptions/InvalidArgumentException.h"

using json = nlohmann::json;

StartRoutine::StartRoutine(int argc, char **argv)
{
    engine::model::EngineInput eIN;
    std::string payload;
    Config* c;
    for (int i = 1; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-help" || std::string(argv[i]) == "-h" || std::string(argv[i]) == "-?")
        {
            std::cout << "" << std::endl;
        }
        else if (std::string(argv[i]) == "-function" || std::string(argv[i]) == "-f")
        {
            if (i + 1 < argc)
            {
                eIN.function = std::stoi(argv[++i]);
            }
            else
            {
                throw InvalidArgumentException("-function/-f option requires one argument.", 1);
            }
        }
        else if (std::string(argv[i]) == "-config" || std::string(argv[i]) == "-c")
        {
            if (i + 1 < argc)
            {
                //TODO remove any logs before this point
                //TODO the logger reads from the Config Class with has a static path variable shared between instances
                 c = new Config(argv[++i]);
            }
            else
            {
                throw InvalidArgumentException("-config/-c option requires one argument.", 1);
            }
        }
        else if (std::string(argv[i]) == "-log" || std::string(argv[i]) == "-l")
        {
            if (i + 1 < argc)
            {
                eIN.serverLogFile = argv[++i];
            }
            else
            {
                throw InvalidArgumentException("-log/-l option requires one argument.", 1);
            }
        }
        else if (std::string(argv[i]) == "-pretty-printing" || std::string(argv[i]) == "-pp")
        {
            eIN.prettyPrinting = true;
        }
        else if (std::string(argv[i]) == "-payload" || std::string(argv[i]) == "-p")
        {
            if (i + 1 < argc)
            {
                payload =argv[++i];
            }
            else
            {
                throw InvalidArgumentException("-payload/-p option requires one argument.", 1);
            }
        }
    }
    std::string a = Config::getConfig().at("core")["logPath"];

    engine::Dispatcher d = engine::Dispatcher(eIN, payload);
}
