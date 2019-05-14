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

#include <string>

namespace engine
{

    class IEngineAdapter
    {
        public:
            virtual int getEngineFunction() const = 0;
            virtual void run() = 0;
            virtual std::string getName() const = 0;
        protected:
            virtual ~IEngineAdapter()
            {
                //Todo cleanup lololololol just joking,
                //this would trash the memory at some point if the interface is used wrongly, so JUST DO IT
            }
    };

}
#endif
