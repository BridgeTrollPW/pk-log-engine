/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * TextSearch.h
 *
 *  Created on: 13.05.2019
 *      Author: bt
 */
#ifndef TEXTSEARCH_H
#define TEXTSEARCH_H

#include <list>
#include <string>
#include <vector>

#include "../../../util/logger/Logger.h"
#include "../../Dispatcher.h"
#include "../../IEngineAdapter.h"

namespace engine
{
    namespace adapter
    {
        class TextSearch: public IEngineAdapter
        {
            public:
                TextSearch(std::string filePath, std::string searchTerms);
                TextSearch(std::string filePath, std::string searchTerms, std::list<
                        std::string> ouputBuffer);
                /**
                 * get Engine name as string
                 * immutable
                 */
                std::string getName() const
                {
                    return ("TextSearch");
                }
                /**
                 * get engine function as integer value
                 * immutable
                 */
                int getEngineFunction() const
                {
                    return (Dispatcher::ENGINE_FUNCTION::SEARCH);
                }
                void run();

            protected:
                ~TextSearch();
                private:
                util::Logger logger = util::Logger(this->getName());

                std::string filePath;
                std::vector<std::string> searchTerms;
        };
    }
}
#endif
