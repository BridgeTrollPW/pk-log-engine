/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * OptimizeMe.h
 *
 *  Created on: 17.05.2019
 *      Author: bt
 */

#ifndef SRC_ENGINE_ADAPTER_OPTIMIZEME_OPTIMIZEME_H_
#define SRC_ENGINE_ADAPTER_OPTIMIZEME_OPTIMIZEME_H_

#include <iostream>
#include <string>

#include "../../Dispatcher.h"
#include "../../IEngineAdapter.h"


namespace adapter
{
    class OptimizeMe : public IEngineAdapter
    {
    public:
        OptimizeMe()
        {
        }

        void run()
        {

        }

        int getEngineFunction() const
        {
            return (Dispatcher::ENGINE_FUNCTION::INTERNAL_OPTIMIZE_ME);
        }

        std::string getName() const
        {
            return ("OptimizeMe");
        }
    };
}

#endif /* SRC_ENGINE_ADAPTER_OPTIMIZEME_OPTIMIZEME_H_ */
