/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * Connection.h
 *
 *  Created on: 18.05.2019
 *      Author: bt
 */

#ifndef SRC_ENGINE_ADAPTER_CLIENTUPTIME_CONNECTION_H_
#define SRC_ENGINE_ADAPTER_CLIENTUPTIME_CONNECTION_H_

#include <string>

struct Connection
{
        std::string guid;
        std::string connectTimeStr;
        std::string disconnectTimeStr = "";
        std::string total;
};

#endif /* SRC_ENGINE_ADAPTER_CLIENTUPTIME_CONNECTION_H_ */
