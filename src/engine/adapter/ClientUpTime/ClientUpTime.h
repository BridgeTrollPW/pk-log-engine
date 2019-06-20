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


#include <interface/IEngineAdapter.h>
#include <Dispatcher.h>
#include "Connection.h"

namespace adapter
{

    class ClientUpTime : public IEngineAdapter
    {
    public:
        ClientUpTime(std::string filePath, std::string searchTerms);

        ~ClientUpTime() override;

        void run() override;

        int getEngineFunction() const override
        {
            return Dispatcher::ENGINE_FUNCTION::CLIENT_UPTIME;
        }

        std::string getName() const override
        {
            return ("ClientUpTime");
        }

    private:
        std::vector<std::string> playerGuids;
        std::string filePath;
        std::string regexString;
        util::Logger logger = util::Logger(this->getName());
        std::map<std::string, std::list<Connection>> connections;

    };
}

#endif /* SRC_ENGINE_ADAPTER_CLIENTUPTIME_CLIENTUPTIME_H_ */
