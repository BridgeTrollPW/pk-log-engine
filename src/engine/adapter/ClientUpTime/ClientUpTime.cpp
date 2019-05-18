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
#include <iostream>
#include <iterator>

#include "../../../lib/MBLib.h"
#include "../../../util/Exception.h"
#include "../Categorization/Categorization.h"
#include "../Categorization/Rule.h"

using namespace engine::adapter;
/**
 * Use the searchstring cli param as string list of Player GUID's
 */
ClientUpTime::ClientUpTime(std::string filePath, std::string searchTerms) :
        filePath(filePath)
{
    playerGuids = MBKingdoms::Lib::explode(searchTerms, ';');
    if (playerGuids.empty())
    {
        throw Exception("No guids to search for were specified", Exception::ExceptionCode::NO_SEARCHTERMS_PRESENT);
    }
    regexString = "([0-9]{2}:[0-9]{2}:[0-9]{2}) - (.*) has GUID: (.*?) and IP: (.*)";
}

ClientUpTime::~ClientUpTime()
{
}

void ClientUpTime::run()
{
    auto startTime = getEngineTime();
    int resultCounter = 0;
    int lineCounter = 1;
    std::string line;
    std::ifstream fileInputStream = getFileInputStream(filePath);
    Categorization cat = Categorization();
    Rule ruleConnect(cat.getRules().at("player_connected_client"));
    Rule ruleDisconnect(cat.getRules().at("player_disconnect_message_guid"));

    while (getline(fileInputStream, line))
    {
        if (line.find("has GUID:") != std::string::npos)
        {
            auto it = std::find_if(begin(playerGuids), end(playerGuids), [&](const std::string& s)
            {
                return (line.find(s) != std::string::npos);
            });

            if (it != end(playerGuids))
            {

                Result connectedClient = ruleConnect.match(line);
                Connection c;
                c.connectTimeStr = connectedClient.mappings.at("time");
                c.guid = playerGuids.at(it - playerGuids.begin());

                if (connections.count(c.guid) < 1)
                {
                    std::list<Connection> ccl;
                    ccl.push_back(c);
                    connections[c.guid] = ccl;
                }
                else
                {
                    connections.at(c.guid).push_back(c);
                }
            }
        }
        else if (line.find("has left the game with") != std::string::npos)
        {
            auto it = std::find_if(begin(playerGuids), end(playerGuids), [&](const std::string& s)
            {
                return (line.find(s) != std::string::npos);
            });

            if (it != end(playerGuids))
            {
                Result disconnectedClient = ruleDisconnect.match(line);

                //connections.at(playerGuids.at(it - playerGuids.begin())).back().disconnectTimeStr = disconnectedClient.mappings.at("time");

                if (connections.count(disconnectedClient.mappings.at("guid")) == 0)
                {
                    Connection c;
                    c.guid = disconnectedClient.mappings.at("guid");
                    c.disconnectTimeStr = disconnectedClient.mappings.at("time");
                    std::list<Connection> ccl;
                    ccl.push_back(c);
                    connections[c.guid] = ccl;
                }
                else
                {
                    connections.at(disconnectedClient.mappings.at("guid")).back().disconnectTimeStr = disconnectedClient.mappings.at("time");
                }
            }
        }

        resultCounter++;
        lineCounter++;
    }

    for (auto entry : connections)
    {
        std::cout << "GUID:" << entry.first << "\n";
        for (auto entryj : entry.second)
        {
            std::cout << "Connected at: " << entryj.connectTimeStr << " || Disconnected at:" << entryj.disconnectTimeStr << "\n";
        }
    }
    auto endTime = getEngineTime();

    logger.info("ClientUpTime run finished with " + std::to_string(resultCounter) + " found results. Took " + getDurationMS(startTime, endTime) + " ms");
}

