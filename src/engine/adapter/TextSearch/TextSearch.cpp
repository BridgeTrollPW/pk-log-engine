#include "TextSearch.h"

#include <chrono>
#include <iostream>

#include "../../../lib/MBLib.h"
#include "../../../util/Exception.h"

namespace engine
{
        namespace adapter
        {
                TextSearch::TextSearch(std::string filePath, std::string searchTerms) :
                                filePath(filePath)
                {
                        logger.info("Starting TextSearch Adapter");
                        this->searchTerms = MBKingdoms::Lib::explode(searchTerms, ';');
                        if (this->searchTerms.empty())
                        {
                                throw Exception("No search terms were found", Exception::ExceptionCode::NO_SEARCHTERMS_PRESENT);
                        }
                        logger.debug("Got " + std::to_string(this->searchTerms.size()) + " search terms : " + searchTerms);
                }

                TextSearch::~TextSearch()
                {
                }

                void TextSearch::run()
                {
                        auto startTime = std::chrono::high_resolution_clock::now();
                        std::ifstream fileInputStream = getFileInputStream(filePath);
                        std::string line;
                        int lineCounter = 1;
                        int resultCounter = 0;

                        while (getline(fileInputStream, line))
                        {
                                auto it = std::find_if(begin(searchTerms), end(searchTerms), [&](const std::string& s)
                                {       return line.find(s) != std::string::npos;});

                                if (it != end(searchTerms))
                                {
                                        //logger.info("line found @ " + std::to_string(counter));
                                        std::cout << line << std::endl;
                                        resultCounter++;
                                }
                                lineCounter++;
                        }

                        auto endTime = std::chrono::high_resolution_clock::now();
                        logger.info("Search run finished with " + std::to_string(resultCounter) + " found results. Took " + std::to_string(std::chrono::duration_cast<
                                        std::chrono::milliseconds>(endTime - startTime).count()) + " ms");
                }

                std::ifstream TextSearch::getFileInputStream(std::string filePath)
                {
                        std::ifstream logs(filePath, std::ifstream::in);
                        if (!logs.is_open())
                        {
                                throw Exception("Log file cannot be opened", Exception::ExceptionCode::INVALID_LOG_FILE);
                        }
                        else
                        {
                                return (logs);
                        }

                }
        }
}
