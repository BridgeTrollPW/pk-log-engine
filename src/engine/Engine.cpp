#include "Engine.h"

namespace engine
{

    Engine::Engine(model::EngineInput eIN): engineInput(eIN)
    {
        validate();
    }
    
    bool Engine::validate()
    {
        if(engineInput.configFile == "" || engineInput.serverLogFile == "")
            {
                throw Exception("Missing required cli params", 0); 
            }
                
    }
}
