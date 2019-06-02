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
#include "../Categorization/Categorization.h"
#include "../Categorization/Rule.h"

using namespace engine::adapter;

ClientUpTime::ClientUpTime(std::string filePath, std::string searchTerms) :
        filePath(filePath) {
    playerGuids = MBKingdoms::Lib::explode(searchTerms, ';');
    if (playerGuids.empty()) {
        throw std::system_error(std::error_code(404, std::system_category()), "No guids to search for were specified");
    }

    Categorization categorisation = Categorization();
    Rule ruleConnect(categorisation.getRules().at("player_connected_client"));
    Rule ruleDisconnect(categorisation.getRules().at("player_disconnect_message_guid"));

}

ClientUpTime::~ClientUpTime() {
}

void ClientUpTime::run() {
    auto startTime = getEngineTime();
    int resultCounter = 0;
    int lineCounter = 1;
    std::string line;
    std::ifstream fileInputStream = getFileInputStream(filePath);

    while (getline(fileInputStream, line)) {
        if (line.find("has GUID:") != std::string::npos) {

            auto it = std::find_if(begin(playerGuids), end(playerGuids), [&](const std::string &s) -> bool {
                return (line.find(s) != std::string::npos);
            });

            if (it != end(playerGuids)) {
                std::cout << "Connected:: " << line << "\n";

            }

            resultCounter++;
            lineCounter++;
        }

    }
    auto endTime = getEngineTime();
    logger.info("ClientUpTime run finished with " + std::to_string(resultCounter) + " found results. Took " +
                getDurationMS(startTime, endTime) + " ms");

}

