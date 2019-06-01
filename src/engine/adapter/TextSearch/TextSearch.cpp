#include "TextSearch.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>

#include "../../../lib/json.hpp"
#include "../../../lib/MBLib.h"
#include "../../../util/Exception.h"
#include "TextSearchPayload.h"


namespace engine {
    namespace adapter {
        TextSearch::TextSearch(std::string filePath, const TextSearchPayload payload) :
                filePath(filePath) {
            logger.info("Starting TextSearch Adapter");
            this->searchTerms = payload.searchTerms;
            //this->searchTerms
            if (this->searchTerms.empty()) {
                throw Exception("No search terms were found", Exception::ExceptionCode::NO_SEARCHTERMS_PRESENT);
            }
            logger.debug("Got " + std::to_string(this->searchTerms.size()) + " search terms : " + searchTerms);
        }

        TextSearch::~TextSearch() {
        }

        void TextSearch::run() {
            auto startTime = getEngineTime();
            std::ifstream fileInputStream = getFileInputStream(filePath);
            std::string line;
            int lineCounter = 1;
            int resultCounter = 0;

            nlohmann::json o;
            std::list<nlohmann::json> j;

            while (getline(fileInputStream, line)) {
                auto it = std::find_if(begin(searchTerms), end(searchTerms), [&](const std::string &s) {
                    return (line.find(s) != std::string::npos);
                });

                if (it != end(searchTerms)) {
                    o["lineNumber"] = lineCounter;
                    o["string"] = line;
                    //j.push_back(o);
                    std::cout << o << "\n";
                    resultCounter++;
                }
                lineCounter++;
            }

            auto endTime = getEngineTime();
            logger.info("Search run finished with " + std::to_string(resultCounter) + " found results. Took " +
                        getDurationMS(startTime, endTime) + " ms");
        }
    }
}
