/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * ClientUpTime.h
 *
 *  Created on: 16.05.2019
 *      Author: bt
 */

#ifndef SRC_ENGINE_ADAPTER_CLIENTUPTIME_CLIENTUPTIME_H_
#define SRC_ENGINE_ADAPTER_CLIENTUPTIME_CLIENTUPTIME_H_

#include <string>
#include <vector>

#include "../../../util/logger/Logger.h"
#include "../../Dispatcher.h"
#include "../../IEngineAdapter.h"

namespace engine
{
    namespace adapter
    {

        class ClientUpTime: public IEngineAdapter
        {
            public:
                ClientUpTime(std::string filePath, std::string searchTerms);
                ~ClientUpTime();
                void run();

                int getEngineFunction() const
                {
                    return (Dispatcher::ENGINE_FUNCTION::CLIENT_UPTIME);
                }

                std::string getName() const
                {
                    return ("ClientUpTime");
                }

            private:
                std::vector<std::string> playerGuids;
                std::string filePath;
                util::Logger logger = util::Logger(this->getName());

        };
    }
}
#endif /* SRC_ENGINE_ADAPTER_CLIENTUPTIME_CLIENTUPTIME_H_ */
