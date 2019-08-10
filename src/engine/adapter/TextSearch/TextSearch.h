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

#include <interface/IEngineAdapter.h>
#include <Dispatcher.h>
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
        std::string getName() const override;

        /**
         * get engine function as integer value
         * immutable
         */
        int getEngineFunction() const override;

        void run(AsyncExecutionBuffer &asyncExecutionBuffer) override;

        void terminate() override;

    protected:
        ~TextSearch() override;

    private:
        util::Logger logger = util::Logger(this->getName());

        std::string filePath;
        std::vector<std::string> searchTerms;
        std::time_t startTime;
        std::time_t endTime;
        bool timedSearch{false};
        bool caseSensitivity{false};
    };
}

#endif
