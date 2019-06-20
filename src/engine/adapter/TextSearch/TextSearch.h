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
#include "TextSearchPayload.h"


namespace adapter
{
    class TextSearch : public IEngineAdapter
    {
    public:
        TextSearch(std::string filePath, const TextSearchPayload &payload);

        /**
         * get Engine name as string
         * immutable
         */
        std::string getName() const override
        {
            return ("TextSearch");
        }

        /**
         * get engine function as integer value
         * immutable
         */
        int getEngineFunction() const override
        {
            return (Dispatcher::ENGINE_FUNCTION::SEARCH);
        }

        void run() override;

    protected:
        ~TextSearch() override;

    private:
        util::Logger logger = util::Logger(this->getName());

        std::string filePath;
        std::vector<std::string> searchTerms;
    };
}

#endif
