/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * ClientUpTime.cpp
 *
 *  Created on: 17.05.2019
 *      Author: bt
 */

#include "ClientUpTime.h"

#include <algorithm>
#include <cstdio>
#include <iostream>

#include "../../../lib/MBLib.h"
#include "../../../util/Exception.h"

namespace engine
{
    namespace adapter
    {
        /**
         * Use the serachstring cli param as string list of Player GUID's
         */
        ClientUpTime::ClientUpTime(std::string filePath, std::string searchTerms) :
                filePath(filePath)
        {
            playerGuids = MBKingdoms::Lib::explode(searchTerms, ';');
            if (playerGuids.empty())
            {
                throw Exception("No guids to search for were specified", Exception::ExceptionCode::NO_SEARCHTERMS_PRESENT);
            }
        }

        ClientUpTime::~ClientUpTime()
        {
        }

        void ClientUpTime::run()
        {
            auto startTime = getEngineTime();
            int resultCounter = 0;
            std::string line;
            std::ifstream fileInputStream = getFileInputStream(filePath);

            while (getline(fileInputStream, line))
            {
                auto it = std::find_if(begin(playerGuids), end(playerGuids), [&](const std::string& s)
                {
                    return (line.find(s) != std::string::npos);
                });

                if (it != end(playerGuids))
                {

                }
            }
            auto endTime = getEngineTime();

            logger.info("ClientUpTime run finished with " + std::to_string(resultCounter) + " found results. Took " + getDurationMS(startTime, endTime) + " ms");
        }
    }
}
