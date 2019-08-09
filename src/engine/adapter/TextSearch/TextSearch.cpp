#include <utility>

#include "TextSearch.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <OutputWrapper.h>
#include <regex>

#include "../../../lib/json.hpp"
#include "../../../lib/MBLib.h"
#include "TextSearchPayload.h"


namespace adapter
{
    TextSearch::TextSearch(std::string filePath, const TextSearchPayload &payload) :
            filePath(std::move(filePath))
    {
        logger.info("Starting TextSearch Adapter");
        this->searchTerms = payload.searchTerms;
        this->caseSensitivity = payload.caseSensitivity;
        //this->searchTerms
        if (this->searchTerms.empty())
        {
            throw std::system_error(std::error_code(404, std::system_category()), "No search terms were found");
        }

        if (!payload.startTime.empty() && !payload.endTime.empty())
        {
            timedSearch = true;
            std::vector<std::string> startTimeParts = MBKingdoms::Lib::explode(payload.startTime, ':');
            std::vector<std::string> endTimeParts = MBKingdoms::Lib::explode(payload.endTime, ':');

            tm endTimeStruct{};
            endTimeStruct.tm_hour = std::stoi(endTimeParts.at(0));
            endTimeStruct.tm_min = std::stoi(endTimeParts.at(1));
            endTimeStruct.tm_sec = std::stoi(endTimeParts.at(2));
            this->endTime = mktime(&endTimeStruct);

            tm startTimeStruct{};
            startTimeStruct.tm_hour = std::stoi(startTimeParts.at(0));
            startTimeStruct.tm_min = std::stoi(startTimeParts.at(1));
            startTimeStruct.tm_sec = std::stoi(startTimeParts.at(2));
            this->startTime = mktime(&startTimeStruct);
        }


        std::string searchString;
        std::for_each(searchTerms.begin(), searchTerms.end(), [&searchString](std::string &st) -> void
        {
            searchString += (st + ";");
        });

        logger.debug("Got " + std::to_string(this->searchTerms.size()) + " search terms : " + searchString);
    }

    TextSearch::~TextSearch() = default;

    void TextSearch::run()
    {
        auto searchStartTime = getEngineTime();
        std::ifstream fileInputStream = getFileInputStream(filePath);
        std::string line;
        int lineCounter = 0;
        int resultCounter = 0;

        nlohmann::json o;
        std::list<nlohmann::json> j;

        OutputWrapper outputWrapper{};
        outputWrapper.open();
        while (getline(fileInputStream, line))
        {
            lineCounter++;
            if (timedSearch)
            {
                std::regex logTime("([0-9]{2}):([0-9]{2}):([0-9]{2}).*");
                std::smatch match;
                tm currentTimeStruct{};
                if (std::regex_search(line, match, logTime) && match.size() == 4)
                {
                    //first Regex Capture Group [index 0] is the complete string
                    currentTimeStruct.tm_hour = std::stoi(match.str(1));
                    currentTimeStruct.tm_min = std::stoi(match.str(2));
                    currentTimeStruct.tm_sec = std::stoi(match.str(3));
                }
                time_t current = mktime(&currentTimeStruct);


                //If before start time, continue the while loop
                if (std::difftime(current, this->startTime) < 0)
                {
                    continue;
                }
                //Anything between start time and end time will be searched
                //If after endTime, break the while loop
                if (std::difftime(current, this->endTime) > 0)
                {
                    break;
                }
            }
            auto it = std::find_if(begin(searchTerms), end(searchTerms), [&line, this](std::string &s)
            {
                if(!this->caseSensitivity)
                {
                    //need a local copy so we do not modify the actual logline reference
                    std::string tmpLine = line;
                    std::transform(tmpLine.begin(), tmpLine.end(), tmpLine.begin(), ::tolower);
                    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
                    return (tmpLine.find(s) != std::string::npos);
                }
                return (line.find(s) != std::string::npos);
            });


            if (it != end(searchTerms))
            {
                o["lineNumber"] = lineCounter;
                o["string"] = line;
                outputWrapper.push(o.dump());
                resultCounter++;
            }

        }
        outputWrapper.close();

        auto searchEndTime = getEngineTime();
        logger.info("Search run finished with " + std::to_string(resultCounter) + " found results. Took " +
                    getDurationMS(searchStartTime, searchEndTime) + " ms");
    }

    std::string TextSearch::getName() const
    {
        return "TextSearch";
    }

    int TextSearch::getEngineFunction() const
    {
        return Dispatcher::ENGINE_FUNCTION::SEARCH;
    }
}
