/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * MultiIPChecker.h
 *
 *  Created on: 17.05.2019
 *      Author: bt
 */

#ifndef SRC_ENGINE_ADAPTER_MULTIIPCHECKER_MULTIIPCHECKER_H_
#define SRC_ENGINE_ADAPTER_MULTIIPCHECKER_MULTIIPCHECKER_H_

#include "../../IEngineAdapter.h"

namespace engine
{
    namespace adapter
    {
        class MultiIPChecker: public IEngineAdapter
        {
                //TODO: Check for multiple IPs that use the same GUID and vice versa
                //TODO: Detect multiple GUIDs for one single IP
                //TODO: GeoLocation checking via open web api in parallel(non-blocking) thread ???
        };
    }
}

#endif /* SRC_ENGINE_ADAPTER_MULTIIPCHECKER_MULTIIPCHECKER_H_ */
